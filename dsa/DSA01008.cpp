#include <iostream>

void all_bits_str(size_t length, size_t number_of_trues) {

	static std::string bits;
	if (bits.length() == length) {

		for (char bit : bits) {

			if (bit != '1') {
				continue;
			}

			number_of_trues--;
		}

		if (number_of_trues == 0) {
			std::cout << bits << '\n';
		}

		return;
	}

	for (char bit : { '0', '1' }) {

		bits.push_back(bit);

		all_bits_str(length, number_of_trues);

		bits.pop_back();
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		size_t length, number_of_trues;
		std::cin >> length >> number_of_trues;

		all_bits_str(length, number_of_trues);
		std::cout.flush();
	}

	return 0;
}
