/*
Cho một ma trận cấp M*N chỉ bao gồm các số nguyên dương không quá 1000. Hãy viết
chương trình trước hết loại bỏ hàng đầu tiên sau đó loại bỏ cột đầu tiên ra khỏi
ma trận.

Input: Dòng đầu tiên ghi số bộ test. Mỗi bộ test viết trên một dòng hai số N và
M lần lượt là số hàng và số cột của ma trận (2<N,M<10). Tiếp thep là N dòng ghi
các số của ma trận.

Output:Mỗi bộ test viết ra thứ tự bộ test, sau đó là ma trận sau khi xử lý.
Ví dụ
Input:
1
3 3
1 2 4
3 4 0
6 3 5

Output:
Test 1:
4 0
3 5
*/

#include <stdio.h>

int main() {
	unsigned n, pos = 1;
	scanf("%d", &n);
	while (n--) {
		unsigned row, col, i, j;
		scanf("%d %d", &row, &col);
		int arr[row][col];
		for (i = 0; i < row; i++)
			for (j = 0; j < col; j++) {
				scanf("%d", &arr[i][j]);
			}
		printf("Test %d:\n", pos++);
		for (i = 1; i < row; i++) {
			for (j = 1; j < col; j++) {
				printf("%d ", arr[i][j]);
			}
			putchar('\n');
		};
	};
	return 0;
}
