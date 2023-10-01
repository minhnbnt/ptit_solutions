/*
Cho hai số nguyên dương a,b không quá 106.
Thực hiện tính tổng các số tự nhiên nằm trong đoạn [a, b] và in ra màn hình.
(Lưu ý có thể nhập a lớn hơn b)

Input
Chỉ có một dòng ghi hai số nguyên dương a,b (không quá 6 chữ số)

Output
Ghi ra kết quả trên một dòng

Ví dụ:
Input:
1 10

Output:
55
*/

#include <stdio.h>

int main() {
	unsigned long a, b;
	scanf("%lu %lu", &a, &b);
	if (a > b) {
		unsigned long temp = a;
		a = b, b = temp;
	}
	printf("%lu\n", (b - a + 1) * (a + b) / 2);
	return 0;
}
