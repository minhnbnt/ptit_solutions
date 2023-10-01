/*
Cho số nguyên dương N (không quá 9). In ra lần lượt kết quả phép nhân của N với
các số từ 1 đến 10, mỗi giá trị cách nhau một khoảng trống

Input

Có duy nhất một dòng ghi số nguyên dương N (1 ≤ N ≤ 9).

Output

In kết quả trên một dòng.

Ví dụ:
Input:
5

Output:
5 10 15 20 25 30 35 40 45 50
*/

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (char i = 1; i <= 10; i++) {
		printf("%d ", n * i);
	}
	putchar('\n');
	return 0;
}
