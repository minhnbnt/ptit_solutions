/*
Hệ cơ số 3 chỉ biểu diễn các số sử dụng ba chữ số là 0, 1, 2.

Nhập vào dãy biểu diễn không quá 18 ký tự, hãy kiểm tra xem dãy biểu diễn nào là
đúng với hệ cơ số 3.

Input
Dòng đầu là số bộ test, mỗi dòng tiếp theo ghi một dãy biểu diễn cần kiểm tra.

Output
Nếu đúng in ra YES, nếu sai in ra NO.

Ví dụ:
Input:
3
1214AB
10210221
22222222

Output:
NO
YES
YES
*/

#include <stdio.h>
#include <string.h>

char check(char *str) {
	char *tri = "012", *p;
	for (p = str; *p != '\n'; p++)
		if (strchr(tri, *p) == NULL) return 0;
	return 1;
}

int main(void) {
	unsigned test;
	scanf("%u%*c", &test);
	while (test--) {
		char str[1000] = { 0 };
		fgets(str, 1000, stdin);
		puts(check(str) ? "YES" : "NO");
	}
	return 0;
}
