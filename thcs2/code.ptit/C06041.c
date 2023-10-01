/*
Xâu con của một xâu ký tự S được tạo ra bằng cách lấy một hoặc nhiều ký tự trong
S và giữ nguyên thứ tự ban đầu.

Cho xâu S chỉ bao gồm các chữ cái viết thường. Hãy in ra xâu con có thứ tự từ
điển là lớn nhất.

Input
Chỉ có xâu ký tự S, độ dài không quá 100000. Không có khoảng trống.

Output
Ghi ra xâu con có thứ tự từ điển lớn nhất.

Ví dụ
Input:                Output:
ababba                bbba
abbcbccacbbcbaaba     cccccbba
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) { //
	return *(char *)a < *(char *)b;
}

int main() {
	char str[100000] = { 0 };
	scanf("%[^\n]", str);
	int len = strlen(str), i, j, chars = 0;
	char allchar[len];
	for (i = 0; i < len; i++) {
		j = -1;
		while (j < chars)
			if (str[i] == allchar[++j]) break;
		if (j == chars) {
			allchar[chars++] = str[i];
		};
	};
	qsort(allchar, chars, sizeof(char), cmp);
	int index = 0;
	for (i = 0; i < chars; i++)
		for (j = index; j < len; j++)
			if (allchar[i] == str[j]) {
				putchar(str[j]);
				index = j;
			};
	printf("\n");
	return 0;
}
