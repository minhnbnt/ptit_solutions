#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	auto cases = unsigned();
	std::cin >> cases;

	while (cases--) {

		auto length = size_t();
		std::cin >> length;

		auto vec = std::vector<std::string>{ "6", "8" };

		for (auto i = size_t(0); vec[i].length() < length; i++) {
			vec.push_back(vec[i] + "6");
			vec.push_back(vec[i] + "8");
		}

		std::cout << vec.size() << '\n';

		std::reverse(vec.begin(), vec.end());
		for (auto &num : vec) {
			std::cout << num << ' ';
		}

		std::cout << std::endl;
	}

	return 0;
}
