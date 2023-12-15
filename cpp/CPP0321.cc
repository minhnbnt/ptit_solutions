/*
Cho hai số rất lớn X và Y được biểu diễn như hai xâu ký tự. Nhiệm vụ của bạn là tìm |X-Y|?

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi test gồm hai dòng: dòng thứ nhất đưa xâu X; dòng tiếp
theo đưa vào xâu Y.
T, X, Y  thỏa mãn ràng buộc : 1≤T≤100; 0≤length(X), length(Y)≤10^3.

Output:
Đưa ra số kết quả mỗi test theo từng dòng.

Ví dụ:

Input:
2
978
12977
100
1000000

Output:
11999
0999900
*/

#include <iostream>
#include <string>

int comparator(const std::string &s1, const std::string &s2) {

	if (s1.length() != s2.length()) {
		return s1.length() > s2.length() ? 1 : -1;
	}

	return s1.compare(s2);
}

const std::string minus(std::string s1, std::string s2) {

	bool carry = false;
	std::string result("");
	while (!s1.empty() || !s2.empty()) {
		int x = 0;
		if (!s1.empty()) {
			x += s1.back() - '0';
			s1.pop_back();
		}
		if (!s2.empty()) {
			x -= s2.back() - '0';
			s2.pop_back();
		}
		if (carry) --x;

		if (x < 0) {
			x += 10;
			carry = true;
		} else carry = false;

		result = char(x + '0') + result;
	}

	return result;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string s1, s2;
		std::cin >> std::ws >> s1 >> std::ws >> s2;

		int cmp = comparator(s1, s2);
		if (cmp == 0) {
			std::cout << 0 << std::endl;
			continue;
		}
		if (cmp < 0) {
			std::swap(s1, s2);
		}
		std::cout << minus(s1, s2) << std::endl;
	}

	return 0;
}
