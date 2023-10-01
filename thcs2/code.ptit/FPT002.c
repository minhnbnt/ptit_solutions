/*
Viết chương trình nhân ba ma trận A(mxn) với B(nxp) và C(pxq) để được D=AxBxC

In:
Hàng đầu là các giá trị m,n,p và q (các giá trị cách nhau bởi dấu cách
m hàng tiết theo là các phần tử của ma trận A
n hàng tiếp theo là các phần tử của ma trận B
p hàng tiếp theo là các phần tử của ma trận C

Out:
Ma trận kết quả D

Ví dụ:
In:
4 3 2 2

2 5 4
4 1 9
3 5 2
3 9 3

5 7
3 7
2 4

7 7
5 4

Out:
556 491
642 571
558 494
816 720
*/

#include <stdio.h>
#include <stdlib.h>

int **mul_matrix(int **mx1, int **mx2, //
                 unsigned a, unsigned b, unsigned c) {
	unsigned i, j, k;
	int **mx = (int **)malloc(sizeof(int *) * a);
	for (i = 0; i < a; i++) {
		mx[i] = (int *)calloc(c, sizeof(int));
		for (j = 0; j < c; j++)
			for (k = 0; k < b; k++) //
				mx[i][j] += mx1[i][k] * mx2[k][j];
	}
	return mx;
}

int **input_matrix(unsigned a, unsigned b) {
	unsigned i, j;
	int **mx = (int **)malloc(sizeof(int *) * a);
	for (i = 0; i < a; i++) {
		mx[i] = (int *)malloc(sizeof(int) * b);
		for (j = 0; j < b; j++) //
			scanf("%d", &mx[i][j]);
	}
	return mx;
}

void free_matrix(int **mx, unsigned a) {
	do free(mx[--a]);
	while (a != 0);
	free(mx);
}

int main(int argc, char *argv[]) {
	unsigned m, n, p, q, i, j;
	scanf("%u %u %u %u", &m, &n, &p, &q);
	int **mx1 = input_matrix(m, n), **tmp = mx1;
	int **mx2 = input_matrix(n, p);
	mx1 = mul_matrix(mx1, mx2, m, n, p);
	free_matrix(tmp, m), free_matrix(mx2, n);
	mx2 = input_matrix(p, q);
	mx1 = mul_matrix(mx1, mx2, m, p, q);
	free_matrix(mx2, p);
	for (i = 0; i < m; i++) {
		for (j = 0; j < p; j++) //
			printf("%d ", mx1[i][j]);
		putchar('\n');
	}
	free_matrix(mx1, m);
	return 0;
}
