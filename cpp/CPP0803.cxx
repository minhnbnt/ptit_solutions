#include <fstream>
#include <iostream>
#include <map>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int num;
	std::map<int, unsigned long long> map;

	std::ifstream ifs("./DATA.in");

	while (ifs >> num) {
		++map[num];
	}

	for (const auto &[num, count] : map) {
		std::cout << num << ' ' << count << '\n';
	}
	std::cout.flush();

	return 0;
}
