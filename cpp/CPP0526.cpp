#include <algorithm>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>

struct person {
	std::string first_name;
	int date, month, year;
};

int cmp(const person &a, const person &b) {
	if (a.year != b.year) return a.year < b.year;
	if (a.month != b.month) return a.month < b.month;
	return a.date < b.date;
}

int main(void) {

	unsigned ele;
	std::cin >> ele;

	std::deque<person> deq(ele);
	for (person &p : deq) {

		std::string buf;
		std::getline(std::cin >> std::ws, buf);
		std::istringstream iss(buf);

		iss >> std::ws >> p.first_name;
		int *arr[] = { &p.date, &p.month, &p.year };

		for (int *p : arr) {
			std::string tmp;
			std::getline(iss >> std::ws, tmp, '/');
			*p = std::stoi(tmp);
		}
	}

	std::sort(deq.begin(), deq.end(), cmp);

	std::cout << deq.back().first_name << '\n';
	std::cout << deq.front().first_name << std::endl;

	return 0;
}
