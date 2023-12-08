/*
Cho số nguyên dương N>2. Hãy đưa ra cặp số nguyên tố p, q đầu tiên tìm được có
tổng đúng bằng N. Ví dụ N = 6 ta có cặp số nguyên tố đầu tiên là 3 + 3 =6.

Trong trường hợp không tìm thấy đáp án thì không in ra gì cả.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số chẵn N.
T, N thỏa mãn ràng buộc : 1≤T≤100; 4≤N≤10000.

Output:
Đưa ra kết quả mỗi test theo từng dòng. Nếu không có cặp số nào thỏa mãn thì
không in ra gì cả.

Input:
2
74
1024

Output:
3 71
3 1021
*/

#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

namespace solution {

template <typename T>
bool is_prime(T n) {

	static std::vector<bool> vec(2, false);

	if (n >= vec.size()) {

		T prev_size = vec.size();
		vec.resize(n + 1, true);

		T i, j;
		for (i = 0; i <= sqrt(n); ++i) {

			if (!vec[i]) continue;

			T start = std::max(i, prev_size / i) * i;

			for (j = start; j <= n; j += i) {
				vec[j] = false;
			}
		}
	}

	return vec[n];
}

template <typename T>
std::pair<T, T> calculate(T target) {

	for (T i = 2; i <= target / 2; ++i) {

		if (!is_prime<T>(i)) continue;

		T j = target - i;

		if (is_prime(j)) return { i, j };
	}

	return { 0, 0 };
}

} // namespace solution

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		using u64 = unsigned long long;

		u64 n;
		std::cin >> n;

		std::pair<u64, u64> result = solution::calculate<u64>(n);

		if (result != std::pair<u64, u64>({ 0, 0 })) {
			std::cout << result.first << ' ' << result.second;
		}
		std::cout << std::endl;
	}

	return 0;
}
