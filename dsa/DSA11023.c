#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (a > b ? a : b)

typedef struct TreeNode TreeNode;

struct TreeNode {

	int value;

	struct TreeNode *left;
	struct TreeNode *right;
};

TreeNode *new_node(int value) {

	TreeNode *result = (TreeNode *)malloc(sizeof(TreeNode));

	result->left = result->right = NULL;
	result->value = value;

	return result;
}

void insert_node(TreeNode **root, int value) {

	if (*root == NULL) {
		*root = new_node(value);
		return;
	}

	if (value < (*root)->value) {
		insert_node(&(*root)->left, value);
	} else {
		insert_node(&(*root)->right, value);
	}
}

TreeNode *fill_tree_by_preorder(const int *pre_order, size_t size) {

	TreeNode *result = NULL;

	for (size_t i = 0; i < size; i++) {
		insert_node(&result, pre_order[i]);
	}

	return result;
}

void free_btree(TreeNode *root) {

	if (root == NULL) return;

	free_btree(root->left);
	free_btree(root->right);

	free(root);
}

unsigned get_depth(const TreeNode *root) {

	if (root == NULL) return 0;

	const unsigned left_depth = get_depth(root->left);
	const unsigned right_depth = get_depth(root->right);

	return max(left_depth, right_depth) + 1;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		size_t i, size;
		scanf("%zu", &size);

		int pre_order[size];
		for (i = 0; i < size; i++) {
			scanf("%d", &pre_order[i]);
		}

		TreeNode *root = fill_tree_by_preorder(pre_order, size);
		printf("%u\n", get_depth(root) - 1);

		free(root);
	}

	return EXIT_SUCCESS;
}
