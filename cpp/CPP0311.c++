#include <iostream>
#include <string>
#include <unordered_map>

bool is_valid_str(const std::string &s) {

	std::unordered_map<char, size_t> counter;

	for (char c : s) ++counter[c];

	const size_t len = s.length();
	const size_t max_count = (len % 2 == 0) ? (len / 2) : (len / 2 + 1);

	for (const auto &[c, count] : counter) {
		if (count > max_count) {
			return false;
		}
	}

	return true;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		std::string input;
		std::getline(std::cin >> std::ws, input);

		std::cout << is_valid_str(input) << std::endl;
	}

	return 0;
}
