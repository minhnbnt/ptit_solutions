/*
Viết chương trình cộng hai số nguyên dương bất kỳ (không quá 500 chữ số).

Input:
Dòng 1 ghi số bộ test. Mỗi bộ test gồm 2 dòng, mỗi dòng ghi một số nguyên
dương

Output:
Với mỗi bộ test ghi ra một số nguyên dương là tổng hai số đã cho (số này cũng
không quá 500 chữ số).

Ví dụ:
Input:
3
12
100
1212
8888
121212121212121212
45678978

Output:
112
10100
121212121257800190
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *add(char *a, char *b) {
	char *str = malloc(1);
	unsigned lena = strlen(a), lenb = strlen(b), len = 0;
	char add = 0;
	do {
		char x = 0;
		if (lena > 0) x += a[--lena] - '0';
		if (lenb > 0) x += b[--lenb] - '0';
		x += add, add = x / 10;
		str = realloc(str, sizeof(char) * ++len);
		str[len - 1] = (x % 10) + '0';
	} while (add > 0 || lena > 0 || lenb > 0);
	for (lena = 0; lena <= len / 2 - 1; lena++) {
		char temp = str[lena];
		str[lena] = str[len - lena - 1];
		str[len - lena - 1] = temp;
	}
	str[len] = 0;
	return str;
}

int main() {
	unsigned test;
	scanf("%u%*c", &test);
	while (test--) {
		char a[502] = { 0 }, b[502] = { 0 };
		scanf("%s", a);
		scanf("%s", b);
		puts(add(a, b));
	}
	return 0;
}
