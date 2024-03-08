// https://www.quora.com/How-can-the-SPOJ-problem-LIS2-be-solved
// https://www.spoj.com/problems/LIS2/

#include <iostream>
#include <map>
#include <vector>

class DPElement {

	std::map<int, int> map;

public:

	DPElement(void) = default;
	DPElement(const std::pair<int, int> &pair) : map{ pair } {}

	bool can_insert_pair(const std::pair<int, int> &pair) const {

		auto it = map.lower_bound(pair.first);

		if (it == map.begin()) {
			return false;
		}

		it--;
		return it->second < pair.second;
	}

	void insert(const std::pair<int, int> &pair) {

		auto it = map.lower_bound(pair.first), start = it;
		while (it != map.end() && it->second >= pair.second) {
			it++;
		}

		map.erase(start, it);
		map.insert(pair);
	}
};

class Solver {

	std::vector<DPElement> dp;

	size_t get_index(const std::pair<int, int> &pair) {

		size_t left = 0, right = dp.size() - 1;

		while (left < right) {

			const size_t middle = (left + right + 1) / 2;
			if (dp[middle].can_insert_pair(pair)) {
				left = middle;
			} else {
				right = middle - 1;
			}
		}

		return left + 1;
	}

	void insert(const std::pair<int, int> &pair) {

		const size_t insert_index = this->get_index(pair);

		if (insert_index >= dp.size()) {
			dp.emplace_back(pair);
		}

		dp[insert_index].insert(pair);
	}

public:

	Solver(const std::vector<std::pair<int, int>> &elements) {

		dp.resize(2);
		dp[1].insert(elements[0]);

		for (size_t i = 1; i < elements.size(); i++) {
			this->insert(elements[i]);
		}
	}

	size_t get_result(void) const {
		return dp.size() - 1;
	}
};

int main(void) {

	size_t size;
	std::cin >> size;

	std::vector<std::pair<int, int>> vec(size);
	for (std::pair<int, int> &element : vec) {
		std::cin >> element.first >> element.second;
	}

	const Solver s(vec);

	std::cout << s.get_result() << std::endl;

	return 0;
}
