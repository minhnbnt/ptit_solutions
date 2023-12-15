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
nhập/xuất, sau đó sắp xếp theo thứ tự ngày sinh từ già nhất đến trẻ nhất và in ra màn hình danh sách
đối tượng nhân viên đã sắp xếp.

Input
Dòng đầu ghi số N là số nhân viên (không quá 40). Mỗi nhân viên ghi trên 6 dòng lần lượt ghi các
thông tin theo thứ tự đã ghi trong đề bài. Không có mã nhân viên.

Output
Ghi ra danh sách đầy đủ nhân viên đã sắp xếp, mỗi nhân viên trên một dòng, các thông tin cách nhau
đúng một khoảng trống.

Ví dụ:
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
00003 Hoang Thi C Nu 04/02/1981 Mo Lao-Ha Dong-Ha Noi 8333012347 22/08/2011
00001 Nguyen Van A Nam 10/22/1982 Mo Lao-Ha Dong-Ha Noi 8333012345 31/12/2013
00002 Ly Thi B Nu 10/15/1988 Mo Lao-Ha Dong-Ha Noi 8333012346 22/08/2011
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

enum Gender { male, female };

struct Date {

	int date, month, year;

	Date() = default;
	Date(std::string raw_date) {

		std::string buf;
		std::istringstream iss(raw_date);

		int index = 0;
		int *arr[3] = { &month, &date, &year };
		while (std::getline(iss, buf, '/')) {
			*arr[index] = std::stoi(buf);
			++index;
		}
	}

	static bool comparator(const Date &d1, const Date &d2) {

		if (d1.year != d2.year) {
			return d1.year < d2.year;
		}

		if (d1.month != d2.month) {
			return d1.month < d2.month;
		}

		return d1.date < d2.date;
	}

	const std::string str(void) {

		std::ostringstream oss;

		oss << std::setw(2) << std::setfill('0') << month << '/';
		oss << std::setw(2) << std::setfill('0') << date << '/';

		oss << year;

		return oss.str();
	}
};

class NhanVien {

	Date birth, reg_date;
	std::string name, addr;

	unsigned long long tax_code;
	unsigned id;

	Gender gen;

public:

	bool operator()(const NhanVien &nv1, const NhanVien &nv2) {
		return Date::comparator(nv1.birth, nv2.birth);
	}

	friend std::istream &operator>>(std::istream &is, NhanVien &nv) {

		static unsigned id = 0;
		nv.id = ++id;

		std::string birth, gender, reg_date;
		for (std::string *s : { &nv.name, &gender, &birth, &nv.addr }) {
			std::getline(is >> std::ws, *s);
		}

		is >> nv.tax_code;

		std::getline(is >> std::ws, reg_date);

		nv.birth = Date(birth);
		nv.reg_date = Date(reg_date);

		static const std::unordered_map<std::string, Gender> gen_map = { { "Nam", male },
			                                                             { "Nu", female } };
		nv.gen = gen_map.at(gender);

		return is;
	}

	std::string id_str(void) {

		std::string result = std::to_string(this->id);
		while (result.size() < 5) result = '0' + result;

		return result;
	}

	friend std::ostream &operator<<(std::ostream &os, NhanVien &nv) {

		os << nv.id_str() << ' ' << nv.name << ' ';
		os << (nv.gen == male ? "Nam" : "Nu") << ' ';
		os << nv.birth.str() << ' ' << nv.addr << ' ';
		os << std::setw(10) << std::setfill('0') << nv.tax_code << ' ';
		os << nv.reg_date.str() << '\n';

		return os;
	}
};

void sapxep(NhanVien *ds, int N) {
	std::sort(ds, ds + N, NhanVien());
}

using std::cin, std::cout;

int main() {
	NhanVien ds[50];
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++) cin >> ds[i];
	sapxep(ds, N);
	for (i = 0; i < N; i++) cout << ds[i];
	return 0;
}
