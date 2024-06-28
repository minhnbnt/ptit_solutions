/*
Cho danh sách liên kết đơn lưu giữ các số nguyên được quản lý bởi con trỏ First.

Viết chương trình con xóa tất cả các phần tử có giá trị bằng x trong danh sách
liên kết đơn; chương trình con trả về số lượng các phần tử đã xóa.

Sau khi xóa xong, liệt kê các phần tử còn lại trong danh sách liên kết đơn
First.

Ví dụ: Ta có Input sau:
14                          // là số lượng phần tử trong danh sách
1 1 1 4 5 1 1 1 1 7 1 8 1 9 // là 14 phần tử
1                           // là số cần xóa

Output:
4 5 7 8 9
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int value;
	struct Node *next;

} Node;

Node *new_linked_list(size_t size) {

	Node *head = NULL;

	while (size-- > 0) {

		Node *new_node = (Node *)malloc(sizeof(Node));

		new_node->next = head;
		head = new_node;
	}

	return head;
}

void free_linked_list(Node *head) {

	while (head != NULL) {

		Node *next = head->next;

		free(head);
		head = next;
	}
}

void filter(Node **head, int target) {

	Node *ptr;

	while (1) {

		ptr = *head;

		if (ptr == NULL) {
			return;
		}

		if (ptr->value != target) {
			break;
		}

		Node *next = ptr->next;

		free(ptr);
		*head = next;
	}

	while (1) {

		Node *ptr_next = ptr->next;

		if (ptr_next == NULL) {
			break;
		}

		if (ptr_next->value != target) {
			ptr = ptr_next;
			continue;
		}

		Node *next_next = ptr_next->next;

		free(ptr_next);
		ptr->next = next_next;
	}
}

void print_linked_list(const Node *head) {

	while (head != NULL) {
		printf("%d ", head->value);
		head = head->next;
	}

	putchar('\n');
	fflush(stdout);
}

int main(void) {

	size_t ele;
	scanf("%zu", &ele);

	Node *head = new_linked_list(ele);
	for (Node *ptr = head; ptr != NULL; ptr = ptr->next) {
		scanf("%d", &ptr->value);
	}

	int target;
	scanf("%d", &target);

	filter(&head, target);

	print_linked_list(head);

	free_linked_list(head);

	return 0;
}
