#include <iostream>
#include <queue>
#include <vector>

int lowest_costs_to_corner(const std::vector<std::vector<int>> &grid) {

	struct QueueRecord {

		int x, y;
		int cost;

		QueueRecord(int x, int y, int cost) //
		    : x(x), y(y), cost(cost) {}

		bool operator<(const QueueRecord &other) const {
			return this->cost > other.cost;
		}
	};

	static const int DX[] = { -1, 0, 1, 0 };
	static const int DY[] = { 0, -1, 0, 1 };

	const int row = grid.size(), col = grid[0].size();

	std::priority_queue<QueueRecord> queue;
	queue.emplace(0, 0, grid[0][0]);

	std::vector<std::vector<bool>> visited(row);
	for (std::vector<bool> &v : visited) {
		v.resize(col, false);
	}

	visited[0][0] = true;

	while (true) {

		const auto [x, y, cost] = queue.top();
		queue.pop();

		if (x == row - 1 && y == col - 1) {
			return cost;
		}

		for (int i = 0; i < 4; i++) {

			const int new_x = x + DX[i];
			const int new_y = y + DY[i];

			if (new_x < 0 || new_x >= row) {
				continue;
			}

			if (new_y < 0 || new_y >= col) {
				continue;
			}

			if (visited[new_x][new_y]) {
				continue;
			}

			const int new_cost = cost + grid[new_x][new_y];
			queue.emplace(new_x, new_y, new_cost);

			visited[new_x][new_y] = true;
		}
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		int row, col;
		std::cin >> row >> col;

		std::vector<std::vector<int>> grid(row);

		for (std::vector<int> &v : grid) {

			v.resize(col);

			for (int &x : v) {
				std::cin >> x;
			}
		}

		std::cout << lowest_costs_to_corner(grid) << std::endl;
	}

	return 0;
}
