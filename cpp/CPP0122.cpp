/*
Cho số tự nhiên n.
Nhiệm vụ của bạn là tìm số nguyên nhỏ nhất chia hết cho 1, 2, .., n.

Input:
Dòng đầu tiên đưa vào T là số lượng bộ test.
T dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một số tự nhiên n.
T thỏa mãn ràng buộc: 1≤T≤10^4;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input
2
3
5

Output:
6
60
*/

#include <algorithm>
#include <iostream>
#include <vector>

using u64 = unsigned long long;

u64 lcm(u64 a, u64 b) {
	return a * b / std::__gcd(a, b);
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		static std::vector<u64> vec;

		unsigned n, i;
		std::cin >> n;

		size_t prev_size = vec.size();
		if (n >= prev_size) {

			vec.resize(n + 1, 1);

			for (i = prev_size; i <= n; ++i) {

				if (i == 0) continue;

				vec[i] = vec[i - 1];

				if (vec[i] % i != 0) vec[i] = lcm(vec[i], i);
			}
		}

		std::cout << vec[n] << std::endl;
	}

	return 0;
}
