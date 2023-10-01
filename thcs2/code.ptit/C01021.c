/*
Viết chương trình nhập vào một số n không quá 10^9, thực hiện tìm tổng các chữ
số của n và in ra màn hình.

Input:
Chỉ có một dòng ghi số n.

Output:
Ghi ra kết quả tính toán

Ví dụ:
Input:
1024

Output:
10
*/

#include <stdio.h>

int main() {
	long a;
	scanf("%ld", &a);
	int sum = 0;
	while (a > 0) {
		sum += a % 10;
		a /= 10;
	}
	printf("%d\n", sum);
	return 0;
}
