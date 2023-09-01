#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

struct Candidate {

	size_t id;

	std::string stu_id, name, grade;
	std::string email, corp;

	void print(void) {

		std::cout << id << ' ' << this->stu_id << ' ' << this->name << ' ';

		std::cout << this->grade << ' ' << this->email << ' ' << this->corp
		          << '\n';
	}
};

int comparator(const Candidate *a, const Candidate *b) {
	return a->stu_id < b->stu_id;
}

std::unordered_map<std::string, std::list<Candidate *>> mp;

void input(Candidate &c) {

	static unsigned id = 0;
	c.id = ++id;

	for (std::string *buf :
	     { &c.stu_id, &c.name, &c.grade, &c.email, &c.corp }) {
		std::getline(std::cin >> std::ws, *buf);
	}

	if (mp.find(c.corp) == mp.end()) {
		mp[c.corp] = std::list<Candidate *>();
	}

	mp[c.corp].push_back(&c);
}

int main(void) {

	size_t num_candidate;
	std::cin >> num_candidate;

	std::vector<Candidate> vec(num_candidate);
	for (Candidate &c : vec) {
		input(c);
	}

	size_t num_corp, i;
	std::cin >> num_corp;

	for (i = 0; i < num_corp; ++i) {

		std::string corp;
		std::cin >> std::ws >> corp;

		mp[corp].sort(comparator);
		for (Candidate *c : mp[corp]) {
			c->print();
		}

		std::cout.flush();
	}

	return 0;
}
