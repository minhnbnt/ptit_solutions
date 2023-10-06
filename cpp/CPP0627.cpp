#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

class Teacher {

	size_t id;
	std::string name, subj;

public:

	const std::string &get_name(void) const {
		return name;
	}

	void input(void) {

		static unsigned id = 0;
		this->id = ++id;

		std::string raw_subjName, buf;
		for (std::string *s : { &name, &raw_subjName }) {
			std::getline(std::cin >> std::ws, *s);
		}

		std::istringstream iss(raw_subjName);
		while (iss >> buf) {
			subj.push_back(toupper(buf[0]));
		}
	}

	void print(void) const {

		std::string id = std::to_string(this->id);
		while (id.length() < 2) id = '0' + id;

		id = "GV" + id;

		std::cout << id << ' ' << name << ' ' << subj << '\n';
	}
};

int main(void) {

	size_t num_T;
	std::cin >> num_T;

	std::vector<Teacher> vecT(num_T);
	for (Teacher &t : vecT) {
		t.input();
	}

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string match;
		std::getline(std::cin >> std::ws, match);

		const std::regex regex(".*(" + match + ").*$",
		                       std::regex_constants::icase);

		std::cout << "DANH SACH GIANG VIEN THEO TU KHOA " << match << ":\n";

		for (const Teacher &t : vecT)
			if (std::regex_match(t.get_name(), regex)) {
				t.print();
			}

		std::cout.flush();
	}

	return 0;
}
