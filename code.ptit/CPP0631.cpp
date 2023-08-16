#include <iostream>
#include <string>
#include <unordered_map>

enum gender { male, female };
using u64 = unsigned long long;

struct MatHang {

	unsigned id;
	u64 gia_mua, gia_ban;
	std::string ten, don_vi;

	std::string id_str(void) {
		std::string str = std::to_string(id);
		while (str.length() < 3) str = '0' + str;
		return "MH" + str;
	}

	friend std::istream &operator>>(std::istream &is, MatHang &mh);
};

struct KhachHang {

	unsigned id;
	gender gioi_tinh;
	std::string ten, ngay_sinh, dia_chi;

	std::string id_str(void) {
		std::string str = std::to_string(id);
		while (str.length() < 3) str = '0' + str;

		return "KH" + str;
	}

	friend std::istream &operator>>(std::istream &is, KhachHang &kh);
};

std::unordered_map<std::string, MatHang *> dsmh;
std::unordered_map<std::string, KhachHang *> dskh;

std::istream &operator>>(std::istream &is, KhachHang &kh) {

	static unsigned maKH = 0;
	kh.id = ++maKH;
	std::getline(is >> std::ws, kh.ten);

	static std::unordered_map<std::string, gender> gend_mp = {
		{ "Nam", male }, { "Nu", female }
	};

	std::string gender;
	std::getline(is >> std::ws, gender);
	kh.gioi_tinh = gend_mp[gender];

	std::getline(is >> std::ws, kh.ngay_sinh);

	std::getline(is >> std::ws, kh.dia_chi);

	dskh.insert({ kh.id_str(), &kh });

	return is;
}

std::istream &operator>>(std::istream &is, MatHang &mh) {

	static unsigned maMH = 0;
	mh.id = ++maMH;

	std::getline(is >> std::ws, mh.ten);

	std::getline(is >> std::ws, mh.don_vi);

	is >> mh.gia_mua >> mh.gia_ban;

	dsmh.insert({ mh.id_str(), &mh });

	return is;
}

struct HoaDon {

	unsigned so_luong, id;
	std::string maKH, maMH;

	std::string id_str(void) {

		std::string str = std::to_string(id);
		while (str.length() < 3) str = '0' + str;
		return "HD" + str;
	}

	friend std::istream &operator>>(std::istream &is, HoaDon &hd) {

		static unsigned maHD = 0;
		hd.id = ++maHD;

		is >> std::ws >> hd.maKH >> hd.maMH >> hd.so_luong;

		return is;
	}

	friend std::ostream &operator<<(std::ostream &os, HoaDon &hd) {

		KhachHang &kh = *dskh[hd.maKH];
		MatHang &mh = *dsmh[hd.maMH];
		u64 thanh_tien = hd.so_luong * mh.gia_ban;

		os << hd.id_str() << ' ' << kh.ten << ' ' << kh.dia_chi << ' ';
		os << mh.ten << ' ' << mh.don_vi << ' ' << mh.gia_mua << ' '
		   << mh.gia_ban << ' ';
		os << hd.so_luong << ' ' << thanh_tien << '\n';

		return os;
	}
};

using std::cin;
using std::cout;

int main() {
	KhachHang dskh[25];
	MatHang dsmh[45];
	HoaDon dshd[105];
	int N, M, K, i;
	cin >> N;
	for (i = 0; i < N; i++) cin >> dskh[i];
	cin >> M;
	for (i = 0; i < M; i++) cin >> dsmh[i];
	cin >> K;
	for (i = 0; i < K; i++) cin >> dshd[i];

	for (i = 0; i < K; i++) cout << dshd[i];
	return 0;
}
