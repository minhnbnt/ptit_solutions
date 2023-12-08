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
