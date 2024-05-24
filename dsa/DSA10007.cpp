#include <deque>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Edge {

	int a, b;

	Edge(int a, int b) : a(a), b(b) {}
};

class AdjancencyList {

	int rank;
	std::unordered_map<int, std::vector<int>> adj_list;

public:

	AdjancencyList(int rank) : rank(rank) {
		adj_list.reserve(rank);
	}

	void add_edges(int a, int b) {
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	std::vector<Edge> get_tree(int start) {

		std::vector<Edge> result;
		result.reserve(rank - 1);

		std::deque<int> queue{ start };
		std::unordered_set<int> visited{ start };

		while (!queue.empty()) {

			int current = queue.front();
			queue.pop_front();

			for (int vertex : adj_list[current]) {

				if (visited.find(vertex) != visited.end()) {
					continue;
				}

				result.emplace_back(current, vertex);

				if (result.size() == rank - 1) {
					return result;
				}

				queue.push_back(vertex);
				visited.insert(vertex);
			}
		}

		return std::vector<Edge>();
	}
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		int vertices, edge, start_vertex;
		std::cin >> vertices >> edge >> start_vertex;

		AdjancencyList graph(vertices);

		for (; edge > 0; edge--) {

			int a, b;
			std::cin >> a >> b;

			graph.add_edges(a, b);
		}

		auto tree = graph.get_tree(start_vertex);

		if (tree.empty()) {
			std::cout << -1 << std::endl;
			continue;
		}

		for (auto &[a, b] : tree) {
			std::cout << a << ' ' << b << '\n';
		}

		std::cout.flush();
	}

	return 0;
}
