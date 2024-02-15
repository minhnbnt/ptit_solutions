#include <functional>
#include <iostream>
#include <memory>
#include <vector>

struct TreeNode {

	int value;
	std::unique_ptr<TreeNode> left, right;

	TreeNode(int x) : value(x) {}
};

void fill_tree(std::unique_ptr<TreeNode> &root, int value,
               std::function<bool(int, int)> comparator) {

	if (root == nullptr) {
		root = std::make_unique<TreeNode>(value);
		return;
	}

	if (comparator(value, root->value)) {
		fill_tree(root->left, value, comparator);
	} else {
		fill_tree(root->right, value, comparator);
	}
}

void post_order_traversal(const TreeNode *root) {

	if (root == NULL) return;

	post_order_traversal(root->left.get());
	post_order_traversal(root->right.get());

	std::cout << root->value << ' ';
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele;
		std::cin >> ele;

		std::vector<int> preorder(ele);
		for (int &element : preorder) {
			std::cin >> element;
		}

		std::unique_ptr<TreeNode> root;
		for (int element : preorder) {
			fill_tree(root, element, std::less<int>());
		}

		post_order_traversal(root.get());
		std::cout << std::endl;
	}

	return 0;
}
