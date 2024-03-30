#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

struct TreeNode {

	int value;
	unsigned level;

	std::unique_ptr<TreeNode> left, right;

	void spiral_order_transversal(void) const;

	TreeNode(unsigned level, int x) : value(x), level(level) {}
};

void TreeNode::spiral_order_transversal(void) const {

	std::deque<const TreeNode *> queue{ this };
	std::map<unsigned, std::vector<const TreeNode *>> level_map;

	while (!queue.empty()) {

		const TreeNode *current = queue.front();
		queue.pop_front();

		if (current == NULL) {
			continue;
		}

		level_map[current->level].push_back(current);

		queue.push_back(current->left.get());
		queue.push_back(current->right.get());
	}

	for (auto &[level, nodes] : level_map) {

		if (level % 2 == 0) {
			std::reverse(nodes.begin(), nodes.end());
		}

		for (const TreeNode *ptr : nodes) {
			std::cout << ptr->value << ' ';
		}
	}
}

signed main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t insert_attempt;
		std::cin >> insert_attempt;

		std::unique_ptr<TreeNode> root;
		std::map<int, TreeNode *> node_map;

		while (insert_attempt--) {

			char direction;
			int parent, child;
			std::cin >> parent >> child >> direction;

			TreeNode *parent_ptr;

			try {
				parent_ptr = node_map.at(parent);
			} catch (const std::out_of_range &e) {
				root = std::make_unique<TreeNode>(0, parent);
				parent_ptr = node_map[parent] = root.get();
			}

			auto *child_ptr = new TreeNode(parent_ptr->level + 1, child);
			node_map.emplace(child, child_ptr);

			switch (direction) {
			case 'L':
				parent_ptr->left = std::unique_ptr<TreeNode>(child_ptr);
				break;

			case 'R':
				parent_ptr->right = std::unique_ptr<TreeNode>(child_ptr);
				break;
			}
		}

		root->spiral_order_transversal();
		std::cout << std::endl;
	}

	return 0;
}
