#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left, *right;
};

typedef struct Node Node;

void free_node(Node *root) {

	if (root == NULL) {
		return;
	}

	free_node(root->left);
	free_node(root->right);

	free(root);
}

Node *tree_find(Node *root, int value) {

	if (root == NULL) {
		return NULL;
	}

	if (root->data == value) {
		return root;
	}

	Node *ptr_find = tree_find(root->left, value);
	if (ptr_find != NULL) {
		return ptr_find;
	}

	ptr_find = tree_find(root->right, value);
	if (ptr_find != NULL) {
		return ptr_find;
	}

	return NULL;
}

Node *new_node(int value) {

	Node *ptr = (Node *)malloc(sizeof(Node));
	ptr->left = ptr->right = NULL;

	ptr->data = value;
	return ptr;
}

int is_full_binary_tree(Node *root) {

	if (root == NULL) {
		return 1;
	}

	if (root->left == NULL && root->right == NULL) {
		return 1;
	}

	if (root->left == NULL || root->right == NULL) {
		return 0;
	}

	if (!is_full_binary_tree(root->left)) {
		return 0;
	}

	if (!is_full_binary_tree(root->right)) {
		return 0;
	}

	return 1;
}

int main() {

	unsigned cases;
	scanf("%u", &cases);

	while (cases-- > 0) {

		unsigned insert_attempt;
		scanf("%u", &insert_attempt);

		Node *root = NULL;

		while (insert_attempt-- > 0) {

			char direction;
			int parent, child;
			scanf("%d%d%*[ ]%c", &parent, &child, &direction);

			Node *parent_node = tree_find(root, parent);
			if (parent_node == NULL) {
				root = new_node(parent);
				parent_node = root;
			}

			Node *child_node = new_node(child);

			switch (direction) {
			case 'L':
				parent_node->left = child_node;
				break;
			case 'R':
				parent_node->right = child_node;
				break;
			}
		}

		printf("%d\n", is_full_binary_tree(root));
		fflush(stdout);

		free_node(root);
	}

	return 0;
}
