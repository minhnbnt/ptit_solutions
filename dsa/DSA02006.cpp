#include <algorithm>
#include <iostream>
#include <vector>

class Generator {

	std::vector<int> current;
	long long current_sum = 0, target_sum;

	bool _has = false;

	void print_current(void) const {

		std::cout.put('[');

		for (size_t i = 0; i < current.size(); i++) {

			if (i == 0) {
				std::cout << current[i];
				continue;
			}

			std::cout << ' ' << current[i];
		}

		std::cout << "] ";
	}

public:

	Generator(long long sum) : target_sum(sum) {}

	bool has(void) const {
		return _has;
	}

	template <typename Iter>
	void generate(Iter begin, Iter end) {

		if (current_sum == target_sum) {
			print_current();
			_has = true;
		}

		while (begin != end) {

			const int current_num = *begin;

			current.push_back(*begin);
			current_sum += current_num;

			begin++;

			generate(begin, end);

			current.pop_back();
			current_sum -= current_num;
		}
	}
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t size;
		long long target_sum;
		std::cin >> size >> target_sum;

		std::vector<int> vec(size);
		for (int &x : vec) std::cin >> x;

		std::sort(vec.begin(), vec.end());

		Generator gen(target_sum);
		gen.generate(vec.begin(), vec.end());

		if (!gen.has()) std::cout << -1;

		std::cout << std::endl;
	}

	return 0;
}
