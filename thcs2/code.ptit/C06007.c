/*
Cho xâu ký tự S1 và một từ S2. Viết chương trình loại bỏ tất cả các từ S2 xuất
hiện trong S1

Input:
Dòng đầu ghi xâu S1 (độ dài không quá 100).
Dòng thứ 2 ghi từ S2.

Output:
Ghi ra xâu S1 sau khi đã loại bỏ các từ S2.

Ví dụ:
Input:
mon thcs2 la mon 2tc
mon

Output:
thcs2 la 2tc
*/

#include <stdio.h>
#include <string.h>

char *find_and_replace(char *str, const char *find, const char *replace) {
	int lenf = strlen(find), lenr = strlen(replace);
	char *p = strstr(str, find);
	while (p != NULL) {
		memmove(p + lenr, p + lenf, strlen(p + lenf) + 1);
		memmove(p, replace, lenr);
		p = strstr(p + lenr, find);
	}
	return str;
}

int main() {
	char str[5000], find[200];
	fgets(str, 5000, stdin);
	fgets(find, 200, stdin);
	find[strlen(find) - 1] = 0;
	printf("%s", find_and_replace(str, find, ""));
	return 0;
}
