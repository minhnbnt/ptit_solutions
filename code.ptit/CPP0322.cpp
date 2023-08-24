#include <algorithm>
#include <iostream>
#include <string>

std::string sum(std::string x, std::string y) {

	std::string result;

	bool carry = false;
	size_t i = x.length(), j = y.length();

	while (i > 0 || j > 0 || carry) {

		char c = carry;
		if (i > 0) --i, c += x[i] - '0';
		if (j > 0) --j, c += y[j] - '0';

		if (c < 10) carry = false;
		else carry = true, c -= 10;

		result.push_back(c + '0');
	}

	std::reverse(result.begin(), result.end());

	return result;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string x, y;
		std::cin >> std::ws >> x >> std::ws >> y;

		std::cout << sum(x, y) << std::endl;
	}
}
