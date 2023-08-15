#include <iostream>

using u64 = unsigned long long;

namespace solution {
bool check(u64 num) {

	unsigned short prev = num % 10;

	while (num >= 10) {

		num /= 10;

		unsigned short curr = num % 10;
		if (abs(curr - prev) != 1) {
			return false;
		}
		prev = curr;
	}

	return true;
}
}; // namespace solution

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 num;
		std::cin >> num;

		std::cout << (solution::check(num) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
