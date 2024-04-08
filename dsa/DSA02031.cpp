#include <algorithm>
#include <iostream>
#include <unordered_set>

const std::unordered_set<char> VOWELS{ 'A', 'E', 'I', 'O', 'U' };

bool is_valid(const std::string &s) {

	for (size_t i = 1; i < s.length() - 1; i++) {

		if (VOWELS.find(s[i]) == VOWELS.end()) {
			continue;
		}

		if (VOWELS.find(s[i + 1]) != VOWELS.end()) {
			continue;
		}

		if (VOWELS.find(s[i - 1]) != VOWELS.end()) {
			continue;
		}

		return false;
	}

	return true;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	const char end = std::cin.get();

	std::string target;
	for (char c = 'A'; c <= end; c++) {
		target.push_back(c);
	}

	do {

		if (!is_valid(target)) {
			continue;
		}

		std::cout << target << '\n';

	} while (std::next_permutation(target.begin(), target.end()));

	std::cout.flush();

	return 0;
}
