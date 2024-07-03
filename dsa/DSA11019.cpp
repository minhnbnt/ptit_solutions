#include <iostream>
#include <vector>

struct TreeNode {
	int data;
	TreeNode *left, *right;
};

void fill_tree(TreeNode *&root, TreeNode *node) {

	if (root == NULL) {
		root = node;
		return;
	}

	if (root->data > node->data) {
		fill_tree(root->left, node);
	} else {
		fill_tree(root->right, node);
	}
}

void post_order_transverse(const TreeNode *root) {

	if (root == NULL) {
		return;
	}

	post_order_transverse(root->left);
	post_order_transverse(root->right);

	std::cout << root->data << ' ';
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t size;
		std::cin >> size;

		std::vector<TreeNode> nodes(size);
		for (auto &[data, left, right] : nodes) {
			left = right = NULL;
			std::cin >> data;
		}

		TreeNode *root = NULL;
		for (TreeNode &node : nodes) {
			fill_tree(root, &node);
		}

		post_order_transverse(root);
		std::cout << std::endl;
	}

	return 0;
}
