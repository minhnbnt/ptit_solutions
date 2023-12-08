#include <iostream>
#include <vector>

struct Student {
	std::string id, name, grade, email;
};

int main(void) {

	size_t eleS, i;
	std::cin >> eleS;

	std::vector<Student> vecS(eleS);
	for (Student &s : vecS) {
		for (std::string *buf : { &s.id, &s.name, &s.grade, &s.email }) {
			std::getline(std::cin >> std::ws, *buf);
		}
	}

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned long long year;
		std::cin >> year;

		std::cout << "DANH SACH SINH VIEN KHOA " << year << ":\n";

		for (const Student &s : vecS)
			if (year % 100 == std::stoi(s.id.substr(1, 2))) {
				std::cout << s.id << ' ' << s.name << ' ' << s.grade << ' ' << s.email << '\n';
			}

		std::cout.flush();
	}

	return 0;
}
