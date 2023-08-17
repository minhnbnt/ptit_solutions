/*
Dãy số Fibonacci được định nghĩa Fn = Fn-1 + Fn-2, n>1 và F0 = 0, F1 = 1.
Dưới đây là một số số Fibonacci : 0, 1, 1, 2, 3, 5, 8, 13, 21…

Nhiệm vụ của bạn là tìm số Fibonacci thứ n.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số nguyên dương n.
T, n thỏa mãn ràng buộc :1 ≤ T ≤ 100; 1≤n≤1000.

Output:
Đưa ra kết quả mỗi test theo modulo 109 + 7 theo từng dòng.

Input:
2
2
5

Output:
1
5
*/

#include <iostream>
#include <vector>

using u64 = unsigned long long;

u64 get_mod_fib(unsigned n) {

	static const u64 mod = 1e9 + 7;
	static std::vector<u64> fibs = { 0, 1 };

	if (n > fibs.size()) {
		fibs.resize(n + 1, 0);
	}

	if (fibs[n] == 0 && n > 1) {
		fibs[n] = (get_mod_fib(n - 1) + get_mod_fib(n - 2)) % mod;
	}

	return fibs[n];
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned n;
		std::cin >> n;

		std::cout << get_mod_fib(n) << std::endl;
	}

	return 0;
}
