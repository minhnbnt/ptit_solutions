#include <iostream>
#include <sstream>
#include <stack>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input, tmp;
		std::getline(std::cin >> std::ws, input);
		std::istringstream iss(input);

		std::stack<std::string> stk;
		while (iss >> tmp) {
			stk.push(tmp);
		}

		while (true) {

			const std::string &top = stk.top();

			std::cout.write(top.c_str(), top.length());
			stk.pop();

			if (stk.empty()) {
				break;
			}

			std::cout.put(' ');
		}
		std::cout << std::endl;
	}

	return 0;
}
