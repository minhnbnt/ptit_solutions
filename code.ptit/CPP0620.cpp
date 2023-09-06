#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Student {

	std::string id, name, grade, email;
public:
	static int comparator(const Student &s1, const Student &s2) {

		if (s1.grade != s2.grade) {
			return s1.grade < s2.grade;
		}

		return s1.id < s2.id;
	}

	void input(std::istream &is) {

		for (std::string *s : { &id, &name, &grade, &email }) {
			std::getline(is >> std::ws, *s);
		}
	}

	void print(void) const {
		std::cout << id << ' ' << name << ' ';
		std::cout << grade << ' ' << email << '\n';
	}
};

int main(void) {

	size_t ele;
	std::cin >> ele;

	std::vector<Student> vecs(ele);

	for (Student &s : vecs) {
		s.input(std::cin);
	}

	std::sort(vecs.begin(), vecs.end(), Student::comparator);

	for (const Student &s : vecs) {
		s.print();
	}
	std::cout.flush();

	return 0;
}
