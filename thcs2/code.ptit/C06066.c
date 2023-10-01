/*
Cho một số nguyên dương không quá 200 chữ số. Mỗi bước tách số nguyên thành hai
nửa: nửa đầu là n/2 chữ số đầu tiên, nửa sau là phần còn lại (trong đó n là số
chữ số của số ban đầu, nếu n lẻ thì phép chia 2 sẽ tính phần nguyên). Sau đó
thực hiện tính tổng của hai nửa này.

Lặp lại các bước trên cho đến khi kết quả chỉ còn là số có 1 chữ số.

Hãy thực hiện tính toán và in kết quả của từng bước.

Input
Chỉ có một số nguyên dương không quá 200 chữ số.

Output
Ghi ra kết quả từng bước, mỗi bước trên một dòng. Dừng lại khi kết quả chỉ còn 1
chữ số.

Ví dụ:
Input:
123456

Ouput:
579
84
12
3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *add(const char *str1, const char *str2) {
	char *result = malloc(1), add = 0;
	unsigned len1 = strlen(str1), len2 = strlen(str2), len = 0;
	do {
		char x = 0;
		if (len1 > 0) x += str1[--len1] - '0';
		if (len2 > 0) x += str2[--len2] - '0';
		x += add, add = x / 10;
		result = realloc(result, ++len + 1);
		result[len - 1] = x % 10 + '0';
	} while (len1 || len2 || add);
	for (unsigned i = 0; i < len / 2; i++) {
		char tmp = result[i];
		result[i] = result[len - i - 1];
		result[len - i - 1] = tmp;
	}
	result[len] = '\0';
	return result;
}

char *result(const char *str) {
	unsigned i, len = strlen(str), len1 = len / 2;
	char *str1 = malloc(len1 + 1), *str2 = (char *)&str[len1];
	strncpy(str1, str, len1), str1[len1] = '\0';
	return add(str1, str2);
}

int main(void) {
	char *str = malloc(1), c;
	unsigned len = 0;
	while (1) {
		scanf("%c", &c);
		if (c == '\n') break;
		str = realloc(str, ++len + 1);
		str[len - 1] = c;
	}
	str[len] = '\0';
	char *print = result(str), *tmp = print;
	free(str);
	while (1) {
		puts(print), tmp = print;
		if (strlen(print) == 1) break;
		print = result(print);
		free(tmp);
	}
	return 0;
}
