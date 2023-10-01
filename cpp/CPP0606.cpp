/*
Một nhân viên làm việc trong công ty được lưu lại các thông tin sau:

Mã nhân viên: được gán giá trị là 00001
Họ tên: Xâu ký tự không quá 40 chữ cái.
Giới tính: Nam hoặc Nu
Ngày sinh: đúng theo chuẩn dd/mm/yyyy
Địa chỉ: Xâu ký tự không quá 100 chữ cái
Mã số thuế: Dãy số có đúng 10 chữ số
Ngày ký hợp đồng: đúng theo chuẩn dd/mm/yyyy

Viết chương trình nhập một nhân viên (không nhập mã) trong đó có sử dụng chồng
toán tử nhập/xuất và in ra màn hình thông tin của nhân viên đó.

Input
Gồm 6 dòng lần lượt ghi các thông tin theo thứ tự đã ghi trong đề bài. Không có
mã nhân viên.

Output
Ghi ra đầy đủ thông tin nhân viên trên một dòng, các thông tin cách nhau đúng
một khoảng trống.

Ví dụ:
Input:
Nguyen Van Hoa
Nam
11/22/1982
Mo Lao-Ha Dong-Ha Noi
8333123456
31/12/2013

Output:
00001 Nguyen Van Hoa Nam 11/22/1982 Mo Lao-Ha Dong-Ha Noi 8333123456 31/12/2013
*/

#include <iostream>

using namespace std;

class NhanVien {

	unsigned maNV;
	unsigned long long masoThue;
	string hoTen, gtinh, diaChi;
	string ngaySinh, ngayKiHD;
public:
	string maNV_str(void) {
		string str = to_string(maNV);
		while (str.length() < 5) str = '0' + str;
		return str;
	}

	friend istream &operator>>(istream &is, NhanVien &nv) {

		static unsigned id = 0;
		nv.maNV = ++id;

		getline(is >> ws, nv.hoTen);

		is >> ws >> nv.gtinh >> ws >> nv.ngaySinh;

		getline(is >> ws, nv.diaChi);
		is >> nv.masoThue >> ws >> nv.ngayKiHD;

		return is;
	}

	friend ostream &operator<<(ostream &os, NhanVien &nv) {

		os << nv.maNV_str() << ' ' << nv.hoTen << ' ' << nv.gtinh << ' '
		   << nv.ngaySinh << ' ' << ' ' << nv.diaChi << ' ' << nv.masoThue
		   << ' ' << nv.ngayKiHD << '\n';

		return os;
	}
};

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	NhanVien a;
	cin >> a;
	cout << a;
	return 0;
}
