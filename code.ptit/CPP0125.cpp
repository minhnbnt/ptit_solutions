#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

using u64 = unsigned long long;

int main(void) {

	u64 start, end, i, j;
	std::cin >> start >> end;

	if (start > end) std::swap(start, end);

	std::vector<bool> isPrime(end + 1, true);
	isPrime[0] = isPrime[1] = false;

	for (i = 2; i < sqrt(end); ++i) {

		if (!isPrime[i]) continue;

		for (j = i * i; j <= end; j += i) {
			isPrime[j] = false;
		}
	}

	for (i = start; i <= end; ++i) {
		if (!isPrime[i]) continue;
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}
