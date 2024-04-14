#include <bitset>
#include <iostream>

int main(void) {

	using u64 = unsigned long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string s1, s2;
		std::cin >> s1 >> s2;

		const std::bitset<32> bit1(s1), bit2(s2);

		std::cout << bit1.to_ullong() * bit2.to_ulong() << std::endl;
	}

	return 0;
}
