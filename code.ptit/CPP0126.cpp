#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

using u64 = unsigned long long;

int main(void) {

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
