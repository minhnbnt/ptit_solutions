#include <iostream>
#include <sstream>
#include <string>

struct SinhVien {
	std::string name, id, birth;
	float GPA;
};

void nhapThongTinSV(SinhVien &a) {

	std::string raw_date, buf;

	for (std::string *s : { &a.name, &a.id, &raw_date }) {
		std::getline(std::cin >> std::ws, *s);
	}
	std::cin >> a.GPA;

	std::istringstream iss(raw_date);
	while (std::getline(iss, buf, '/')) {

		while (buf.length() < 2) buf = '0' + buf;

		a.birth += buf;

		if (iss.eof()) return;

		a.birth.push_back('/');
	}
}

void inThongTinSV(const SinhVien &a) {

	std::cout.precision(2);

	std::cout << "N20DCCN001 " << a.name << ' ' << a.id << ' ';
	std::cout << a.birth << ' ' << std::fixed << a.GPA << '\n';
}

int main() {
	struct SinhVien a;
	nhapThongTinSV(a);
	inThongTinSV(a);
	return 0;
}
