/*
Một số nguyên dương có N chữ số được gọi là SỐ VÒNG nếu khi ta nhân số đó lần
lượt với các số từ 1 đến N thì ta được một số thỏa mãn tính chất:

Nếu như chọn các chữ số từ một vị trí nào đó rồi vòng lại (đến trước chữ số đầu
tiên chọn) ta được số đã cho ban đầu.

Ví dụ: số 142857 là số vòng, vì:
142857 × 1 = 142857
142857 × 2 = 285714
142857 × 3 = 428571
142857 × 4 = 571428
142857 × 5 = 714285
142857 × 6 = 857142

Viết chương trình xác định xem một số có phải số vòng hay không.

Input
Dòng đầu ghi số bộ test. Không quá 20.
Mỗi bộ test trên một dòng số nguyên, có từ 2 đến 60 chữ số.

Chú ý: Có thể có các số 0 ở đầu, và không được xóa bỏ các số 0 này, nó là một
phần của số và  cũng được tính trong việc xác định độ dài của số.

Ví dụ: “01” là số có 2 chữ số, nó khác với “1” có 1 chữ số.

Output
Ghi ra YES hoặc NO

Ví dụ

Input:
5
142857
142856
142858
01
0588235294117647

Output:
YES
NO
NO
NO
YES
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strrev(char *str) {
	unsigned len = strlen(str), i;
	for (i = 0; i < len / 2; i++) {
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
	return str;
}

char *mul(const char *x, unsigned y) {
	char *rtn = (char *)malloc(sizeof(char));
	unsigned lenx = strlen(x), len = 0, add = 0;
	do {
		unsigned a = 0;
		if (lenx > 0) a += x[--lenx] - '0';
		a *= y, a += add, add = a / 10;
		rtn = (char *)realloc(rtn, ++len + 1);
		rtn[len - 1] = (a % 10) + '0';
	} while (add > 0 || lenx > 0);
	rtn[len] = 0, strrev(rtn);
	return rtn;
}

char loop_number(const char *x) {
	unsigned len = strlen(x), i, j;
	for (i = 2; i <= len; i++) {
		char *temp = mul(x, i);
		for (j = 0; j < len; j++) {
			char *p = strchr(temp, x[j]);
			if (p == NULL) return 0;
			else *p = 'x';
		}
		free(temp);
	}
	return 1;
}

int main(void) {
	unsigned n;
	scanf("%d%*c", &n);
	while (n--) {
		char *str = malloc(sizeof(char));
		unsigned len = 0;
		while (1) {
			char c = getchar();
			if (c == '\n' || c == EOF) break;
			else if (isdigit(c)) {
				str = (char *)realloc(str, ++len + 1);
				str[len - 1] = c;
			}
		}
		str[len] = 0;
		puts(loop_number(str) ? "YES" : "NO");
		free(str);
	};
	return 0;
}
