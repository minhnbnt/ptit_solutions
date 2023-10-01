#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using u64 = unsigned long long;

bool gen_res(const std::vector<u64> &vec) {

	size_t odd = 0, even = 0;

	for (const u64 &x : vec) {
		if (x % 2 == 1) {
			++odd;
		} else ++even;
	}

	if (vec.size() % 2 == 1) {
		return odd > even;
	}

	return odd < even;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string buf;
		std::getline(std::cin >> std::ws, buf);
		std::istringstream iss(buf);

		std::vector<u64> vec;

		while (!iss.eof()) {

			u64 x;
			iss >> x;

			vec.push_back(x);
		}

		std::cout << (gen_res(vec) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
