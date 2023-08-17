/*
Cho số nguyên dương N. Hãy đưa ra tất cả các số nguyên tố nhỏ hơn hoặc bằng N.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là  một số nguyên dương N được
ghi trên một dòng. T, N thỏa mãn ràng buộc: 1≤T≤100; 2≤N≤104.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
10
35

Output:
2 3 5 7
2 3 5 7 11 13 17 19 23 29 31
*/

#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		static std::vector<bool> vec(2, false);

		unsigned n, i, j;
		std::cin >> n;

		if (n >= vec.size()) {

			unsigned prev_size = vec.size();
			vec.resize(n + 1, true);

			for (i = 2; i <= sqrt(n); i++) {

				if (!vec[i]) continue;

				unsigned long start = std::max(i, prev_size / i) * i;
				for (j = start; j <= n; j += i) {
					vec[j] = false;
				}
			}
		}

		for (i = 0; i <= n; i++) {
			if (!vec[i]) continue;
			std::cout << i << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
