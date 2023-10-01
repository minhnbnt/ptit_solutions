/*
Cho 3 điểm A, B, C trong không gian 2 chiều Oxy, hãy tính diện tích tam giác
được tạo bởi 3 điểm đó.

Công thức Heron tính diện tích tam giác khi biết độ dài 3 cạnh là a,b,c:
S = sqrt(p*(p-a)*(p-b)*(p-c)) với p = (a+b+c)/2

Dữ liệu vào
Dòng đầu ghi số bộ test, không quá 10
Mỗi bộ test ghi trên 1 dòng 6 số thực có giá trị tuyệt đối không quá 1000 lần
lượt là tọa độ của 3 điểm A, B, C. Kết quả

Nếu 3 điểm không thể tạo thành tam giác thì in ra INVALID
Nếu 3 điểm tạo thành 1 tam giác thì in ra diện tích của tam giác đó, làm tròn
đến 2 chữ số phần thập phân.

Ví dụ
Input:
3
0 0 0 5 0 199
1 1 1 1 1 1
0 0 0 5 5 0

Output:
INVALID
INVALID
12.50
*/

#include <math.h>
#include <stdio.h>

int main(void) {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		double a[2], b[2], c[2];
		scanf("%lf %lf %lf %lf %lf %lf", //
		      &a[0], &a[1], &b[0], &b[1], &c[0], &c[1]);
		double ab = sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2)),
			   bc = sqrt(pow(b[0] - c[0], 2) + pow(b[1] - c[1], 2)),
			   ac = sqrt(pow(a[0] - c[0], 2) + pow(a[1] - c[1], 2));
		if (ab + bc > ac && ab + ac > bc && bc + ac > ab) {
			double p = (ab + bc + ac) / 2;
			printf("%.2lf\n", sqrt(p * (p - ab) * (p - bc) * (p - ac)));
		} else puts("INVALID");
	}
	return 0;
}
