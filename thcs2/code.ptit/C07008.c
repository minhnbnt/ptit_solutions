/*
Cho hai đa thức có bậc không quá 10000 (chỉ viết ra các phần tử có hệ số khác
0). Hãy tính tổng hai đa thức đó.

Input: Dòng đầu ghi số bộ test. Mỗi bộ test có hai dòng, mỗi dòng ghi một đa
thức theo mẫu như trong ví dụ. Chú ý: Bậc của các hạng tử luôn theo thứ tự giảm
dần, trong đa thức chỉ có phép cộng và luôn được viết đầy đủ hệ số + số mũ (kể
cả mũ 0).

Output: Ghi ra một dòng đa thức tổng tính được (theo mẫu như ví dụ)

Ví dụ:
Input:
1
3*x^8 + 7*x^2 + 4*x^0
11*x^6 + 9*x^2 + 2*x^1 + 3*x^0

Output:
3*x^8 + 11*x^6 + 16*x^2 + 2*x^1 + 7*x^0
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int multi;
	unsigned exp;
} poly;

int cmp(const void *a, const void *b) {
	poly *x = (poly *)a;
	poly *y = (poly *)b;
	return x->exp < y->exp;
}

int main(void) {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		poly *x = malloc(sizeof(poly));
		unsigned size = 0, i;
		while (1) {
			char c;
			int multi;
			unsigned exp;
			scanf("%d%*3s%u%c", &multi, &exp, &c);
			x = realloc(x, sizeof(poly) * (size + 1));
			x[size].multi = multi, x[size++].exp = exp;
			if (c != '\n') scanf("%*s");
			else break;
		}
		while (1) {
			char c, flag = 1;
			int multi;
			unsigned exp;
			scanf("%d%*3s%u%c", &multi, &exp, &c);
			for (i = 0; i < size; i++)
				if (x[i].exp == exp) {
					flag = 0;
					x[i].multi += multi;
				}
			if (flag) {
				x = realloc(x, sizeof(poly) * (size + 1));
				x[size].multi = multi, x[size++].exp = exp;
			}
			if (c != '\n') scanf("%*s");
			else break;
		}
		qsort(x, size, sizeof(poly), cmp);
		for (i = 0; i < size; i++) {
			printf("%d*x^%u", x[i].multi, x[i].exp);
			if (i != size - 1) {
				printf(" + ");
			} else putchar('\n');
		}
	}
	return 0;
}
