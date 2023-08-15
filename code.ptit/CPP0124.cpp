#include <complex>
#include <iostream>
#include <map>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::map<int, unsigned> mp;

	unsigned long long n;
	std::cin >> n;

	for (unsigned long i = 2; i <= sqrt(n); ++i) {

		unsigned count = 0;

		while (n % i == 0) {
			n /= i;
			++count;
		}

		if (count > 0) mp.insert({ i, count });
	}

	if (n > 1) mp.insert({ n, 1 });

	for (const std::pair<int, unsigned> &pr : mp)
		std::cout << pr.first << " " << pr.second << "\n";
	std::cout << std::flush;

	return 0;
}
