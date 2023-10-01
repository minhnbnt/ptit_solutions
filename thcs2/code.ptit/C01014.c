/*
Viết chương trình nhập 2 số thực a,b và in ra nghiệm của phương trình bậc nhất
a*x+b=0.

Input:
Chỉ có một dòng ghi hai số a,b.

Output:
Kết quả ghi ra trên một dòng tương ứng là “Vo nghiem”  “Vo so nghiem” hoặc
nghiệm dưới dạng số thực có đúng 2 chữ số sau dấu phẩy.

Ví dụ
Input       Output
2 -1        0.50
0 1         Vo nghiem
0 0         Vo so nghiem
*/

#include <stdio.h>

int main() {
	float a, b;
	scanf("%f %f", &a, &b);
	if (a != 0) printf("%.2f\n", -b / a);
	else if (b != 0) puts("Vo nghiem");
	else puts("Vo so nghiem");
	return 0;
}
