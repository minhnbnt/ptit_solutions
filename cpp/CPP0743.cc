/*
Cho xâu ký tự S. Nhiệm vụ của bạn là đảo ngược các từ trong S. Ví dụ S =  “I like this program very
much”, ta nhận được kết quả là “much very program this like I”.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S.
T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ Length(S)≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
I like this program very much
much very program this like I

Output:
much very program this like I
I like this program very much
*/

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input, tmp;
		std::getline(std::cin >> std::ws, input);
		std::istringstream iss(input);

		std::stack<std::string> stk;
		while (iss >> tmp) {
			stk.push(tmp);
		}

		while (true) {

			const std::string &top = stk.top();

			std::cout.write(top.c_str(), top.length());
			stk.pop();

			if (stk.empty()) {
				break;
			}

			std::cout.put(' ');
		}
		std::cout << std::endl;
	}

	return 0;
}
