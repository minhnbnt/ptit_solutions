/*
Cho hai số rất lớn X và Y được biểu diễn như hai xâu ký tự. Nhiệm vụ của bạn là
tìm X × Y?

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi test gồm hai dòng: dòng thứ nhất đưa
xâu X; dòng tiếp theo đưa vào xâu Y.
T, X, Y  thỏa mãn ràng buộc : 1≤T≤1000 ≤length(X), length(Y)≤10^3.

Output:
Đưa ra số kết quả mỗi test theo từng dòng.

Input:
1
2 3

Output:
6
*/

#include <algorithm>
#include <iostream>
#include <string>

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

const std::string product_int(std::string a, const unsigned short b) {

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

		const std::string x = product_int(a, b.back() - '0');
		result = sum(x + std::string(pow_10, '0'), result);

		b.pop_back(), ++pow_10;
	}

	return result;
}

auto main(void) -> int {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string a, b;
		std::cin >> std::ws >> a >> std::ws >> b;

		std::cout << product(a, b) << std::endl;
	}

	return 0;
}
