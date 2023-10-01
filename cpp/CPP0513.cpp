#include <iostream>
#include <sstream>
#include <string>

struct SinhVien {

	float gpa;
	unsigned id;
	std::string name, grade, birth;

	std::string get_id(void) const {

		std::string id = std::to_string(this->id);
		while (id.length() < 3) id = '0' + id;

		return "B20DCCN" + id;
	}

	void input(const unsigned id) {

		this->id = id;

		std::string raw_date;
		for (std::string *s : { &name, &grade, &raw_date }) {
			std::getline(std::cin >> std::ws, *s);
		}

		std::istringstream iss(raw_date);
		while (true) {

			std::string buf;
			std::getline(iss, buf, '/');

			while (buf.length() < 2) {
				buf = '0' + buf;
			}
			birth += buf;

			if (iss.eof()) break;

			birth += '/';
		}

		std::cin >> gpa;
	}

	void print(void) const {

		std::cout.precision(2);

		std::cout << get_id() << ' ' << name << ' ' << grade << ' ';
		std::cout << birth << ' ' << std::fixed << gpa << '\n';
	}
};

void nhap(struct SinhVien *ds, int N) {
	for (int i = 0; i < N; ++i) {
		ds[i].input(i + 1);
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
