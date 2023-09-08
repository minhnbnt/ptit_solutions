/*
Một xâu ký tự được gọi là Pangram nếu nó chứa đầy đủ các ký tự từ ‘a’, ..’z’.
Cho xâu ký tự S và số K. Hãy xác định xem có thể thực hiện nhiều nhất K phép
biến đổi các ký tự để S trở thành Pangram hay không? Mỗi phép biến đổi là một
phép thay thế ký tự này bằng một ký tự khác.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào xâu ký tự S; dòng tiếp theo đưa vào số K.
T, S, K thỏa mãn ràng buộc: 1≤ T ≤100; 0≤ K ≤62; 1≤ Length(S) ≤10^6.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
qwqqwqeqqwdsdadsdasadsfsdsdsdasasas
4
qwqqwqeqqwdsdadsdasadsfsdsdsdasasas
24

Output:
0
1
*/

#include <iostream>
#include <string>
#include <unordered_set>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string buf;
		std::getline(std::cin >> std::ws, buf);

		unsigned k;
		std::cin >> k;

		if (buf.length() < 26) {
			std::cout << 0 << std::endl;
			continue;
		}

		std::unordered_set<char> char_set;
		for (const char &c : buf) {
			char_set.insert(c);
		}

		if (26 - char_set.size() > k) {
			std::cout << 0 << std::endl;
		} else std::cout << 1 << std::endl;
	}

	return 0;
}
