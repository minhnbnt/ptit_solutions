/*
Nhập 2 số nguyên dương a,b không quá 1000.

Hãy in ra lần lượt các giá trị: tổng, hiệu, tích, chia kết quả thực (với đúng 2
chữ số sau dấu phẩy) và chia phần dư của 2 số a,b đã cho.

Kết quả tính toán ghi trên một dòng. Nếu b = 0 thì không thực hiện phép toán nào
mà chỉ in ra số 0.

Input:
Chỉ có 2 số a,b trên một dòng.

Output:
Ghi ra lần lượt kết quả các phép toán trên một dòng.

Ví dụ:
Input:
10 5

Output:
15 5 50 2.00 0
*/

#include <stdio.h>

int main() {
	unsigned int a, b;
	scanf("%d %d", &a, &b);
	if (b) {
		printf("%d ", a + b);
		printf("%d ", a - b);
		printf("%d ", a * b);
		printf("%.2f ", (float)a / b);
		printf("%d\n", a % b);
	} else puts("0");
	return 0;
}
