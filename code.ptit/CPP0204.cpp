/*
Cho một câu hỏi Q là bộ đôi hai số L và R. Nhiệm vụ của bạn là xác định xem có
bao nhiêu số nguyên tố trong khoảng [L, R]. Ví dụ với Q = [1, 10] ta có câu trả
lời là 4 vì có {2, 3, 5, 7} là các số nguyên tố.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một bộ đôi L, R. các số
được viết cách nhau một vài khoảng trống.

T, L, R thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ L≤ R ≤10^5;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
1 10
5 10

Output:
4
2
*/

#include <complex>
#include <iostream>
#include <vector>

using u64 = unsigned long long;

std::vector<bool> vec(2, false);

void sieve(u64 n) {

	const u64 &size = vec.size();

	if (n < size) return;

	vec.resize(n + 1, true);

	u64 i, j;
	for (i = 2; i <= sqrt(n); ++i) {

		if (!vec[i]) continue;

		const u64 start = std::max(i, size / i) * i;

		for (j = start; j <= n; j += i) {
			vec[j] = false;
		}
	}
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 left, right, i;
		std::cin >> left >> right;
		if (left > right) {
			std::swap(left, right);
		}

		sieve(right);

		u64 count = 0;
		for (i = left; i <= right; ++i) {
			if (vec[i]) ++count;
		}
		std::cout << count << std::endl;
	}

	return 0;
}
