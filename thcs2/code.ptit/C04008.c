/*
Nhập 2 mảng (a, N) và (b, M) và số nguyên p (0≤p<M<=N<100). Hãy chèn mảng b vào
vị trí p của mảng a.

Input: Dòng đầu ghi số bộ test, mỗi bộ test gồm 3 dòng: dòng đầu ghi 3 số N,M,p.
Dòng thứ 2 ghi N số của mảng a. Dòng thứ 3 ghi M số của mảng b.

Output: ghi ra thứ tự bộ test, rồi xuống dòng và dãy số kết quả sau khi chèn.

Ví dụ:

Input:
1
4 3 1
5 3 6 7
2 9 11

Output:
Test 1:
5 2 9 11 3 6 7
*/

#include <stdio.h>

int main() {
	int test;
	scanf("%d", &test);
	for (int k = 1; k <= test; k++) {
		int a, b, pos, i, j;
		scanf("%d %d %d", &a, &b, &pos);
		int arr1[a], arr2[b];
		for (i = 0; i < a; i++) {
			scanf("%d", &arr1[i]);
		}
		for (j = 0; j < b; j++) {
			scanf("%d", &arr2[j]);
		}
		char flag = 1;
		printf("Test %d: \n", k);
		for (i = 0; i < a; i++) {
			if (pos - i == 0) {
				for (j = 0; j < b; j++) {
					printf("%d ", arr2[j]);
				}
				flag = 0;
			}
			printf("%d ", arr1[i]);
		}
		if (flag)
			for (j = 0; j < b; j++) {
				printf("%d ", arr2[j]);
			}
		putchar('\n');
	}
	return 0;
}
