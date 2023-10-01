#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const std::string sum(std::string a, std::string b) {

	std::string result;
	bool carry = false;

	while (!a.empty() || !b.empty() || carry) {

		unsigned short x = 0;

		if (!a.empty()) {
			x += a.back() - '0';
			a.pop_back();
		}

		if (!b.empty()) {
			x += b.back() - '0';
			b.pop_back();
		}

		if (carry) ++x;

		carry = x > 9;

		result.push_back(x % 10 + '0');
	}

	std::reverse(result.begin(), result.end());

	return result;
}

const std::string product_int(std::string a, const unsigned short &b) {

	std::string result;
	unsigned carry = 0;

	while (!a.empty() || carry > 0) {

		unsigned x = b;
		if (a.empty()) x = 0;
		else {
			x *= a.back() - '0';
			a.pop_back();
		}

		x += carry, carry = x / 10;

		result.push_back(x % 10 + '0');
	}

	std::reverse(result.begin(), result.end());

	return result;
}

const std::string product(const std::string &a, std::string b) {

	size_t pow_10 = 0;
	std::string result = "0";

	while (!b.empty()) {

		std::string x = product_int(a, b.back() - '0');
		result = sum(x + std::string(pow_10, '0'), result);

		b.pop_back(), ++pow_10;
	}

	return result;
}

std::string catalan(unsigned n) {

	std::vector<std::string> vec(n + 1, "0");
	vec[0] = vec[1] = "1";

	for (unsigned i = 2; i <= n; ++i) {
		for (unsigned j = 0; j < i; ++j) {
			vec[i] = sum(vec[i], product(vec[j], vec[i - j - 1]));
		}
	}

	return vec[n];
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned n;
	std::cin >> n;

	std::cout << catalan(n + 1) << std::endl;

	return 0;
}
