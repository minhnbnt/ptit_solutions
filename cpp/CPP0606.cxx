/*
Một nhân viên làm việc trong công ty được lưu lại các thông tin sau:

Mã nhân viên: được gán giá trị là 00001
Họ tên: Xâu ký tự không quá 40 chữ cái.
Giới tính: Nam hoặc Nu
Ngày sinh: đúng theo chuẩn mm/dd/yyyy
Địa chỉ: Xâu ký tự không quá 100 chữ cái
Mã số thuế: Dãy số có đúng 10 chữ số
Ngày ký hợp đồng: đúng theo chuẩn dd/mm/yyyy

Viết chương trình nhập một nhân viên (không nhập mã) trong đó có sử dụng chồng toán tử nhập/xuất và
in ra màn hình thông tin của nhân viên đó.

Input
Gồm 6 dòng lần lượt ghi các thông tin theo thứ tự đã ghi trong đề bài. Không có mã nhân viên.

Output
Ghi ra đầy đủ thông tin nhân viên trên một dòng, các thông tin cách nhau đúng một khoảng trống.

Ví dụ
Nguyen Van Hoa
Nam
11/22/1982
Mo Lao-Ha Dong-Ha Noi
8333123456
31/12/2013

Input
Output
00001 Nguyen Van Hoa Nam 11/22/1982 Mo Lao-Ha Dong-Ha Noi 8333123456 31/12/2013
*/

#include <iostream>
#include <string>

class NhanVien {

	std::string ho_ten, gioi_tinh, dia_chi;
	std::string ngay_sinh, ngay_ki_hd;
	std::string ma_so_thue;
	unsigned ma_NV;

public:

	std::string maNV_str(void) {

		std::string str = std::to_string(ma_NV);
		while (str.length() < 5) str = '0' + str;

		return str;
	}

	friend void operator>>(std::istream &is, NhanVien &nv) {

		static bool is_input = true;

		if (!is_input) {

			std::cout << nv.maNV_str() << ' ' << nv.ho_ten << ' ' << nv.gioi_tinh;
			std::cout << ' ' << nv.ngay_sinh << ' ' << nv.dia_chi << ' ';
			std::cout << nv.ma_so_thue << ' ' << nv.ngay_ki_hd << '\n';

			return;
		}

		static unsigned ma = 0;
		nv.ma_NV = ++ma;

		std::getline(is, nv.ho_ten);
		is >> nv.gioi_tinh >> nv.ngay_sinh;
		std::getline(is >> std::ws, nv.dia_chi);
		is >> nv.ma_so_thue >> nv.ngay_ki_hd;

		is_input = false;
	}
};

using std::cin;

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	NhanVien a;
	cin >> a;
	cin >> a;
	return 0;
}
