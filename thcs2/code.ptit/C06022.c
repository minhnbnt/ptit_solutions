/*
Cho trước một xâu ký tự S1 chỉ bao gồm các chữ cái và khoảng trống cùng một từ
S2. Hãy tìm xem S2 có xuất hiện trong S1 hay không. Nếu có loại bỏ tất cả những
lần xuất hiện của S2 trong S1. Chú ý: tìm S2 trong S1 theo kiểu không phân biệt
chữ hoa chữ thường

Input:  Dòng 1 ghi số bộ test. Mỗi bộ test ghi trên hai dòng: Dòng đầu ghi xâu
ký tự S1, độ dài không quá 200. Dòng thứ 2 ghi từ S2 (không quá 20 ký tự)

Output: Với mỗi bộ test ghi ra thứ tự bộ test và xâu kết quả sau khi đã xóa.

Ví dụ:

Input:
2
Abc ddd abdc aaa bbb abc ddD XY
aBc
ACHDNC XXXX YYYY ABC ABC XXXX
XxXx

Output:
Test 1: ddd abdc aaa bbb ddD XY
Test 2: ACHDNC YYYY ABC ABC
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strlwr(char *str) {
	char *a = malloc(strlen(str) + 1);
	strcpy(a, str);
	for (char *p = a; *p != '\0'; p++) //
		*p = tolower(*p);
	return a;
}

int main(int argc, char *argv[]) {
	unsigned test, i = 0;
	scanf("%u%*c", &test);
	while (i++ < test) {
		char str[200], a[50];
		fgets(str, 200, stdin), strtok(str, "\n");
		fgets(a, 50, stdin), strtok(a, "\n");
		char *p = strtok(str, " ");
		printf("Test %d: ", i);
		while (p != NULL) {
			if (strcmp(strlwr(p), strlwr(a))) {
				printf("%s ", p);
			}
			p = strtok(NULL, " ");
		}
		putchar('\n');
	}
	return 0;
}
