#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode TreeNode;

struct TreeNode {
	int value;
	TreeNode *left, *right;
};

void postorder_transverse(TreeNode *root) {

	if (root == NULL) return;

	postorder_transverse(root->left);
	postorder_transverse(root->right);

	printf("%d ", root->value);
}

TreeNode *new_node(int value) {

	TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));

	new_node->left = new_node->right = NULL;
	new_node->value = value;

	return new_node;
}

TreeNode *get_tree(const int *begin, const int *end) {

	if (begin >= end) return NULL;

	const size_t distance = end - begin;
	const int *middle = begin + (distance - 1) / 2;

	TreeNode *root = new_node(*middle);

	root->left = get_tree(begin, middle);
	root->right = get_tree(middle + 1, end);

	return root;
}

void free_tree(TreeNode *root) {

	if (root == NULL) return;

	free_tree(root->left);
	free_tree(root->right);

	free(root);
}

int comparator(const void *a, const void *b) {
	return *(const int *)a - *(const int *)b;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		size_t i, size;
		scanf("%zu", &size);

		int array[size];
		for (i = 0; i < size; i++) {
			scanf("%d", &array[i]);
		}

		qsort(array, size, sizeof(int), comparator);

		TreeNode *root = get_tree(array, array + size);

		postorder_transverse(root);
		putchar('\n');

		free_tree(root);
	}

	return EXIT_SUCCESS;
}
