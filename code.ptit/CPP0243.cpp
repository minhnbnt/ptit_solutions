#include <iostream>
#include <map>
#include <vector>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele1, ele2, i;
		std::cin >> ele1 >> ele2;

		std::map<i64, size_t> mp;
		for (i = 0; i < ele1; ++i) {

			i64 x;
			std::cin >> x;

			++mp[x];
		}

		std::vector<i64> vec(ele2);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		for (const i64 &x : vec) {

			std::map<i64, size_t>::iterator it = mp.find(x);

			if (it == mp.end()) {
				continue;
			}

			size_t second = it->second;
			while (second--) {
				std::cout << it->first << ' ';
			}

			mp.erase(it);
		}

		for (const std::pair<i64, size_t> &pr : mp) {

			size_t second = pr.second;
			while (second--) {
				std::cout << pr.first << ' ';
			}
		}

		std::cout << std::endl;
	}

	return 0;
}
