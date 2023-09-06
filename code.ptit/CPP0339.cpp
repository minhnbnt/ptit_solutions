#include <iostream>
#include <string>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::getline(std::cin >> std::ws, input);

		int i, j;
		const size_t &len = input.length();
		unsigned long long count = 0;

		for (i = 0; i < len; ++i)
			for (j = len - 1; j >= i; --j)
				if (input[i] == input[j]) {
					++count;
				}

		std::cout << count << std::endl;
	}

	return 0;
}
