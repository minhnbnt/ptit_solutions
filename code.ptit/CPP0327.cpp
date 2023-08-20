/*
Cho số tự nhiên N được biểu diễn dưới dạng nhị phân. Hãy kiểm tra xem N có phải
là số chia hết cho 5 hay không? Đưa ra “Yes” nếu N chia hết cho 5, trái lại đưa
ra “No”.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một biểu diễn nhị phân của
N. T, N thỏa mãn ràng buộc: 1≤ T ≤100; 0≤ N ≤10^000.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
1010
10000101001

Output:
Yes
Yes
*/

#include <iostream>
#include <string>

int mod_5(const std::string s) {

	size_t pos = s.length();
	int base = 1, result = 0;

	do {
		--pos;

		if (s[pos] == '1') {
			result = (result + base) % 5;
		}

		base = (base * 2) % 5;

	} while (pos != 0);

	return result;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::cin >> std::ws >> input;

		std::cout << (mod_5(input) == 0 ? "Yes" : "No") << std::endl;
	}

	return 0;
}
