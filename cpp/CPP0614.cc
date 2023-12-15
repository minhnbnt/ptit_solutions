/*
Một nhân viên làm việc trong công ty được lưu lại các thông tin sau:

Mã nhân viên: được gán tự động tăng, bắt đầu từ 00001
Họ tên: Xâu ký tự không quá 40 chữ cái.
Giới tính: Nam hoặc Nu
Ngày sinh: đúng theo chuẩn dd/mm/yyyy
Địa chỉ: Xâu ký tự không quá 100 chữ cái
Mã số thuế: Dãy số có đúng 10 chữ số
Ngày ký hợp đồng: đúng theo chuẩn dd/mm/yyyy
Viết chương trình nhập danh sách nhân viên (không nhập mã) trong đó có sử dụng chồng toán tử
nhập/xuất và in ra màn hình danh sách vừa nhập.

Input
Dòng đầu ghi số N là số nhân viên (không quá 40). Mối nhân viên ghi trên 6 dòng lần lượt ghi các
thông tin theo thứ tự đã ghi trong đề bài. Không có mã nhân viên.

Output
Ghi ra danh sách đầy đủ nhân viên, mỗi nhân viên trên một dòng, các thông tin cách nhau đúng một
khoảng trống.

Ví dụ
Input:
3
Nguyen Van A
Nam
10/22/1982
Mo Lao-Ha Dong-Ha Noi
8333012345
31/12/2013
Ly Thi B
Nu
10/15/1988
Mo Lao-Ha Dong-Ha Noi
8333012346
22/08/2011
Hoang Thi C
Nu
04/02/1981
Mo Lao-Ha Dong-Ha Noi
8333012347
22/08/2011

Output:
00001 Nguyen Van A Nam 10/22/1982 Mo Lao-Ha Dong-Ha Noi 8333012345 31/12/2013
00002 Ly Thi B Nu 10/15/1988 Mo Lao-Ha Dong-Ha Noi 8333012346 22/08/2011
00003 Hoang Thi C Nu 04/02/1981 Mo Lao-Ha Dong-Ha Noi 8333012347 22/08/2011
*/

#include <iostream>
#include <sstream>

enum Gender { male, female };

class NhanVien {

	std::string name, birth, addr, reg_date;
	unsigned long long tax;
	Gender gender;
	unsigned id;

public:

	const std::string get_idstr(void) const {
		std::string result = std::to_string(this->id);
		while (result.length() < 5) result = '0' + result;

		return result;
	}

	friend std::istream &operator>>(std::istream &is, NhanVien &nv) {

		static unsigned id = 0;
		nv.id = ++id;

		std::string gender;

		for (std::string *s : { &nv.name, &gender, &nv.birth, &nv.addr }) {
			std::getline(std::cin >> std::ws, *s);
		}

		nv.gender = male;
		if (gender == "Nu") {
			nv.gender = female;
		}

		std::cin >> nv.tax >> std::ws >> nv.reg_date;

		return is;
	}

	friend std::ostream &operator<<(std::ostream &os, const NhanVien &nv) {

		os << nv.get_idstr() << ' ' << nv.name << ' ';
		os << (nv.gender == male ? "Nam" : "Nu") << ' ';

		os << nv.birth << ' ' << nv.addr << ' ';
		os << nv.tax << ' ' << nv.reg_date << '\n';

		return os;
	}
};

using std::cin, std::cout;

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	NhanVien ds[50];
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++) cin >> ds[i];
	for (i = 0; i < N; i++) cout << ds[i];
	return 0;
}
