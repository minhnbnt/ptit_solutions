#include <algorithm>
#include <iostream>
#include <sstream>

class SinhVien {

	std::string name, grade, date;
	unsigned id;
	float GPA;

public:

	const std::string id_str(std::string head) const {

		std::string result = std::to_string(id);
		while (result.length() < 3) result = '0' + result;

		return head + result;
	}

	static bool comparator(const SinhVien &s1, const SinhVien &s2) {
		return s1.GPA > s2.GPA;
	}

	static const std::string proper_name(const std::string raw_name) {

		std::string result, buf;
		std::istringstream iss(raw_name);

		while (true) {

			iss >> buf;

			for (char &c : buf) {
				c = tolower(c);
			}
			buf[0] = toupper(buf[0]);

			result.append(buf);

			if (iss.eof()) break;

			result.push_back(' ');
		}

		return std::move(result);
	}

	static const std::string proper_date(const std::string raw_date) {

		std::string result, buf;
		std::istringstream iss(raw_date);

		while (std::getline(iss, buf, '/')) {

			while (buf.length() < 2) {
				buf = '0' + buf;
			}

			result.append(buf);

			if (iss.eof()) break;

			result.push_back('/');
		}

		return std::move(result);
	}

	friend std::istream &operator>>(std::istream &is, SinhVien &sv) {

		static unsigned id = 0;
		sv.id = ++id;

		std::string raw_name, raw_date;
		for (std::string *s : { &raw_name, &sv.grade, &raw_date }) {
			std::getline(std::cin >> std::ws, *s);
		}
		std::cin >> sv.GPA;

		sv.name = SinhVien::proper_name(raw_name);
		sv.date = SinhVien::proper_date(raw_date);

		return is;
	}

	friend std::ostream &operator<<(std::ostream &os, SinhVien &sv) {

		os.precision(2);

		os << sv.id_str("B20DCCN") << ' ' << sv.name << ' ' << sv.grade;
		os << ' ' << sv.date << ' ' << std::fixed << sv.GPA << '\n';

		return os;
	}
};

void sapxep(SinhVien *ds, int N) {
	std::sort(ds, ds + N, SinhVien::comparator);
}

using std::cin, std::cout;

int main() {
	SinhVien ds[50];
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> ds[i];
	}
	sapxep(ds, N);
	for (i = 0; i < N; i++) {
		cout << ds[i];
	}
	return 0;
}
