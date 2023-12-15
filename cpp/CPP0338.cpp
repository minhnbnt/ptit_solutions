/*
Cho xâu ký tự S và số k. Nhiệm vụ của bạn là đếm số xâu con của S có đúng k ký tự khác nhau. Các xâu
con không nhất thiết phải khác nhau. Ví dụ với xâu S=”abc” và k = 2, ta có kết quả là 2 bao gồm các
xâu con: “ab”, “bc”.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S và số k được viết trên một
dòng.
T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ k ≤26;1≤ Length(S)≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
abc 2
aba 2

Output:
2
3
*/

#include <cctype>
#include <iostream>
#include <string>
#include <unordered_set>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned target;
		std::string input;
		std::cin >> input >> target;

		int result = 0;

		for (size_t i = 0; i < input.length(); ++i) {

			std::unordered_set<char> char_set;

			for (size_t j = i; j < input.length(); ++j) {

				char_set.insert(tolower(input[j]));

				if (char_set.size() == target) {
					++result;
				} else if (char_set.size() > target) {
					break;
				}
			}
		}

		std::cout << result << std::endl;
	}

	return 0;
}
