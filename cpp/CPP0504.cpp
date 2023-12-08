#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

struct SinhVien {
	std::string name, grade, birth;
	float GPA;
};

void nhap(SinhVien &s) {

	std::getline(std::cin >> std::ws, s.name);
	std::getline(std::cin >> std::ws, s.grade);

	std::string date, tmp;
	std::getline(std::cin >> std::ws, date);

	std::istringstream iss(date);
	while (true) {

		std::getline(iss >> std::ws, tmp, '/');
		s.birth += tmp.size() < 2 ? '0' + tmp : tmp;

		if (iss.eof()) break;
		s.birth += '/';
	}

	std::cin >> s.GPA;
}

void in(const SinhVien &s) {
	std::cout << "B20DCCN001 " << s.name << ' ' << s.grade //
			  << ' ' << s.birth << ' ' << ' ';

	std::cout.precision(2);
	std::cout << std::fixed << s.GPA << std::endl;
}

int main() {
	struct SinhVien a;
	nhap(a);
	in(a);
	return 0;
}
