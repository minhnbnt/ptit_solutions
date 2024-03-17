#include <functional>
#include <iostream>
#include <memory>
#include <vector>

struct TreeNode {

	int value;
	std::unique_ptr<TreeNode> left, right;

	TreeNode(int x) : value(x) {}

	bool is_leaf(void) const {

		if (this->left != nullptr) {
			return false;
		}

		if (this->right != nullptr) {
			return false;
		}

		return true;
	}

	void print_leaves(void) const {

		if (this->is_leaf()) {
			std::cout << this->value << ' ';
			return;
		}

		if (this->left != nullptr) {
			this->left->print_leaves();
		}

		if (this->right != nullptr) {
			this->right->print_leaves();
		}
	}
};

void fill_tree_with_comparator(std::unique_ptr<TreeNode> &root, int value,
                               std::function<bool(int, int)> comparator) {

	if (root == nullptr) {
		root = std::make_unique<TreeNode>(value);
		return;
	}

	if (comparator(value, root->value)) {
		fill_tree_with_comparator(root->left, value, comparator);
	} else {
		fill_tree_with_comparator(root->right, value, comparator);
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t size;
		std::cin >> size;

		std::vector<int> inorder(size);
		for (int &x : inorder) {
			std::cin >> x;
		}

		std::unique_ptr<TreeNode> root;
		for (const int element : inorder) {
			fill_tree_with_comparator(root, element, std::less<int>());
		}

		root->print_leaves();
		std::cout << std::endl;
	}

	return 0;
}
