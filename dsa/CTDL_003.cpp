#include <iostream>
#include <limits>
#include <tuple>
#include <vector>

class Solver {

	struct Item {

		int value, weight;

		Item(int value, int weight) : value(value), weight(weight) {}
	};

	int capacity;
	std::vector<Item> items;

	int best_values_recorded;
	std::vector<bool> solution;

	int current_value, capacity_required;
	std::vector<bool> current;

	void solve(size_t index) {

		if (index == items.size()) {

			if (capacity_required > capacity) {
				return;
			}

			if (current_value > best_values_recorded) {
				best_values_recorded = current_value;
				solution = current;
			}

			return;
		}

		for (bool take : { true, false }) {

			current.push_back(take);

			if (take) {
				current_value += items[index].value;
				capacity_required += items[index].weight;
			}

			this->solve(index + 1);

			current.pop_back();

			if (take) {
				current_value -= items[index].value;
				capacity_required -= items[index].weight;
			}
		}
	}

public:

	Solver(const std::vector<int> &values, const std::vector<int> &weights,
	       int capacity)

	    : capacity(capacity), current_value(), capacity_required(),
	      best_values_recorded(std::numeric_limits<int>::min()) {

		for (size_t i = 0; i < values.size(); i++) {
			items.emplace_back(values[i], weights[i]);
		}
	}

	std::tuple<int, std::vector<bool>> get_result() {

		this->solve(0);

		return std::make_tuple(best_values_recorded, solution);
	}
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);

	size_t size;
	int capacity;
	std::cin >> size >> capacity;

	std::vector<int> values(size), weight(size);
	for (int &x : values) std::cin >> x;
	for (int &x : weight) std::cin >> x;

	Solver s(values, weight, capacity);
	auto [best_values_recorded, solution] = s.get_result();

	std::cout << best_values_recorded << '\n';
	for (bool b : solution) {
		std::cout << b << ' ';
	}

	std::cout << std::endl;

	return 0;
}
