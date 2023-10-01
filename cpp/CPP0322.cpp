/*
Cho hai số rất lớn X và Y được biểu diễn như hai xâu ký tự. Nhiệm vụ của bạn là
tìm X+Y?

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi test gồm hai dòng: dòng thứ nhất đưa
xâu X; dòng tiếp theo đưa vào xâu Y.
T, X, Y  thỏa mãn ràng buộc : 1≤T≤100; 0≤length(X), length(Y)≤10^3.

Output:
Đưa ra số kết quả mỗi test theo từng dòng.

Ví dụ:
Input:
1
12
198111

Output:
198123
*/

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

	return 0;
}
