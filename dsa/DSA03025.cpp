#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

struct Line {

	int begin, end;

	bool operator<(const Line &other) const {

		if (this->end != other.end) {
			return this->end < other.end;
		}

		return this->begin > other.begin;
	}
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t size;
		std::cin >> size;

		std::vector<Line> lines(size);
		for (auto &[begin, end] : lines) {
			std::cin >> begin >> end;
		}

		std::sort(lines.begin(), lines.end());

		size_t result = 0;
		int prev_end = std::numeric_limits<int>::min();

		for (auto [begin, end] : lines) {

			if (begin < prev_end) {
				continue;
			}

			prev_end = end;
			result++;
		}

		std::cout << result << std::endl;
	}

	return 0;
}
