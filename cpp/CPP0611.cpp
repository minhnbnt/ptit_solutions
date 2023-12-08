#include <iostream>
#include <sstream>
#include <string>

class SinhVien {

	size_t id;
	float GPA;
	std::string name, grade, birth;

	static std::string proper_date(const std::string &date) {

		std::string buf, propered;
		std::istringstream iss(date);

		while (std::getline(iss >> std::ws, buf, '/')) {

			if (buf.length() < 2) buf = '0' + buf;

			propered += buf;

			if (!iss.eof()) propered += '/';
		}

		return propered;
	}

	public:

	friend std::istream &operator>>(std::istream &is, SinhVien &s) {

		static size_t id = 0;
		s.id = ++id;

		for (std::string *s : { &s.name, &s.grade, &s.birth }) std::getline(is >> std::ws, *s);

		s.birth = proper_date(s.birth);

		is >> s.GPA;

		return is;
	}

	friend std::ostream &operator<<(std::ostream &os, const SinhVien &s) {

		os.precision(2);

		std::string id = std::to_string(s.id);
		while (id.length() < 3) id = '0' + id;

		id = "B20DCCN" + id;

		os << id << ' ' << s.name << ' ' << s.grade << ' ';
		os << s.birth << ' ' << std::fixed << s.GPA << '\n';

		return os;
	}
};

using std::cin, std::cout;

int main() {
	SinhVien ds[50];
	int N, i;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> ds[i];
	}
	for (i = 0; i < N; i++) {
		cout << ds[i];
	}
	return 0;
}
