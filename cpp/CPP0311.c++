/*
Cho xâu ký tự S bao gồm các ký tự ‘a’,..,’z’. Các ký tự trong S có thể lặp lại. Nhiệm vụ của bạn sắp
đặt lại các ký tự trong S sao cho các ký tự kề nhau đều khác nhau.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S.
T, S thỏa mãn ràng buộc: 1≤ T ≤100; 0≤ Length(S) ≤10^3.

Output:
Đưa ra 1 hoặc 0 nếu có thể hoặc không thể sắp đặt lại các ký tự trong xâu S thỏa mãn yêu cầu bài
toán.

Input:
3
geeksforgeeks
bbbabaaacd
bbbbb

Output:
1
1
0
*/

#include <iostream>
#include <string>
#include <unordered_map>

bool is_valid_str(const std::string &s) {

	std::unordered_map<char, size_t> counter;

	for (char c : s) ++counter[c];

	const size_t len = s.length();
	const size_t max_count = (len % 2 == 0) ? (len / 2) : (len / 2 + 1);

	for (const auto &[c, count] : counter) {
		if (count > max_count) {
			return false;
		}
	}

	return true;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		std::string input;
		std::getline(std::cin >> std::ws, input);

		std::cout << is_valid_str(input) << std::endl;
	}

	return 0;
}
