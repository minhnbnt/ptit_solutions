#include <iostream>
#include <queue>

void solve(void) {

	size_t i, size;
	std::cin >> size;

	// for some reasons, this doesn't work with unsigned int :0
	std::priority_queue<int, std::vector<int>, std::greater<int>> ropes;

	for (i = 0; i < size; i++) {

		int rope_length;
		std::cin >> rope_length;

		ropes.push(rope_length);
	}

	long long total_costs = 0;

	while (ropes.size() > 1) {

		const int first_rope = ropes.top();
		ropes.pop();

		const int second_rope = ropes.top();
		ropes.pop();

		const int new_rope = first_rope + second_rope;

		total_costs += new_rope;
		ropes.push(new_rope);
	}

	std::cout << total_costs << std::endl;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) solve();

	return 0;
}
