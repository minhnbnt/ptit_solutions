/*
Một nhân viên làm việc trong công ty được lưu lại các thông tin sau:

Mã nhân viên: được gán giá trị là 00001
Họ tên: Xâu ký tự không quá 40 chữ cái.
Giới tính: Nam hoặc Nu
Ngày sinh: đúng theo chuẩn dd/mm/yyyy
Địa chỉ: Xâu ký tự không quá 100 chữ cái
Mã số thuế: Dãy số có đúng 10 chữ số
Ngày ký hợp đồng: đúng theo chuẩn dd/mm/yyyy
Viết chương trình nhập một nhân viên (không nhập mã) và in ra màn hình thông tin của nhân viên đó.

Input
Gồm 6 dòng lần lượt ghi các thông tin theo thứ tự đã ghi trong đề bài. Không có mã nhân viên.

Output
Ghi ra đầy đủ thông tin nhân viên trên một dòng, các thông tin cách nhau đúng một khoảng trống.

Ví dụ
Input
Nguyen Van Hoa
Nam
22/11/1982
Mo Lao-Ha Dong-Ha Noi
8333123456
31/12/2013

Output
00001 Nguyen Van Hoa Nam 22/11/1982 Mo Lao-Ha Dong-Ha Noi 8333123456 31/12/2013
*/

#include <iostream>
#include <string>

enum gender { male, female };

struct NhanVien {

	gender gtinh;

	std::string ten, nsinh, nkihd, dchi;

	unsigned long long msothue;
};

void nhap(struct NhanVien &a) {

	std::getline(std::cin >> std::ws, a.ten);

	a.gtinh = male;
	std::string gtinh;
	std::getline(std::cin >> std::ws, gtinh);

	if (gtinh == "Nu") {
		a.gtinh = female;
	} else if (gtinh != "Nam") {
		throw std::runtime_error("Giới tính không hợp lệ!");
	}

	std::getline(std::cin >> std::ws, a.nsinh);

	std::getline(std::cin >> std::ws, a.dchi);

	std::cin >> a.msothue;

	std::getline(std::cin >> std::ws, a.nkihd);
}

void in(const struct NhanVien &a) {

	std::cout << "00001 " << a.ten << ' ';
	std::cout << (a.gtinh == male ? "Nam " : "Nu ");

	std::cout << a.nsinh << ' ' << a.dchi << ' ' //
	          << a.msothue << ' ' << a.nkihd << '\n';
}

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	struct NhanVien a;
	nhap(a);
	in(a);
	return 0;
}
