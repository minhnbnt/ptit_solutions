/*
Một nhân viên làm việc trong công ty được lưu lại các thông tin sau:

Mã nhân viên: được gán tự động tăng, bắt đầu từ 00001
Họ tên: Xâu ký tự không quá 40 chữ cái.
Giới tính: Nam hoặc Nu
Ngày sinh: đúng theo chuẩn dd/mm/yyyy
Địa chỉ: Xâu ký tự không quá 100 chữ cái
Mã số thuế: Dãy số có đúng 10 chữ số
Ngày ký hợp đồng: đúng theo chuẩn dd/mm/yyyy
Viết chương trình nhập danh sách nhân viên (không nhập mã) và in ra màn hình danh sách nhân viên vừa
nhập.

Input
Dòng đầu ghi số N là số nhân viên (không quá 40). Mỗi nhân viên ghi trên 6 dòng lần lượt ghi các
thông tin theo thứ tự đã ghi trong đề bài. Không có mã nhân viên.

Output
Ghi ra danh sách đầy đủ nhân viên theo đúng thứ tự nhập, mỗi nhân viên trên một dòng, các thông tin
cách nhau đúng một khoảng trống.

Ví dụ
Input
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

#include <iomanip>
#include <iostream>
#include <string>

enum Gender { male, female };

struct NhanVien {
	size_t id;
	Gender gender;
	std::string name, birth, addr, reg_date;
	unsigned long long tax_id;
};

void nhap(NhanVien &nv) {

	static size_t id = 0;
	nv.id = ++id;

	std::string gender;
	for (std::string *s : { &nv.name, &gender, &nv.birth, &nv.addr }) {
		std::getline(std::cin >> std::ws, *s);
	}

	nv.gender = gender == "Nam" ? male : female;

	std::cin >> nv.tax_id;

	std::getline(std::cin >> std::ws, nv.reg_date);
}

void inds(NhanVien *ds, size_t size) {

	for (size_t i = 0; i < size; ++i) {
		std::cout << std::setw(5) << std::setfill('0') << ds[i].id << ' ';

		std::cout << ds[i].name << (ds[i].gender == male ? " Nam " : " Nu ");
		std::cout << ds[i].birth << ' ' << ds[i].addr << ' ';

		std::cout << std::setw(10) << ds[i].tax_id << ' ';

		std::cout << std::setw(0) << ds[i].reg_date << '\n';
	}

	std::cout.flush();
}

using std::cin;

// Bài tập này yêu cầu sử dụng hàm main cho sẵn như sau:
int main() {
	struct NhanVien ds[50];
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++) nhap(ds[i]);
	inds(ds, N);
	return 0;
}
