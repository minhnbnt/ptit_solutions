#include <iostream>
#include <string>

void print_all_bits(size_t len) {

	static std::string bits;

	if (bits.length() == len) {
		std::cout << bits << ' ';
		return;
	}

	for (char c : { '0', '1' }) {

		bits.push_back(c);

		print_all_bits(len);

		bits.pop_back();
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t length;
		std::cin >> length;

		print_all_bits(length);
		std::cout << std::endl;
	}

	return 0;
}
