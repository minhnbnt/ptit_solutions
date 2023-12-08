#include <forward_list>
#include <iostream>

class Student {

	float scores[3];
	std::string id, name, grade;

	public:

	static int comparator(const Student &s1, const Student &s2) {
		return s1.name < s2.name;
	}

	void input(void) {
		for (std::string *s : { &id, &name, &grade }) {
			std::getline(std::cin >> std::ws, *s);
		}

		for (float &score : scores) {
			std::cin >> score;
		}
	}

	void print(void) const {

		static unsigned id = 0;

		std::cout << ++id << ' ' << this->id << ' ' << name;
		std::cout << ' ' << grade << std::fixed;

		for (const float &score : scores) {
			std::cout << ' ' << score;
		}

		std::cout.put(10);
	}
};

int main(void) {

	size_t ele;
	std::cin >> ele;

	std::forward_list<Student> lss(ele);
	for (Student &s : lss) {
		s.input();
	}

	lss.sort(Student::comparator);

	std::cout.precision(1);

	for (const Student &s : lss) {
		s.print();
	}
	std::cout.flush();

	return 0;
}
