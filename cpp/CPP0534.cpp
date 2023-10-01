#include <iostream>
#include <map>

bool revertable(const std::string &s) {

	const size_t &len = s.length();

	for (size_t i = 0; i < len / 2; ++i) {
		if (s[i] != s[len - i - 1]) {
			return false;
		}
	}

	return true;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	auto comparator = [](const std::string &s1, const std::string &s2) {
		if (s1.length() != s2.length()) {
			return s1.length() > s2.length();
		}

		return s1 > s2;
	};

	std::map<std::string, size_t, decltype(comparator)> map(comparator);

	while (!std::cin.eof()) {

		std::string num;
		std::cin >> std::ws >> num;

		if (num.length() < 2 || !revertable(num)) {
			continue;
		}

		++map[num];
	}

	for (const auto &[num, count] : map) {
		std::cout << num << ' ' << count << '\n';
	}
	std::cout.flush();

	return 0;
}
