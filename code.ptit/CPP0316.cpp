#include <iostream>
#include <string>

using u64 = unsigned long long;

u64 sum_of_digits(const std::string &s) {

	u64 result = 0;
	for (const char &c : s) {
		result += c - '0';
	}
	return result;
}

bool is_lucky_number(std::string num) {

	if (num == "9") return true;
	if (num.length() == 1) return false;

	u64 sum = sum_of_digits(num);
	return is_lucky_number(std::to_string(sum));
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string num;
		std::cin >> std::ws >> num;

		std::cout << is_lucky_number(num) << std::endl;
	}

	return 0;
}
