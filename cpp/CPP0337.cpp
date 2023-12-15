/*
Cho xâu ký tự S. Nhiệm vụ của bạn là hãy tìm độ dài xâu con nhỏ nhất của S chứa đầy đủ các ký tự của
S mỗi ký tự ít nhất một lần. Ví dụ với xâu S=”aabcbcdbca” ta có xâu con nhỏ nhất là “dbca”.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S được viết trên một dòng.
T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ Length(S)≤10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
aabcbcdbca
aaab

Output:
4
2
*/

#include <iostream>
#include <limits>
#include <unordered_set>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string str;
		std::getline(std::cin >> std::ws, str);

		size_t i, j, min_length = std::numeric_limits<size_t>::max();
		size_t num_chars = std::unordered_set<char>(str.begin(), str.end()).size();
		for (i = 0; i < str.size(); ++i) {

			std::unordered_set<char> char_set;

			for (j = i; j < str.size(); ++j) {

				if (char_set.size() == num_chars) {
					break;
				}

				char_set.insert(str[j]);
			}

			if (char_set.size() != num_chars) {
				break;
			}

			min_length = std::min(min_length, j - i);
		}

		std::cout << min_length << std::endl;
	}

	return 0;
}
