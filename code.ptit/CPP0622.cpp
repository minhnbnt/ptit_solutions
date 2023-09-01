#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct student {

	std::string id, name, grade, email;

	void input(void);
};

std::unordered_map<std::string, std::vector<student *>> mp_vec;

void student::input(void) {

	for (std::string *s : { &id, &name, &grade, &email }) {
		std::getline(std::cin >> std::ws, *s);
	}

	if (mp_vec.find(grade) == mp_vec.end()) {
		mp_vec[grade] = std::vector<student *>();
	}

	mp_vec[grade].push_back(this);
}

int main(void) {

	size_t num_stu;
	std::cin >> num_stu;

	std::vector<student> vec_stu(num_stu);
	for (student &s : vec_stu) {
		s.input();
	}

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string grade;
		std::cin >> std::ws >> grade;

		std::cout << "DANH SACH SINH VIEN LOP " << grade << ":\n";
		for (const student *s : mp_vec[grade]) {

			std::cout << s->id << ' ' << s->name << ' ';
			std::cout << s->grade << ' ' << s->email << '\n';
		}

		std::cout.flush();
	}

	return 0;
}
