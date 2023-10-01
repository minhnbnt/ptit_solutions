/*
Cho một số nguyên dương N không quá 20. Ma trận vuông A cấp N*N được tạo theo
mẫu trong bảng dưới. Viết chương trình tính tích của A với chuyển vị của A.

Với N = 5     Với N = 4
1 0 0 0 0     1 0 0 0
1 2 0 0 0     1 2 0 0
1 2 3 0 0     1 2 3 0
1 2 3 4 0     1 2 3 4
1 2 3 4 5

Input: Dòng 1 ghi số bộ test. Mỗi bộ test ghi trên một dòng số N (1<N<20).

Output: Ghi thứ tự bộ test, sau đó là N hàng ghi ma trận kết quả. Tiếp theo là
một dòng trống.

Ví dụ:
Input:
1
4

Output:
Test 1:
1 1 1 1
1 5 5 5
1 5 14 14
1 5 14 30
*/

#include <stdio.h>

unsigned min(unsigned a, unsigned b) {
	return a < b ? a : b;
}

unsigned long generate(unsigned n) {
	if (++n == 1) return 1;
	return generate(n - 2) + n * n;
}

int main(void) {
	unsigned test, i = 0;
	scanf("%u", &test);
	while (i++ < test) {
		printf("Test %u:\n", i);
		unsigned n, j, k;
		scanf("%u", &n);
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) //
				printf("%lu ", generate(min(j, k)));
			putchar('\n');
		}
	}
	return 0;
}
