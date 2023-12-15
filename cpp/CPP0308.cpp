/*
Cho xâu ký tự S. Nhiệm vụ của bạn là in ra tất cả các ký tự không lặp khác nhau trong S. Ví dụ S
=”ABCDEABC” ta nhận được kết quả là “DE”.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S được viết trên một dòng.
T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ Length(S)≤10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng. In ra theo thứ tự chữ cái xuất hiện trong xâu ban đầu.

Input:
2
ABCDEAABC
ABC

Output:
DE
ABC
*/

#include <iostream>
#include <string>
#include <unordered_map>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::getline(std::cin >> std::ws, input);

		std::unordered_map<char, size_t> map;
		for (const char &c : input) {
			++map[c];
		}

		for (const char &c : input) {
			if (map.at(c) == 1) {
				std::cout.put(c);
			}
		}
		std::cout << std::endl;
	}

	return 0;
}
