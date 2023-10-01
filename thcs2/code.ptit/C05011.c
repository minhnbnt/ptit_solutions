/*
Cho ma trận A chỉ gồm các số nguyên dương cấp N*M. Hãy viết chương trình tính
tích của A với ma trận chuyển vị của A.

Input: Dòng đầu tiên ghi số bộ test. Với mỗi bộ test: Dòng đầu tiên ghi hai số n
và m là bậc của ma trân a; n dòng tiếp theo, mỗi dòng ghi m  số của một dòng
trong ma trận A.

Output: Với mỗi bộ test ghi ra thứ tự bộ test, sau đó đến ma trận tích tương
ứng, mỗi số cách nhau đúng một khoảng trống.

Ví dụ:

Input:
1
2 2
1 2
3 4

Output:
Test 1:
5 11
11 25
*/

#include <stdio.h>

int main(void) {
	unsigned test, l = 0;
	scanf("%u", &test);
	while (l++ < test) {
		printf("Test %u:\n", l);
		unsigned x, y, i, j, k;
		scanf("%u%u", &x, &y);
		int arr[x][y];
		for (i = 0; i < x; i++)
			for (j = 0; j < y; j++) //
				scanf("%d", &arr[i][j]);
		for (i = 0; i < x; i++) {
			for (j = 0; j < x; j++) {
				unsigned long sum = 0;
				for (k = 0; k < y; k++) //
					sum += arr[i][k] * arr[j][k];
				printf("%lu ", sum);
			}
			putchar('\n');
		}
	}
	return 0;
}
