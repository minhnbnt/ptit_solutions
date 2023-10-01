/*
Cho ba hình chữ nhật. Các bạn được phép xoay hình nhưng không được phép xếp
chồng lấn lên nhau, hỏi 3 hình chữ nhật đó có thể ghép thành một hình vuông được
hay không

Input:
Có ba dòng, mỗi dòng ghi hai số nguyên dương là chiều rộng và chiều cao của hình
chữ nhật (các số đều không quá 100).

Output:
Ghi ra YES nếu có thể tạo thành hình vuông, NO nếu không thể.

Ví dụ:
Input:
8 2
1 6
7 6

Output:
YES
*/

#include <math.h>
#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a[3][2], i, j, area = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			scanf("%d", &a[i][j]);
		}
		area += a[i][0] * a[i][1];
	}
	int edge = sqrt(area);
	if (edge * edge == area) {
		for (i = 0; i < 3; i++)
			if (a[i][0] < a[i][1]) //
				swap(&a[i][0], &a[i][1]);
		for (i = 0; i < 3; i++)
			for (j = i + 1; j < 3; j++)
				if (a[i][0] < a[j][0]) {
					swap(&a[i][0], &a[j][0]);
					swap(&a[i][1], &a[j][1]);
				}
		if (a[0][0] == edge) {
			if (a[1][0] == edge && a[2][0] == edge) {
				if (a[1][1] + a[2][1] + a[0][1] == edge) area = 0;
			} else {
				i = j = 0;
				while (i < 2) {
					if (a[1][i] + a[2][j] == edge) break;
					if (++j == 2) ++i, j = 0;
				}
				if (a[1][1 - i] + a[0][1] == edge && //
				    a[1][1 - i] == a[2][1 - j])
					area = 0;
			}
		}
	}
	puts(area ? "NO" : "YES");
	return 0;
}
