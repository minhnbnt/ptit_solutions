/*
Cho số tự nhiên N. Nhiệm vụ của bạn là hãy đưa ra ước số nguyên tố thứ k của N.
Đưa ra -1 nếu không tồn tại ước số thứ k của N. Ví dụ N = 225, k =2 ta có kết
quả là 3 vì 225 = 3×3×5×5. Với N = 81, k = 5 ta có kết quả -1 vì 81 = 3×3×3×3.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một bộ đôi N và k.
T, N thỏa mãn ràng buộc 1≤T≤100; 1≤N, k≤104.

Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input:
2
225 2
81 5

Output:
3
-1
*/

#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

int main(void) {

	using u64 = unsigned long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		static std::vector<bool> vec(2, false);

		u64 _n, i, j;
		std::cin >> _n;

		u64 n = sqrt(_n);

		if (n >= vec.size()) {

			u64 prev_size = vec.size();
			vec.resize(n + 1, true);

			for (i = 2; i <= sqrt(n); i++) {

				if (!vec[i]) continue;

				u64 start = std::max(i, prev_size / i) * i;
				for (j = start; j <= n; j += i) {
					vec[j] = false;
				}
			}
		}

		for (i = 0; i <= n; ++i) {
			if (!vec[i]) continue;
			std::cout << i * i << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
