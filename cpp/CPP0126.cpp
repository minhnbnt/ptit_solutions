/*
Hãy sinh ra tất cả các số nguyên tố trong khoảng [M, N]. Ví dụ M=1, N=10 ta có
kết quả 2 3 5 7.

Input:
Dòng đầu tiên đưa vào số lượng test T.

Những dòng kế tiếp mỗi dòng đưa vào một bộ test. Mỗi bộ test là bộ đôi M, N được
viết cách nhau một vài khoảng trống. T, M, N thỏa mãn ràng buộc: 1≤T≤100;
1≤M≤N≤10000; N-M≤10000.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
1 10
3 5

Output:
2 3 5 7
3 5
*/

#include <complex>
#include <iostream>
#include <vector>

using u64 = unsigned long long;

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		static std::vector<bool> vec(2, false);

		u64 start, end, i, j;
		std::cin >> start >> end;

		if (end >= vec.size()) {

			size_t prev_size = vec.size();
			vec.resize(end + 1, true);

			for (i = 2; i <= sqrt(end); ++i) {

				if (!vec[i]) continue;

				u64 _start = std::max(i * i, (prev_size / i) * i);
				for (j = _start; j <= end; j += i) {
					vec[j] = false;
				}
			}
		}

		for (i = start; i <= end; ++i)
			if (vec[i]) std::cout << i << " ";
		std::cout << std::endl;
	}

	return 0;
}
