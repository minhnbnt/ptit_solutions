#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Graph {

	std::unordered_map<int, std::set<int>> adj_list;

public:

	void add_edges(int a, int b) {
		adj_list[a].insert(b);
		adj_list[b].insert(a);
	}

	void DFS(int start) {

		std::vector<int> stack{ start };
		std::unordered_set<int> visited;

		while (!stack.empty()) {

			const int current = stack.back();
			stack.pop_back();

			auto [_, is_new] = visited.insert(current);
			if (is_new) std::cout << current << ' ';

			for (int adj : adj_list[current]) {

				if (visited.find(adj) != visited.end()) {
					continue;
				}

				stack.push_back(current);
				stack.push_back(adj);

				break;
			}
		}
	}
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned rank, edges, start;
		std::cin >> rank >> edges >> start;

		Graph g;
		for (unsigned i = 0; i < edges; i++) {

			int a, b;
			std::cin >> a >> b;

			g.add_edges(a, b);
		}

		g.DFS(start);
		std::cout << std::endl;
	}

	return 0;
}
