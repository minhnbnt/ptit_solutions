#include <iostream>
#include <limits>
#include <vector>

int main(void) {

	using u64 = unsigned long long;

	u64 num_lights;
	std::cin >> num_lights;
	std::vector<bool> light(num_lights, true);

	u64 continuous, broken;
	std::cin >> continuous >> broken;

	while (broken--) {

		u64 pos;
		std::cin >> pos;

		light[pos - 1] = false;
	}

	std::vector<u64> vec;
	for (const bool not_broken : light) {

		static u64 sum = 0;

		if (!not_broken) {
			++sum;
		}

		vec.push_back(sum);
	}

	u64 result = std::numeric_limits<u64>::max();
	for (u64 i = continuous; i < num_lights; ++i)
		result = std::min(result, vec[i] - vec[i - continuous]);

	std::cout << result << std::endl;

	return 0;
}
