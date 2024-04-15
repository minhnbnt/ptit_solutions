#include <deque>
#include <functional>
#include <iostream>
#include <memory>
#include <unordered_map>

struct TreeNode {

	int value;
	std::unique_ptr<TreeNode> left, right;

	TreeNode(int x) : value(x) {}

	std::function<const TreeNode *(void)> level_transversal(void) const {

		auto pending = std::make_shared<std::deque<const TreeNode *>>();
		pending->push_back(this);

		return [=](void) mutable {
			while (!pending->empty()) {

				const TreeNode *current = pending->front();
				pending->pop_front();

				if (current == NULL) {
					continue;
				}

				pending->push_back(current->left.get());
				pending->push_back(current->right.get());

				return current;
			}

			return static_cast<const TreeNode *>(NULL);
		};
	}
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		std::unique_ptr<TreeNode> root;
		std::unordered_map<int, TreeNode *> node_map;

		unsigned insert_attempt;
		std::cin >> insert_attempt;

		while (insert_attempt--) {

			char direction;
			int parent, child;
			std::cin >> parent >> child >> direction;

			TreeNode *parent_ptr;

			try {
				parent_ptr = node_map.at(parent);
			} catch (const std::out_of_range &e) {
				root = std::make_unique<TreeNode>(parent);
				node_map[parent] = parent_ptr = root.get();
			}

			auto child_node = std::make_unique<TreeNode>(child);
			node_map[child] = child_node.get();

			switch (direction) {
			case 'L':
				parent_ptr->left = std::move(child_node);
				break;
			case 'R':
				parent_ptr->right = std::move(child_node);
				break;
			}
		}

		auto generator = root->level_transversal();

		while (true) {

			const TreeNode *current = generator();

			if (current == NULL) {
				break;
			}

			std::cout << current->value << ' ';
		}

		std::cout << std::endl;
	}

	return 0;
}
