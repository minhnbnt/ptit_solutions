/*
Cho xâu ký tự S có độ dài không quá 100. Hãy loại bỏ các từ trùng nhau trong
xâu.

Input:
Chỉ có một dòng ghi xâu S.

Output:
Ghi ra kết quả sau khi loại các từ trùng nhau.

Ví dụ:

Input:
mon thcs2 hoc la mon 2tc hoc

Output:
mon thcs2 hoc la 2tc
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char str[100];
	fgets(str, 100, stdin);
	str[strlen(str) - 1] = 0;
	char words[20][50] = { { 0 } };
	unsigned size = 0, i;
	char *p = strtok(str, " ");
	while (p != NULL) {
		char flag = 1;
		unsigned len = strlen(p);
		for (i = 0; i < size; i++)
			if (!strcmp(p, words[i])) {
				flag = 0;
				break;
			}
		if (flag) {
			printf("%s ", p);
			strcpy(words[size++], p);
		}
		p = strtok(NULL, " ");
	}
	putchar('\n');
	return 0;
}
