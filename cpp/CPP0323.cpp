/*
Cho số nguyên dương N rất lớn được biểu diễn như một xâu và số M. Hãy tìm K = N%M. Ví dụ
N=123456789873123456778976, M = 100 thì K=76.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp mỗi dòng đưa vào các test. Mỗi test là bộ đôi N, M được viết trên hai dòng khác
nhau.
T, N, M thỏa mãn ràng buộc : 1≤T≤100; 0≤length(N) ≤1000; 2≤M ≤1012.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
12345
10

Output:
5
*/

#include <algorithm>
#include <iostream>

using u64 = unsigned long long;

u64 module(std::string s, u64 mod) {

	std::reverse(s.begin(), s.end());

	u64 result = 0, base = 1;

	for (const char &c : s) {

		const unsigned short digit = c - '0';

		result += (base * digit) % mod;
		result %= mod;

		base = (base * 10) % mod;
	}

	return result;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 mod;
		std::string num;
		std::cin >> std::ws >> num >> mod;

		std::cout << module(num, mod) << std::endl;
	}

	return 0;
}
