#include <cstdint>
#include <deque>
#include <iostream>
#include <map>

class RetrangleState {

	union {
		uint8_t array[6];
		uint8_t values[2][3];
	};

public:

	RetrangleState(unsigned a[6]) {
		for (unsigned i = 0; i < 6; i++) {
			array[i] = a[i];
		}
	}

	RetrangleState left_rotate(void) const {

		RetrangleState result = *this;

		uint8_t temp = result.values[0][0];
		result.values[0][0] = result.values[1][0];
		result.values[1][0] = result.values[1][1];
		result.values[1][1] = result.values[0][1];
		result.values[0][1] = temp;

		return result;
	}

	RetrangleState right_rotate(void) const {

		RetrangleState result = *this;

		uint8_t temp = result.values[0][1];
		result.values[0][1] = result.values[1][1];
		result.values[1][1] = result.values[1][2];
		result.values[1][2] = result.values[0][2];
		result.values[0][2] = temp;

		return result;
	}

	bool operator<(const RetrangleState &other) const {

		for (unsigned i = 0; i < 6; i++) {
			if (this->array[i] != other.array[i]) {
				return this->array[i] < other.array[i];
			}
		}

		return false;
	}
};

unsigned number_of_step(RetrangleState begin, RetrangleState end) {

	std::deque<RetrangleState> queue{ begin };
	std::map<RetrangleState, unsigned> generated{ { begin, 0 } };

	while (generated.find(end) == generated.end()) {

		const RetrangleState current = queue.front();
		const unsigned number_of_move = generated[current];

		queue.pop_front();

		for (auto next : { current.left_rotate(), current.right_rotate() }) {

			if (generated.find(next) != generated.end()) {
				continue;
			}

			generated.emplace(next, number_of_move + 1);
			queue.push_back(next);
		}
	}

	return generated.at(end);
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned begin_arr[6];
		for (unsigned &x : begin_arr) {
			std::cin >> x;
		}

		unsigned end_arr[6];
		for (unsigned &x : end_arr) {
			std::cin >> x;
		}

		const RetrangleState begin(begin_arr), end(end_arr);
		std::cout << number_of_step(begin, end) << std::endl;
	}

	return 0;
}
