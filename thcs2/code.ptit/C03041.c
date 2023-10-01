/*
Cho 2 đỉnh là góc dưới bên trái và góc trên bên phải của hình chữ nhật trong hệ
tọa độ Oxy. Hãy kiểm tra xem đó có phải là hình vuông hay không.

Input:
Dòng đầu ghi số bộ test

Mỗi test có 4 số nguyên a,b,c,d.

Trong đó (a,b) là tọa độ điểm góc dưới bên trái, (c,d) là tọa độ góc trên bên
phải (-1000 <a<c<1000; -1000<b<d<1000)

(a luôn nhỏ hơn c; b luôn nhỏ hơn d).

Output:
Ghi ra YES hoặc NO tương ứng với kết quả kiểm tra

Ví dụ
Input:
2
1 1 3 3
1 2 3 7

Output:
YES
NO
*/

#include <stdio.h>

int main() {
	unsigned int n;
	scanf("%d", &n);
	int x[n][2], y[n][2];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++) {
			scanf("%d %d", &x[i][j], &y[i][j]);
		}
	for (int i = 0; i < n; i++)
		if (x[i][0] - x[i][1] == y[i][0] - y[i][1]) {
			puts("YES");
		} else puts("NO");
	return 0;
}
