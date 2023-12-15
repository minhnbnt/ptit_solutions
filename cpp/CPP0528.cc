#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Student {

	static std::unordered_map<std::string, std::vector<Student *>> map;

	unsigned pos;
	std::string id, name, grade, email, corp;

public:

	static std::vector<Student *> &get(const std::string &corp) {
		return map[corp];
	}

	static bool comaprator(const Student *s1, const Student *s2) {
		return s1->name < s2->name;
	}

	void print(void) const {
		std::cout << pos << ' ' << id << ' ' << name << ' ';
		std::cout << grade << ' ' << email << ' ' << corp << '\n';
	}

	void input(void) {

		static unsigned id = 0;
		this->pos = ++id;

		for (std::string *s : { &this->id, &this->name, &this->grade, &this->email, &this->corp }) {
			std::getline(std::cin >> std::ws, *s);
		}

		if (map.find(this->corp) == map.end()) {
			map[this->corp] = std::vector<Student *>();
		}

		map[this->corp].push_back(this);
	}
};

std::unordered_map<std::string, std::vector<Student *>> Student::map;

int main(void) {

	unsigned size;
	std::cin >> size;

	std::vector<Student> vec(size);
	for (Student &s : vec) {
		s.input();
	}

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string corp;
		std::cin >> std::ws >> corp;

		std::vector<Student *> &vec = Student::get(corp);
		std::sort(vec.begin(), vec.end(), Student::comaprator);

		for (Student *s : vec) {
			s->print();
		}

		std::cout.flush();
	}

	return 0;
}
