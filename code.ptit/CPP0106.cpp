#include <iostream>
#include <string>

bool revertable(std::string num) {

	for (unsigned i = 0; i < num.length() / 2; i++)
		if (num[i] != num[num.length() - i - 1]) {
			return false;
		}

	return true;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string num;
		std::cin >> std::ws >> num;

		std::cout << (revertable(num) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
