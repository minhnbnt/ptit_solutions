#include <deque>
#include <iostream>
#include <sstream>

std::string &proper(std::string &word) {

	for (char &c : word) {
		c = tolower(c);
	}

	word[0] = toupper(word[0]);

	return word;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		int method;
		std::cin >> method;

		if (method != 1 && method != 2) {
			std::cerr << "Invalid method." << std::endl;
			continue;
		}

		std::string buf, word;
		std::getline(std::cin >> std::ws, buf);
		std::istringstream iss(buf);

		std::deque<std::string> deq;
		while (iss >> word) {
			deq.push_back(proper(word));
		}

		if (method == 1) {
			word = deq.back(), deq.pop_back();
			deq.push_front(word);
		} else {
			word = deq.front(), deq.pop_front();
			deq.push_back(word);
		}

		for (const std::string &name : deq) {
			std::cout << name << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
