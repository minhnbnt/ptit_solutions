/*
Cho số nguyên dương n. Hãy kiểm tra xem n có phải là số Fibonacci hay không?

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số nguyên dương n.

T, n thỏa mãn ràng buộc :1 ≤ T ≤ 100; 0≤n≤10^18.

Output:
Đưa ra “YES” hoặc “NO” tương ứng với n là số Fibonacci hoặc không phải số
Fibonacci của mỗi test theo từng dòng.

Input:
2
8
15

Output:
YES
NO
*/

#include <algorithm>
#include <iostream>
#include <vector>

using u64 = unsigned long long;

bool in_fibs(u64 x) {

	static std::vector<u64> fibs{ 0, 1, 1 };

	if (x < fibs.back()) {
		return std::binary_search(fibs.begin(), fibs.end(), x);
	}

	while (x > fibs.back()) {

		const u64 &last_fib = fibs.back();
		const u64 &last2 = *std::next(fibs.rbegin());

		fibs.push_back(last_fib + last2);

		if (x < fibs.back()) {
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

	while (cases--) {

		u64 input;
		std::cin >> input;

		std::cout << (in_fibs(input) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
