/*
Một nhân viên làm việc trong công ty được lưu lại các thông tin sau:

Mã nhân viên: được gán tự động tăng, bắt đầu từ 00001
Họ tên: Xâu ký tự không quá 40 chữ cái.
Giới tính: Nam hoặc Nu
Ngày sinh: đúng theo chuẩn dd/mm/yyyy
Địa chỉ: Xâu ký tự không quá 100 chữ cái
Mã số thuế: Dãy số có đúng 10 chữ số
Ngày ký hợp đồng: đúng theo chuẩn dd/mm/yyyy
Viết chương trình nhập danh sách nhân viên (không nhập mã), sau đó sắp xếp theo thứ tự ngày sinh từ
già nhất đến trẻ nhất và in ra màn hình danh sách nhân viên đã sắp xếp.

Input
Dòng đầu ghi số N là số nhân viên (không quá 40). Mỗi nhân viên ghi trên 6 dòng lần lượt ghi các
thông tin theo thứ tự đã ghi trong đề bài. Không có mã nhân viên.

Output
Ghi ra danh sách đầy đủ nhân viên đã sắp xếp, mỗi nhân viên trên một dòng, các thông tin cách nhau
đúng một khoảng trống.

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

Output
00003 Hoang Thi C Nu 04/02/1981 Mo Lao-Ha Dong-Ha Noi 8333012347 22/08/2011
00001 Nguyen Van A Nam 10/22/1982 Mo Lao-Ha Dong-Ha Noi 8333012345 31/12/2013
00002 Ly Thi B Nu 10/15/1988 Mo Lao-Ha Dong-Ha Noi 8333012346 22/08/2011
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>

enum Gender { GENDER_male, GENDER_female };

struct Date {

	int day, month, year;

	Date(void) = default;

	Date(const std::string &s) {
		sscanf(s.c_str(), "%d/%d/%d", &month, &day, &year);
	}

	inline std::string to_string(void) const {

		std::ostringstream oss;

		oss << std::setw(2) << std::setfill('0') << month << '/';
		oss << std::setw(2) << std::setfill('0') << day << '/';
		oss << year;

		return oss.str();
	}
};

struct NhanVien {

	std::string name, addr;
	Date birth, reg_date;
	unsigned long long tax_code;
	Gender gen;
	size_t id;

	bool operator<(const NhanVien &nv) const {

		if (birth.year != nv.birth.year) {
			return birth.year < nv.birth.year;
		}

		if (birth.month != nv.birth.month) {
			return birth.month < nv.birth.month;
		}

		return birth.day < nv.birth.day;
	}
};

inline void nhap(NhanVien &nv) {

	static size_t id = 0;
	nv.id = ++id;

	std::getline(std::cin >> std::ws, nv.name);

	std::string gen;
	std::getline(std::cin >> std::ws, gen);

	static std::unordered_map<std::string, Gender> map_gen = {
		{ "Nam", GENDER_male }, { "Nu", GENDER_female } //
	};

	nv.gen = map_gen.at(gen);

	std::string date;
	std::getline(std::cin >> std::ws, date);

	nv.birth = Date(date);

	std::getline(std::cin >> std::ws, nv.addr);

	std::cin >> nv.tax_code;

	std::getline(std::cin >> std::ws, date);
	nv.reg_date = Date(date);
}

inline void sapxep(NhanVien *ds, int N) {
	std::sort(ds, ds + N);
}

void inds(const NhanVien *ds, int N) {

	for (int i = 0; i < N; ++i) {

		const NhanVien &nv = ds[i];

		std::cout << std::setfill('0') << std::setw(5) << nv.id;

		std::cout << ' ' << nv.name << ' ';
		std::cout << (nv.gen == GENDER_male ? "Nam " : "Nu ");

		std::cout << nv.birth.to_string() << ' ';
		std::cout << nv.addr << ' ' << nv.tax_code << ' ';
		std::cout << nv.reg_date.to_string() << '\n';
	}
}

using std::cin;

int main() {
	struct NhanVien ds[50];
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++) {
		nhap(ds[i]);
	}
	sapxep(ds, N);
	inds(ds, N);
	return 0;
}
