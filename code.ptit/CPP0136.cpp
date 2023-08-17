/*
Cho số tự nhiên N. Nhiệm vụ của bạn là hãy đếm tất cả các số có đúng ba ước số.
Ví dụ n=100, ta có các số 4.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N.
T, N thỏa mãn rang buộc 1≤T≤100; 1≤N ≤1012.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
50
200

Output:
4
6
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

		unsigned count = 0;
		for (i = 1; i <= n; ++i) {
			if (vec[i]) ++count;
		}
		std::cout << count << std::endl;
	}

	return 0;
}
