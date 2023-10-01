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

		static const std::unordered_map<std::string, Gender> gen_map = {
			{ "Nam", male }, { "Nu", female }
		};
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
