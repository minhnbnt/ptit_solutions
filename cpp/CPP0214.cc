#include <deque>
#include <iostream>
#include <vector>

class Solution {
public:
	static std::vector<int> maxSlidingWindow(const std::vector<int> &vec, size_t length) {

		std::vector<int> result;
		std::deque<size_t> deq;

		for (size_t i = 0; i < vec.size(); ++i) {

			while (!deq.empty() && vec[deq.back()] <= vec[i]) {
				deq.pop_back();
			}

			deq.push_back(i);

			if (deq.front() == i - length) {
				deq.pop_front();
			}

			if (i >= length - 1) {
				result.push_back(vec[deq.front()]);
			}
		}

		return result;
	}
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, length;
		std::cin >> ele >> length;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		for (int x : Solution::maxSlidingWindow(vec, length)) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
