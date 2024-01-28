#include <iostream>
#include <set>
#include <unordered_map>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		unsigned points, edges;
		std::cin >> points >> edges;

		std::unordered_map<unsigned, std::set<unsigned>> adj_list;
		for (unsigned i = 0; i < edges; i++) {

			unsigned a, b;
			std::cin >> a >> b;

			adj_list[a].insert(b);
			adj_list[b].insert(a);
		}

		for (unsigned i = 1; i <= points; i++) {

			std::cout << i << ':';

			auto it = adj_list.find(i);
			if (it == adj_list.end()) {
				std::cout << '\n';
				continue;
			}

			for (unsigned adj : it->second) {
				std::cout << ' ' << adj;
			}

			std::cout.put('\n');
		}
		std::cout.flush();
	}

	return 0;
}
