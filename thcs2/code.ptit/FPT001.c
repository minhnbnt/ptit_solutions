/*
Viết chương trình tạo một ma trận vuông kích thước nxn (n nhập từ bàn phím,
n>0). Cấu trúc của ma trận với hàng đầu là các phần tử từ 0-> n-1 Hàng tiếp theo
sẽ thêm một phần tử 0 ở đầu, và phần còn lại từ 9->n-2 Tương tự cho đến hàng
cuối sẽ chỉ gồm các phần tử 0

In: Giá trị n
Out:
Ma trận kết quả gồm n hàng, mỗi phần tử trên một hàng cách nhau dấu cách

Ví dụ:
In:
4

Out:
0 1 2 3
0 0 1 2
0 0 0 1
0 0 0 0
*/

#include <stdio.h>

int main(void) {
	unsigned n, i, j;
	scanf("%u", &n);
	for (i = 0; i < n; i++) {
		unsigned k = 0;
		for (j = 0; j < n; j++) {
			if (j > i) ++k;
			printf("%u ", k);
		}
		putchar('\n');
	}
	return 0;
}
