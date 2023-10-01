/*
Khai báo lớp Khách hàng với các thuộc tính:
Mã khách hàng: tự động tăng, tính từ KH001
Tên khách hàng: xâu ký tự độ dài không quá 50
Giới tính: Nam hoặc Nu
Ngày sinh: Theo đúng chuẩn dd/mm/yyyy
Địa chỉ: xâu ký tự độ dài không quá 100

Khai báo lớp Mặt hàng với các thuộc tính:
Mã mặt hàng: tự động tăng, tính từ MH001
Tên mặt hàng: xâu ký tự độ dài không quá 100
Đơn vị tính: xâu ký tự độ dài không quá 10
Giá mua: số nguyên dương không quá 7 chữ số
Giá bán: số nguyên dương không quá 7 chữ số

Khai báo lớp Hóa đơn là bạn của lớp Khách hàng và lớp Mặt hàng trong đó có các
thông tin:
Mã hóa đơn
Mã khách hàng
Mã mặt hàng
Số lượng (không quá 1000)
Viết chương trình nhập danh sách hóa đơn và in danh sách ra màn hình.

Input:
Dòng đầu ghi số N là số khách hàng (không quá 20).
Tiếp theo là thông tin của N khách hàng, mỗi khách hàng ghi trên 4 dòng theo
đúng thứ tự đã mô tả (không có mã)
Dòng tiếp theo ghi số M là số mặt hàng (không quá 40).
Tiếp theo là thông tin của M mặt hàng, mỗi mặt hàng ghi trên 4 dòng theo đúng
thứ tự đã mô tả (không có mã)
Dòng tiếp theo ghi số K là số hóa đơn (không quá 100)
Mỗi hóa đơn ghi trên 1 dòng gồm 3 thông tin theo đúng thứ tự đã mô tả (không có
mã).

Output:
Ghi ra danh sách hóa đơn theo đúng thứ tự nhập, trong đó gồm các thông tin sau,
mỗi thông tin cách nhau đúng một khoảng trống.

Mã hóa đơn
Tên khách hàng
Địa chỉ
Tên mặt hàng
Đơn vị tính
Giá mua
Giá bán
Số lượng
Thành tiền

Ví dụ:
Input:
2
Nguyen Van Nam
Nam
12/12/1997
Mo Lao-Ha Dong-Ha Noi
Tran Van Binh
Nam
11/14/1995
Phung Khoang-Nam Tu Liem-Ha Noi
2
Ao phong tre em
Cai
25000
41000
Ao khoac nam
Cai
240000
515000
3
KH001 MH001 2
KH001 MH002 3
KH002 MH002 4

Output:
HD001 Nguyen Van Nam Mo Lao-Ha Dong-Ha Noi Ao phong tre em Cai 25000 41000 2
82000
HD002 Nguyen Van Nam Mo Lao-Ha Dong-Ha Noi Ao khoac nam Cai 240000 515000
3 1545000
HD003 Tran Van Binh Phung Khoang-Nam Tu Liem-Ha Noi Ao khoac nam Cai
240000 515000 4 2060000
*/

#include <iostream>
#include <string>
#include <unordered_map>

enum Gender { male, female };
using u64 = unsigned long long;

struct Obj {

	unsigned id;

	static const std::string get_idstr(unsigned id, const std::string head) {

		std::string result = std::to_string(id);
		while (result.length() < 3) result = '0' + result;

		return head + result;
	}
};

struct MatHang : Obj {

	u64 gia_mua, gia_ban;
	std::string ten, don_vi;

	friend std::istream &operator>>(std::istream &, MatHang &);
};

struct KhachHang : Obj {

	Gender gioi_tinh;
	std::string ten, ngay_sinh, dia_chi;

	friend std::istream &operator>>(std::istream &, KhachHang &);
};

std::unordered_map<std::string, MatHang *> dsmh;
std::unordered_map<std::string, KhachHang *> dskh;

std::istream &operator>>(std::istream &is, KhachHang &kh) {

	static unsigned maKH = 0;
	kh.id = ++maKH;

	std::string gender;

	for (std::string *s : { &kh.ten, &gender, &kh.ngay_sinh, &kh.dia_chi }) {
		std::getline(is >> std::ws, *s);
	}

	static const std::unordered_map<std::string, Gender> gend_mp = {
		{ "Nam", male }, { "Nu", female }
	};

	kh.gioi_tinh = gend_mp.at(gender);

	dskh.emplace(Obj::get_idstr(maKH, "KH"), &kh);

	return is;
}

std::istream &operator>>(std::istream &is, MatHang &mh) {

	static unsigned maMH = 0;
	mh.id = ++maMH;

	std::getline(is >> std::ws, mh.ten);
	std::getline(is >> std::ws, mh.don_vi);

	is >> mh.gia_mua >> mh.gia_ban;

	dsmh.emplace(Obj::get_idstr(maMH, "MH"), &mh);

	return is;
}

struct HoaDon : Obj {

	unsigned so_luong;
	std::string maKH, maMH;

	friend std::istream &operator>>(std::istream &is, HoaDon &hd) {

		static unsigned maHD = 0;
		hd.id = ++maHD;

		is >> std::ws >> hd.maKH >> hd.maMH >> hd.so_luong;

		return is;
	}

	friend std::ostream &operator<<(std::ostream &os, HoaDon &hd) {

		const MatHang &mh = *dsmh[hd.maMH];
		const KhachHang &kh = *dskh[hd.maKH];
		const u64 thanh_tien = hd.so_luong * mh.gia_ban;

		os << Obj::get_idstr(hd.id, "HD") << ' ';

		os << kh.ten << ' ' << kh.dia_chi << ' ';

		os << mh.ten << ' ' << mh.don_vi << ' ';
		os << mh.gia_mua << ' ' << mh.gia_ban << ' ';

		os << hd.so_luong << ' ' << thanh_tien << '\n';

		return os;
	}
};

using std::cin, std::cout;

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
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
