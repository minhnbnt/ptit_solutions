#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Edge {
	unsigned from, to;
	int length;
};

unsigned rank;
std::vector<Edge> edges;
std::unordered_set<unsigned> visited;

bool is_negative_cycle(unsigned start_vertex) {

	std::unordered_map<unsigned, int> dists;
	dists.reserve(rank);

	for (unsigned i = 1; i <= rank; i++) {
		dists[i] = INT_MAX;
	}

	dists[start_vertex] = 0;

	for (unsigned i = 1; i < rank; i++) {
		for (const auto &[from, to, length] : edges) {

			if (dists[from] == INT_MAX) {
				continue;
			}

			dists[to] = std::min(dists[to], dists[from] + length);
		}
	}

	for (const auto &[from, to, length] : edges) {

		if (dists[from] == INT_MAX) {
			continue;
		}

		if (dists[from] + length < dists[to]) {
			return true;
		}
	}

	for (unsigned i = 1; i <= rank; i++) {
		if (dists[i] != INT_MAX) {
			visited.insert(i);
		}
	}

	return false;
}

bool has_negative_cycle(void) {

	for (unsigned i = 1; i <= rank; i++) {

		if (visited.find(i) != visited.end()) {
			continue;
		}

		if (is_negative_cycle(i)) {
			return true;
		}
	}

	return false;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned edges_size;
		std::cin >> rank >> edges_size;

		edges.resize(edges_size);
		for (auto &[from, to, length] : edges) {
			std::cin >> from >> to >> length;
		}

		std::cout << has_negative_cycle() << std::endl;

		edges.clear(), visited.clear();
	}

	return 0;
}
