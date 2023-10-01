/*
Nhập 2 số nguyên dương a,b không quá 6 chữ số.

Hãy in ra lần lượt các giá trị: tổng, hiệu, tích, chia phần nguyên, chia phần
dư, chia kết quả thực (với đúng 2 chữ số sau dấu phẩy) của 2 số a,b đã cho.

Mỗi kết quả tính toán ghi trên một dòng

Input:
Chỉ có 2 số a,b trên một dòng.

Output:
Gồm 6 dòng lần lượt là kết quả của các phép tính theo thứ tự trong mô tả đề bài.

Ví dụ:
Input:
1 2

Output:
3
-1
2
0
1
0.50
*/

#include <stdio.h>

int main() {
	unsigned long int a, b;
	scanf("%ld %ld", &a, &b);
	if (b) {
		printf("%ld\n", a + b);
		printf("%ld\n", a - b);
		printf("%ld\n", a * b);
		printf("%ld\n", a / b);
		printf("%ld\n", a % b);
		printf("%.2f\n", (float)a / b);
	} else puts("0");
	return 0;
}
