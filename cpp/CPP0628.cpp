#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Corp {

	unsigned candidates;
	std::string id, name;

	public:

	void input(void) {

		std::cin >> std::ws >> id;
		std::getline(std::cin >> std::ws, name);

		std::cin >> candidates;
	}

	void print(void) const {
		std::cout << id << ' ' << name << ' ' << candidates << '\n';
	}

	bool operator()(const Corp &c1, const Corp &c2) {

		if (c1.candidates != c2.candidates) {
			return c1.candidates > c2.candidates;
		}

		return c1.id < c2.id;
	}
};

class Solution {
	public:
	static void main(void) {

		size_t num_corp;
		std::cin >> num_corp;

		std::vector<Corp> vec_corp(num_corp);
		for (Corp &c : vec_corp) {
			c.input();
		}

		std::sort(vec_corp.begin(), vec_corp.end(), Corp());

		for (const Corp &c : vec_corp) {
			c.print();
		}
		std::cout.flush();
	}
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	Solution::main();

	return 0;
}
