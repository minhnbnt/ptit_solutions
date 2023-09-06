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
