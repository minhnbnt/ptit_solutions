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
