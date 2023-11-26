#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

bool is_nice_sign(const std::string &s) {

	const std::string sign_tail = s.substr(5);
	std::vector<char> chars;

	for (char c : sign_tail) {

		if (c == '.') continue;

		chars.push_back(c);
	}

	if (std::is_sorted(chars.cbegin(), chars.cend(), std::less_equal<char>())) {
		return true;
	}

	if (chars[0] == chars[1] && chars[1] == chars[2] && chars[3] == chars[4]) {
		return true;
	}

	std::unordered_set<char> chars_set(chars.cbegin(), chars.cend());

	if (chars.size() == 1) {
		return true;
	}

	for (char c : chars_set) {
		if (strchr("68", c) == NULL) {
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

		std::string signs;
		std::cin >> std::ws >> signs;

		std::cout << (is_nice_sign(signs) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
