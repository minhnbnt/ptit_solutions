/*
Cho một ma trận cấp M*N chỉ bao gồm các số nguyên dương không quá 1000. Hãy viết
chương trình trước hết loại bỏ hàng có tổng lớn nhất sau đó tính toán lại để
loại tiếp cột có tổng lớn nhất ra khỏi ma trận.

Input: Dòng đầu tiên ghi số bộ test.  Mỗi bộ test viết trên một dòng hai số N và
M lần lượt là số hàng và số cột của ma trận (2<N,M<10). Tiếp thep là N dòng ghi
các số của ma trận.

Output: Mỗi bộ test viết ra thứ tự bộ test, sau đó là ma trận sau khi tính toán.

Ví dụ:
Input:
1
3 3
1 2 4
3 4 0
6 3 5

Output:
Test 1:
1 4
3 0
*/

#include <stdio.h>

int main(void) {
	unsigned test, current = 0;
	scanf("%u", &test);
	while (current++ < test) {
		printf("Test %u:\n", current);
		unsigned row, col, i, j;
		scanf("%u%u", &row, &col);
		int arr[row][col], max = -32767;
		unsigned max_valued_row;
		for (i = 0; i < row; i++) {
			int sum = 0;
			for (j = 0; j < col; j++) {
				scanf("%d", &arr[i][j]);
				sum += arr[i][j];
			}
			if (sum > max) {
				max_valued_row = i;
				max = sum;
			}
		}
		max = -__INT_MAX__;
		unsigned max_valued_col;
		for (i = 0; i < col; i++) {
			int sum = 0;
			for (j = 0; j < row; j++) {
				if (j == max_valued_row) continue;
				sum += arr[j][i];
			}
			if (sum > max) {
				max_valued_col = i;
				max = sum;
			}
		}
		for (i = 0; i < row; i++) {
			if (i == max_valued_row) continue;
			for (j = 0; j < col; j++) {
				if (j == max_valued_col) continue;
				printf("%d ", arr[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
}
