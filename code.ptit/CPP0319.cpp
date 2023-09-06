#include <iostream>
#include <string>

const std::string gen_max(unsigned digits, unsigned sum) {

	if (sum == 0 && digits > 1) {
		return "-1";
	}

	std::string result;

	while (sum > 9 && digits > 1) {
		result.push_back('9');
		sum -= 9, --digits;
	}

	if (sum > 9) return "-1";

	result.push_back(sum + '0');
	result += std::string(digits - 1, '0');

	return result;
}

const std::string gen_min(const std::string &max) {

	if (max == "0") return "0";
	if (max == "-1") return "-1";

	std::string min(max.rbegin(), max.rend());

	if (min[0] == '0') {

		for (size_t i = 1; i < min.length(); ++i)
			if (min[i] != '0') {
				--min[i];
				break;
			}

		min[0] = '1';
	}

	return min;
}

int main(void) {

	unsigned digits, sum;
	std::cin >> digits >> sum;

	const std::string max = gen_max(digits, sum);

	std::cout << gen_min(max) << ' ' << max << std::endl;

	return 0;
}
