/*
Cho xâu ký tự S bao gồm các ký tự ‘a’,..,’z’ và các chữ số. Nhiệm vụ của bạn là hãy tìm số lớn nhất
có mặt trong xâu.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S.
T, S thỏa mãn ràng buộc: 1≤ T ≤100; 0≤ Length(S) ≤105.
Input đảm bảo đáp số không vượt quá 10^9.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input:

Output:

3
100klh564abc365bg
abvhd9sdnkjdfs
abchsd0sdhs

564
9
0
*/

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::getline(std::cin >> std::ws, input);
		for (char &c : input) {
			if (!isdigit(c)) {
				c = ' ';
			}
		}

		long long x, max = 0;
		std::istringstream iss(input);
		while (iss >> x) {
			max = std::max(max, x);
		}

		std::cout << max << std::endl;
	}

	return 0;
}
