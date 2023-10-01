/*
Hãy thực hiện thuật toán sắp xếp nổi bọt trên dãy N số nguyên. Ghi ra các bước
thực hiện thuật toán.

Input: Dòng 1 ghi số N (không quá 100). Dòng 2 ghi N số nguyên dương (không quá
100).

Output:Ghi ra màn hình từng bước thực hiện thuật toán. Mỗi bước trên một dòng,
các số trong dãy cách nhau đúng một khoảng trống.

Ví dụ:
Input:
4
5 3 2 7

Output:
Buoc 1: 3 2 5 7
Buoc 2: 2 3 5 7
*/

#include <stdio.h>

int main() {
	int n, buoc = 1;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	while (1) {
		char flag = 0;
		for (int i = 0; i < n - 1; i++)
			if (a[i] > a[i + 1]) {
				int t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
				flag = 1;
			}
		if (flag) {
			printf("Buoc %d: ", buoc++);
			for (int i = 0; i < n; i++) {
				printf("%d ", a[i]);
			}
			putchar('\n');
		} else break;
	}
	return 0;
}
