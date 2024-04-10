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

std::unique_ptr<TreeNode>
fill_tree_by_preorder(const std::vector<int> &preorder) {

	std::unique_ptr<TreeNode> root = nullptr;

	for (int element : preorder) {
		fill_tree(root, element, std::less<int>());
	}

	return root;
}

void postorder_transversal(const TreeNode *root) {

	if (root == NULL) return;

	postorder_transversal(root->left.get());
	postorder_transversal(root->right.get());

	std::cout << root->value << ' ';
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		size_t size;
		std::cin >> size;

		std::vector<int> preorder(size);
		for (int &x : preorder) {
			std::cin >> x;
		}

		auto root = fill_tree_by_preorder(preorder);

		postorder_transversal(root.get());
		std::cout << std::endl;
	}

	return 0;
}
