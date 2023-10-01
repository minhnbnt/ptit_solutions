/*
Cho xâu ký tự S. Hãy đếm tất cả các xâu con của S có ký tự đầu và ký tự cuối
giống nhau. Ví dụ với xâu “aba” ta có 4 xâu con bao gồm: “a”, “b”, “a”, “aba”.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S được viết
trên một dòng.
T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ k ≤26;1≤ Length(S)≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
abcab
aba

Output:
7
4
*/

#include <iostream>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::getline(std::cin >> std::ws, input);

		int i, j;
		const size_t &len = input.length();
		unsigned long long count = 0;

		for (i = 0; i < len; ++i)
			for (j = len - 1; j >= i; --j)
				if (input[i] == input[j]) {
					++count;
				}

		std::cout << count << std::endl;
	}

	return 0;
}
