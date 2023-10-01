#include <iostream>
#include <string>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::cin >> std::ws >> input;

		int result = 0;

		for (int i = 0; i < input.length() - 2; ++i) {

			if (input.size() < 3) break;

			else if (input[i] == '1' && input[i + 1] == '0' &&
			         input[i + 2] == '0') {
				input.erase(i, 3);
				result += 3;
				i = -1;
			}
		}

		std::cout << result << std::endl;
	}

	return 0;
}
