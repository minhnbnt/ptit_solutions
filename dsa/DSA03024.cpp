#include <iostream>
#include <queue>

struct Task {

	unsigned start, finish;

	Task(void) = default;
	Task(unsigned start, unsigned finish) {
		this->start = start;
		this->finish = finish;
	}

	bool operator<(const Task &other) const {

		if (this->finish != other.finish) {
			return this->finish > other.finish;
		}

		return this->start < other.start;
	}
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t number_of_tasks, i;
		std::cin >> number_of_tasks;

		std::priority_queue<Task> tasks;
		for (i = 0; i < number_of_tasks; i++) {

			unsigned start, finish;
			std::cin >> start >> finish;

			tasks.emplace(start, finish);
		}

		size_t result = 0;
		unsigned prev_finish = 0;

		while (!tasks.empty()) {

			const Task current = tasks.top();
			tasks.pop();

			if (current.start < prev_finish) {
				continue;
			}

			prev_finish = current.finish;
			++result;
		}

		std::cout << result << std::endl;
	}

	return 0;
}
