#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

struct Edge {

	int a, b;
	int length;

	bool operator<(const Edge &other) {
		return this->length < other.length;
	}
};

class DisjoinSet {

	std::unordered_map<int, int> parent;
	std::unordered_map<int, unsigned> children_size;

public:

	DisjoinSet(int vertex) {

		children_size.reserve(vertex);
		parent.reserve(vertex);

		for (int i = 1; i < vertex; i++) {
			children_size[i] = 1;
			parent[i] = i;
		}
	}

	bool is_connected(int a, int b) {
		return find_parent(a) == find_parent(b);
	}

	int find_parent(int vertex) {

		if (parent[vertex] != vertex) {
			parent[vertex] = find_parent(parent[vertex]);
		}

		return parent[vertex];
	}

	void union_2sets(int a, int b) {

		int parent_a = find_parent(a);
		int parent_b = find_parent(b);

		if (parent_a == parent_b) {
			return;
		}

		if (children_size[parent_a] < children_size[parent_a]) {
			std::swap(parent_a, parent_b);
		}

		children_size[parent_a] += children_size[parent_b];
		parent[parent_b] = parent_a;
	}
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		int vertices, edges_size;
		std::cin >> vertices >> edges_size;

		std::vector<Edge> edges(edges_size);
		for (auto &[a, b, length] : edges) {
			std::cin >> a >> b >> length;
		}

		std::sort(std::begin(edges), std::end(edges));

		unsigned tree_length = 0;

		DisjoinSet set(vertices);
		for (auto &[a, b, length] : edges) {

			if (set.is_connected(a, b)) {
				continue;
			}

			tree_length += length;
			set.union_2sets(a, b);
		}

		std::cout << tree_length << std::endl;
	}

	return 0;
}
