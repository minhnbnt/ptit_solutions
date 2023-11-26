/*
Cho mảng A[] gồm n số nguyên dương. Nhiệm vụ của bạn là hãy sắp xếp lại các phần
tử của mảng sao cho A[i] ≥A[i-1] nếu i chẵn,  A[i] ≤A[i-1] nếu i lẻ. Ví dụ với
mảng A[] = {1, 2, 2, 1} ta được mảng được sắp A[] = { 1, 2, 1, 2}.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào n là số phần tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng;
các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤103; 1≤ A[i] ≤10^3;

Output:
Đưa ra kết quả mỗi test theo từng dòng.
Input:
2
4
1 2 2 1

3
1 3 2

Output:
1 2 1 2
1 3 2
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)a > *(int *)b;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned ele, i, j = 0;
		scanf("%u", &ele);

		int arr[ele], buf[ele];
		for (i = 0; i < ele; ++i) {
			scanf("%d", &arr[i]);
		}
		qsort(arr, ele, sizeof(int), cmp);

		for (i = 0; i < ele; i += 2) {
			buf[i] = arr[j];
			++j;
		}
		for (i = 1; i < ele; i += 2) {
			buf[i] = arr[j];
			++j;
		}

		for (i = 0; i < ele; ++i) {
			printf("%d ", buf[i]);
		}

		putchar('\n');
		fflush(stdout);
	}

	return 0;
}
