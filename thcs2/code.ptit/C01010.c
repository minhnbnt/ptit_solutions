/*
Viết chương trình nhập vào số ngày, thực hiện chuyển số ngày sang năm, tuần,
ngày (bỏ qua trường hợp năm nhuận).

Input:
Có duy nhất một dòng ghi số ngảy, không quá 1000.

Output:
In kết quả trên một dòng theo thứ tự: năm – tuần – ngày, mỗi số cách nhau một
khoảng trống.

Ví dụ
Input:
350

Output:
0 50 0
*/

#include <stdio.h>

int main() {
	unsigned int n;
	scanf("%d", &n);
	printf("%d ", n / 365);
	printf("%d ", (n % 365) / 7);
	printf("%d\n", (n % 365) % 7);
	return 0;
}
