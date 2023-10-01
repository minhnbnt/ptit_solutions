/*
Viết chương trình phân tích một số nguyên dương (không quá 6 chữ số) thành tích
các thừa số nguyên tố.

Kết quả được viết theo mẫu trong Ví dụ (có chữ x giữa các thừa số)

Input:
Chỉ có một dòng ghi số n.

Output:
Ghi ra kết quả tính toán

Ví dụ:
Input:
28

Output:
2x2x7
*/

#include <math.h>
#include <stdio.h>

int main() {
	long n;
	scanf("%ld", &n);
	for (int i = 2; i <= sqrt(n); i++)
		while (n % i == 0) {
			printf("%d", i), n /= i;
			if (n > 1) printf("x");
		}
	if (n > 1) printf("%ld", n);
	putchar('\n');
	return 0;
}
