/*
Cho hai số L, R. Nhiệm vụ của bạn là hãy đếm tất cả các số có đúng ba ước số
trong khoảng [L, R]. Ví dụ L =1, R =10, ta có kết quả là 2 vì chỉ có số 3 và 9
là có đúng 3 ước số.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là cặp số L, R.
T, N thỏa mãn rang buộc 1≤T≤100; 1≤L, R ≤1012.

Output:

Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
1 10
1 1000000000000
2

Output:
78498
*/

#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

int main(void) {

	using u64 = unsigned long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 _n, _m, i, j;
		std::cin >> _n >> _m;

		u64 n = sqrt(_n), m = sqrt(_m);
		if (n * n <= _n) ++n;

		static std::vector<bool> vec(2, false);
		if (m >= vec.size()) {

			u64 prev_size = vec.size();
			vec.resize(m + 1, true);

			for (i = 2; i <= sqrt(m); ++i) {

				if (!vec[i]) continue;

				u64 start = std::max(i, prev_size / i) * i;
				for (j = i * i; j <= m; j += i) {
					vec[j] = false;
				}
			}
		}

		u64 count = 0;
		for (i = n; i <= m; ++i) {
			if (vec[i]) ++count;
		}
		std::cout << count << std::endl;
	}

	return 0;
}
