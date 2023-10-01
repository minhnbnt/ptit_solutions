/*
Cho hai số nguyên (có thể âm) có giá trị tuyệt đối không quá 106.

Viết chương trình tính tổng hai số

Input:
Có duy nhất một dòng ghi hai số nguyên, cách nhau một khoảng trống.

Output:
In kết quả trên một dòng

Ví dụ
Input:
10 2

Output:
12
*/

#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", a + b);
	return 0;
}
