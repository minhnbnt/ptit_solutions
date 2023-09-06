#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	std::unordered_map<std::string, size_t> map;

	while (cases--) {

		std::string buf, head;
		std::getline(std::cin >> std::ws, buf);

		std::istringstream iss(buf);

		while (iss >> buf) {

			for (char &c : buf) {
				c = tolower(c);
			}

			if (iss.eof()) {
				head = buf + head;
				break;
			}

			head.push_back(buf[0]);
		}

		if (map.find(head) != map.end()) {

			++map[head];
			head.push_back('0' + map[head]);

		} else map.emplace(head, 1);

		std::cout << head << "@ptit.edu.vn" << std::endl;
	}

	return 0;
}
