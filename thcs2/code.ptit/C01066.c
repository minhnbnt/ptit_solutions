/*
Viết chương trình nhập vào ba số nguyên có trị tuyệt đối không quá 6 chữ số. Tìm
giá trị nhỏ nhất trong ba số đó.

Input:
Chỉ có một dòng ghi ba số a,b,c cách nhau một khoảng trống. Cả ba số không quá 6
chữ số.

Output:
Ghi ra số nhỏ nhất.

Ví dụ
Input:
10 20 30

Output:
10
*/

#include <stdio.h>

int main() {
	int a[3];
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	int min = a[0];
	for (int i = 1; i < 3; i++)
		if (a[i] < min) min = a[i];
	printf("%d", min);
	return 0;
}
