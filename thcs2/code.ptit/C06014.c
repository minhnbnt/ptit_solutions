/*
Một xâu họ tên được coi là viết chuẩn nếu chữ cái đầu tiên mỗi từ được viết hoa,
các chữ cái khác viết thường. Các từ cách nhau đúng một dấu cách và không có
khoảng trống thừa ở đầu và cuối xâu. Hãy viết chương trình đưa các xâu họ tên về
dạng chuẩn.

Input:
Dòng 1 ghi số bộ test. Mỗi bộ test ghi trên một dòng xâu ký tự họ tên, không quá
80 ký tự.

Output:
Với mỗi bộ test ghi ra xâu ký tự họ tên đã chuẩn hóa.
Ví dụ:

Input:
3
   nGuYEN    vAN    naM
tRan           TRUNG hiEU
      vO le         hOA bINh

Output:
Nguyen Van Nam
Tran Trung Hieu
Vo Le Hoa Binh
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	unsigned test;
	scanf("%u%*c", &test);
	while (test--) {
		char str[100];
		fgets(str, 100, stdin);
		char *p = strtok(str, " ");
		while (1) {
			putchar(toupper(*(p++)));
			while (*p != '\0') putchar(tolower(*(p++)));
			p = strtok(NULL, " ");
			if (p == NULL) break;
			putchar(' ');
		}
	}
	return 0;
}
