/*
Nhập vào kích thước hình vuông (không quá 9). Vẽ hình vuông số theo nguyên tắc
tương ứng theo mẫu trong ví  dụ dưới đây.

Input
Chỉ có một số dòng ghi kích thước hình vuông (không quá 9).

Output
Ghi ra kết quả theo mẫu.

Ví dụ
Input:
4

Output:
4444444
4333334
4322234
4321234
4322234
4333334
4444444
*/

#include <stdio.h>

int main() {
	int n, i, j, num;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		num = n, j = n + 1;
		while (j-- > n - i + 1) printf("%d", num--);
		while (j--) printf("%d", num);
		while (++j < n - i - 1) printf("%d", num);
		while (++j < n) printf("%d", ++num);
		putchar('\n');
	};
	for (i = n - 1; i > 0; i--) {
		num = j = n;
		while (--j > n - i) printf("%d", num--);
		while (j--) printf("%d", num);
		while (++j < n - i) printf("%d", num);
		while (j++ < n) printf("%d", num++);
		putchar('\n');
	};
	return 0;
}
