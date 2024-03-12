#include <functional>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

template <typename T>
struct TreeNode {

	T data;
	std::unique_ptr<TreeNode<T>> left, right;

	TreeNode(T x) : data(x) {}
};

class Comparator {

	std::unordered_map<int, size_t> index_map;

public:

	Comparator(const std::vector<int> &inorder) {
		for (size_t i = 0; i < inorder.size(); i++) {
			index_map.emplace(inorder[i], i);
		}
	}

	std::function<bool(int, int)> get(void) const {
		return [this](int a, int b) { //
			return index_map.at(a) < index_map.at(b);
		};
	}
};

template <typename T>
void fill_tree(std::unique_ptr<TreeNode<T>> &root, T data,
               std::function<bool(T, T)> comparator) {

	if (root == nullptr) {
		root = std::make_unique<TreeNode<T>>(data);
		return;
	}

	if (comparator(data, root->data)) {
		fill_tree(root->left, data, comparator);
	} else {
		fill_tree(root->right, data, comparator);
	}
}

std::unique_ptr<TreeNode<int>>
get_tree_by_levelorder(const std::vector<int> &levelorder,
                       std::function<bool(int, int)> comparator) {

	std::unique_ptr<TreeNode<int>> root;

	for (int element : levelorder) {
		fill_tree(root, element, comparator);
	}

	return root;
}

void postorder_transversval(const TreeNode<int> *root) {

	if (root == NULL) return;

	postorder_transversval(root->left.get());
	postorder_transversval(root->right.get());

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

		std::vector<int> inorder(size), levelorder(size);
		for (int &x : inorder) std::cin >> x;
		for (int &x : levelorder) std::cin >> x;

		const Comparator comparator(inorder);

		auto root = get_tree_by_levelorder(levelorder, comparator.get());

		postorder_transversval(root.get());
		std::cout << std::endl;
	}

	return 0;
}
