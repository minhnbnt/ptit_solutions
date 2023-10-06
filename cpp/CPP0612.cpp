#include <iostream>
#include <sstream>

class SinhVien {

	std::string name, grade, birth;
	unsigned id;
	float GPA;

public:

	const std::string get_id(void) const {

		std::string id = std::to_string(this->id);
		while (id.length() < 3) id = '0' + id;

		return "B20DCCN" + id;
	}

	static void proper_date(std::string &date) {

		std::istringstream iss(date);
		date.clear();

		while (true) {

			std::string buf;
			std::getline(iss, buf, '/');

			while (buf.length() < 2) {
				buf = '0' + buf;
			}

			date.append(buf);

			if (iss.eof()) {
				return;
			}

			date.push_back('/');
		}
	}

	static void proper_name(std::string &name) {

		std::istringstream iss(name);
		name.clear();

		while (true) {

			std::string buf;
			iss >> buf;

			for (char &c : buf) {
				c = tolower(c);
			}
			buf[0] = toupper(buf[0]);

			name.append(buf);

			if (iss.eof()) {
				break;
			}

			name.push_back(' ');
		}
	}

	friend std::istream &operator>>(std::istream &is, SinhVien &sv) {

		static unsigned id = 0;
		sv.id = ++id;

		for (std::string *s : { &sv.name, &sv.grade, &sv.birth }) {
			std::getline(is >> std::ws, *s);
		}

		proper_date(sv.birth), proper_name(sv.name);

		is >> sv.GPA;

		return is;
	}

	friend std::ostream &operator<<(std::ostream &os, const SinhVien &sv) {

		os.precision(2);

		os << sv.get_id() << ' ' << sv.name << ' ' << sv.grade << ' ';
		os << sv.birth << ' ' << std::fixed << sv.GPA << '\n';

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
