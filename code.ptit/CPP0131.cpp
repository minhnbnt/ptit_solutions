/*
Cho số tự nhiên N. Nhiệm vụ của bạn là hãy đưa ra ước số nguyên tố nhỏ nhất của
các số từ 1 đến N.

Ví dụ n=10, ta có được kết quả : 1 2 3 2 5 2 7 2 3 2.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N.
T, N thỏa mãn ràng buộc 1≤T≤100; 1≤N ≤109.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5
10

Output:
1 2 3 2 5
1 2 3 2 5 2 7 2 3 2
*/

#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

auto main(void) -> int {

	using u64 = unsigned long long;

	unsigned cases;
	std::cin >> cases;
	while (cases--) {

		u64 x, i, j;
		std::cin >> x;

		static std::vector<u64> vec = { 0, 1 };

		if (x >= vec.size()) {

			u64 prev_size = vec.size();
			vec.resize(x + 1, 0);

			for (i = 2; i <= sqrt(x); ++i) {

				if (vec[i] != 0) continue;

				u64 start = std::max(i, prev_size / i) * i;
				for (j = start; j <= x; j += i) {
					if (vec[j] == 0) vec[j] = i;
				}
			}
		}

		for (i = 1; i <= x; ++i) {
			u64 tmp = vec[i] == 0 ? i : vec[i];
			std::cout << tmp << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
