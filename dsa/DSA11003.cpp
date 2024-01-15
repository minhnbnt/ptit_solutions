#include <functional>
#include <iostream>
#include <memory>
#include <unordered_map>
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

std::unique_ptr<TreeNode> fill_tree_by_order(const std::vector<int> &inorder,
                                             const std::vector<int> &preorder) {

	std::unordered_map<int, size_t> inorder_index_map;
	for (size_t i = 0; i < inorder.size(); ++i) {
		inorder_index_map.emplace(inorder[i], i);
	}

	const auto comparator = [&inorder_index_map](int a, int b) {
		return inorder_index_map[a] < inorder_index_map[b];
	};

	std::unique_ptr<TreeNode> root;
	for (const int x : preorder) {
		fill_tree(root, x, comparator);
	}

	return root;
}

void post_order_traversal(const std::unique_ptr<TreeNode> &root) {

	if (root == nullptr) return;

	post_order_traversal(root->left);
	post_order_traversal(root->right);

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

		std::vector<int> inorder(ele), preorder(ele);
		for (int &x : inorder) {
			std::cin >> x;
		}
		for (int &x : preorder) {
			std::cin >> x;
		}

		auto root = fill_tree_by_order(inorder, preorder);

		post_order_traversal(root);
		std::cout << std::endl;
	}

	return 0;
}
