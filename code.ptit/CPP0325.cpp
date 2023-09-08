/*
Cho số tự nhiên N, hãy kiểm tra xem N có phải là số chia hết cho 11 hay không?
Đưa ra 1 nếu N chia hết cho 11, trái lại đưa ra 0.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một số tự nhiên N.
T, N thỏa mãn ràng buộc: 1≤ T ≤100; 0≤ N ≤101000.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
76945
363588395960667043875487

Output:
1
0
*/

#include <algorithm>
#include <iostream>
#include <string>

int mod_11(std::string s) {

	std::reverse(s.begin(), s.end());

	int result = 0, base = 1;
	for (const char &c : s) {

		int x = (c - '0') * base;

		result = (result + x) % 11;

		base = (base * 10) % 11;
	}

	return result;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string num;
		std::cin >> std::ws >> num;

		std::cout << (mod_11(num) == 0) << std::endl;
	}

	return 0;
}
