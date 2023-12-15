/*
Cho hai hàm h(x) và g(x) xác định trên tập các số tự nhiên A[] gồm n phần tử. Trong đó, h(x) là tích
của các số trong mảng A[], g(x) là ước số chung lớn nhất của các số trong mảng A[]. Nhiệm vụ của bạn
là tìm giá trị h(x)g(x). Chú ý, khi lời giải cho kết quả lớn hãy đưa ra giá trị modulo với 10^9+7.

Input:
Dòng đầu tiên đưa vào T là số lượng bộ test.
T dòng tiếp đưa các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào số n là số các phần tử
của mảng A[]; dòng tiếp theo đưa vào n số tự nhiên phân biệt nhau bởi một vài khoảng trống.
Các số T, N, A[i] thỏa mãn ràng buộc: 1≤T≤26; 1≤n≤60; 1≤A[i]≤10^4;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
2
2 4

Output:
64
*/

#include <algorithm>
#include <iostream>
#include <vector>

using u64 = unsigned long long;
static const long mod = 1e9 + 7;

unsigned get_gcd(const std::vector<unsigned> &vec) {

	unsigned result = vec[0];
	for (size_t i = 1; i < vec.size(); ++i) {
		result = std::__gcd(result, vec[i]);
	}

	return result;
}

u64 get_product(const std::vector<unsigned> &vec) {

	u64 result = 1;
	for (const unsigned &x : vec) {
		result *= x;
		result %= mod;
	}

	return result;
}

u64 bin_pow(u64 base, unsigned exp) {

	u64 result = 1;

	while (exp > 0) {

		if (exp % 2 == 1) {
			result *= base;
			result %= mod;
		}

		base = (base * base) % mod;
		exp /= 2;
	}

	return result;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele;
		std::cin >> ele;

		std::vector<unsigned> vec(ele);
		for (unsigned &x : vec) {
			std::cin >> x;
		}

		const unsigned gcd = get_gcd(vec);
		const u64 base = get_product(vec);

		std::cout << bin_pow(base, gcd) << std::endl;
	}

	return 0;
}
