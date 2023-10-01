/*
Cho một dãy N các phần tử nguyên. Tính giá trị trung bình (để sau dấu phẩy đúng
3 chữ số)

Input:
Hai dòng, dòng đầu là số phần tử; dòng tiếp theo sau là dòng các phần tử

Output:
Giá trị trung bình của dãy với 3 chữ số sau dấu phảy

Ví dụ minh họa:
Input:
4
2 4 1 2

Output:
2.250
*/

#include <stdio.h>

int main(void) {
	unsigned n, i;
	scanf("%u", &n);
	float sum;
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		sum += x;
	}
	printf("%.3f\n", sum / n);
}
