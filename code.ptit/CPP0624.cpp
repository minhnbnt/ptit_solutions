#include <cctype>
#include <iostream>
#include <unordered_map>
#include <vector>

class Student {

	std::string id, name, grade, email;
public:
	void print(void) const {
		std::cout << id << ' ' << name << ' ';
		std::cout << grade << ' ' << email << '\n';
	}

	void input(void);
};

std::unordered_map<std::string, std::vector<Student *>> map;

void Student::input(void) {

	for (std::string *s : { &id, &name, &grade, &email }) {
		std::getline(std::cin >> std::ws, *s);
	}

	const std::string group = id.substr(3, 4);

	if (grade[0] == 'E' && (group == "DCCN" || group == "DCAT")) {
		return;
	}

	if (map.find(group) == map.end()) {
		map[group] = std::vector<Student *>();
	}

	map[group].push_back(this);
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	size_t num_stu;
	std::cin >> num_stu;

	std::vector<Student> vec(num_stu);
	for (Student &s : vec) {
		s.input();
	}

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string group;
		std::getline(std::cin >> std::ws, group);

		for (char &c : group) {
			c = toupper(c);
		}

		static const std::unordered_map<std::string, std::string> id_map = {
			{ "CONG NGHE THONG TIN", "DCCN" },
			{ "AN TOAN THONG TIN", "DCAT" },
			{ "VIEN THONG", "DCVT" },
			{ "KE TOAN", "DCKT" },
			{ "DIEN TU", "DCDT" }
		};

		std::cout << "DANH SACH SINH VIEN NGANH " << group << ":\n";

		for (const Student *p : map[id_map.at(group)]) {
			p->print();
		}
		std::cout.flush();
	}

	return 0;
}
