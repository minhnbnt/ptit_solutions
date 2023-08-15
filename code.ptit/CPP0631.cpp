#include <iostream>
#include <string>
#include <unordered_map>

#define enable_prompt false

using u64 = unsigned long long;

enum gender { male, female };

struct KhachHang {
	unsigned id;
	gender gioi_tinh;
	std::string ten, ngay_sinh, dia_chi;

	std::string id_str(void) {
		std::string str = std::to_string(id);
		while (str.length() < 3) str = '0' + str;
		return "KH" + str;
	}
};

struct MatHang {
	unsigned id;
	u64 gia_mua, gia_ban;
	std::string ten, don_vi;

	std::string id_str(void) {
		std::string str = std::to_string(id);
		while (str.length() < 3) str = '0' + str;
		return "MH" + str;
	}
};

struct HoaDon {
	unsigned so_luong, id;
	std::string maKH, maMH;

	std::string id_str(void) {
		std::string str = std::to_string(id);
		while (str.length() < 3) str = '0' + str;
		return "HD" + str;
	}
};

namespace my_iostream {

std::unordered_map<std::string, MatHang *> dsmh;
std::unordered_map<std::string, KhachHang *> dskh;

struct istream {

	void operator>>(int &n) {
		std::cin >> n;
	}

	void operator>>(KhachHang &kh) {

		static unsigned maKH = 0;
		kh.id = ++maKH;
		if (enable_prompt) std::cout << "Nhap ho ten: ";
		std::getline(std::cin >> std::ws, kh.ten);

		static std::unordered_map<std::string, gender> gend_mp = {
			{ "Nam", male }, { "Nu", female }
		};

		std::string gender;
		if (enable_prompt) std::cout << "Nhap gioi tinh (Nam/Nu): ";
		std::getline(std::cin >> std::ws, gender);
		kh.gioi_tinh = gend_mp[gender];

		if (enable_prompt) std::cout << "Nhap ngay sinh: ";
		std::getline(std::cin >> std::ws, kh.ngay_sinh);

		if (enable_prompt) std::cout << "Nhap dia chi: ";
		std::getline(std::cin >> std::ws, kh.dia_chi);

		dskh.insert({ kh.id_str(), &kh });
	}

	void operator>>(MatHang &mh) {

		static unsigned maMH = 0;
		mh.id = ++maMH;

		if (enable_prompt) std::cout << "Nhap ten mat hang: ";
		std::getline(std::cin >> std::ws, mh.ten);

		if (enable_prompt) std::cout << "Nhap don vi: ";
		std::getline(std::cin >> std::ws, mh.don_vi);

		if (enable_prompt) std::cout << "Nhap gia mua va gia ban: ";
		std::cin >> mh.gia_mua >> mh.gia_ban;

		dsmh.insert({ mh.id_str(), &mh });
	}

	void operator>>(HoaDon &hd) {

		static unsigned maHD = 0;
		hd.id = ++maHD;

		if (enable_prompt) std::cout << "Nhap ma KH, ma MH, so luong: ";
		std::cin >> hd.maKH >> hd.maMH >> hd.so_luong;
	}
};

class ostream {
public:
	void operator<<(HoaDon hd) {

		KhachHang kh = *dskh[hd.maKH];
		MatHang mh = *dsmh[hd.maMH];
		u64 thanh_tien = hd.so_luong * mh.gia_ban;

		std::cout << hd.id_str() << ' ' << kh.ten << ' ' << kh.dia_chi << ' ';
		std::cout << mh.ten << ' ' << mh.don_vi << ' ' << mh.gia_mua << ' '
		          << mh.gia_ban << ' ';
		std::cout << hd.so_luong << ' ' << thanh_tien << '\n';
	};
};
} // namespace my_iostream

my_iostream::istream cin;
my_iostream::ostream cout;

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
