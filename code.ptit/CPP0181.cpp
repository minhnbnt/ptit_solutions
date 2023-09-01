#include <algorithm>
#include <iostream>
#include <string>

int main(void) {

	using u64 = unsigned long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 x, y, i;
		std::string a;
		std::cin >> std::ws >> a >> x >> y;

		for (i = 0; i < std::__gcd(x, y); ++i) {
			std::cout << a;
		}
		std::cout << std::endl;
	}

	return 0;
}
