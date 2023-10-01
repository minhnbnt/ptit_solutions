#include <iostream>
#include <sstream>
#include <string>

struct SinhVien {

	float GPA;
	unsigned id;
	std::string name, grade, birth;

	std::string get_id_str(void) const {

		std::string id = std::to_string(this->id);
		while (id.length() < 3) id = '0' + id;

		return "B20DCCN" + id;
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

			name += buf;

			if (iss.eof()) break;

			name.push_back(' ');
		}
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
			date += buf;

			if (iss.eof()) {
				break;
			}

			date.push_back('/');
		}
	}

	void input(void) {

		static unsigned id = 0;
		this->id = ++id;

		for (std::string *s : { &name, &grade, &birth }) {
			std::getline(std::cin >> std::ws, *s);
		}

		std::cin >> GPA;

		proper_name(name), proper_date(birth);
	}

	void print(void) const {

		std::cout.precision(2);

		std::cout << get_id_str() << ' ' << name << ' ' << grade;
		std::cout << ' ' << birth << ' ' << std::fixed << GPA << '\n';
	}
};

void nhap(struct SinhVien *ds, int N) {
	for (int i = 0; i < N; ++i) {
		ds[i].input();
	}
}

void in(const struct SinhVien *ds, int N) {

	for (int i = 0; i < N; ++i) {
		ds[i].print();
	}

	std::cout.flush();
}

using std::cin;

int main() {
	struct SinhVien ds[50];
	int N;
	cin >> N;
	nhap(ds, N);
	in(ds, N);
	return 0;
}
