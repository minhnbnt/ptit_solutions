/*
Tính toán giá trị đa thức P(n, x) = a[n-1]x^(n-1) + a[n-2]x(n-2) +..+ a[0].

Kết quả có thể rất lớn nên hãy chia dư cho 109 + 7

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi test gồm hai dòng: dòng thứ nhất đưa
vào hai số n, x; dòng tiếp theo đưa vào n số an-1, an-2, .., a0 là hệ số của đa
thức P. Các số được viết cách nhau một vài khoảng trống.

T, n, x, P[i]  thỏa mãn ràng buộc : 1≤T≤100; 0≤n≤2000; 0≤ x, P[i] ≤1000.

Chú ý: Các hệ số của đa thức P được viết theo thứ tự từ bậc 0 đến bậc n-1

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
4 2
1 2 0 4

Output:
20
*/

#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

const i64 mod = 1e9 + 7;

i64 bin_pow(i64 base, size_t exp) {

	i64 result = 1;

	while (exp > 0) {
		if (exp % 2 == 1) {
			result = (result * base) % mod;
		}

		exp /= 2;
		base = (base * base) % mod;
	}

	return result;
}

i64 gen_result(int x, std::vector<int> a) {

	std::reverse(a.begin(), a.end());

	i64 result = 0;

	for (size_t i = 0; i < a.size(); ++i) {

		int &base = a[i];

		i64 x_exp = bin_pow(x, i);

		result += (x_exp * base) % mod;
		result %= mod;
	}

	return result;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		int x;
		size_t n;
		std::cin >> n >> x;

		std::vector<int> vec(n);
		for (int &e : vec) {
			std::cin >> e;
		}

		std::cout << gen_result(x, vec) << std::endl;
	}

	return 0;
}
