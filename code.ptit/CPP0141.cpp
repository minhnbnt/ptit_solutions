#include <algorithm>
#include <iostream>
#include <vector>

using u64 = unsigned long long;

bool in_fibs(u64 x) {

	static std::vector<u64> fibs{ 0, 1, 1 };

	if (x < fibs.back()) {
		return std::binary_search(fibs.begin(), fibs.end(), x);
	}

	while (x > fibs.back()) {

		const u64 &last_fib = fibs.back();
		const u64 &last2 = *std::next(fibs.rbegin());

		fibs.push_back(last_fib + last2);

		if (x < fibs.back()) {
			return false;
		}
	}

	return true;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 input;
		std::cin >> input;

		std::cout << (in_fibs(input) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
