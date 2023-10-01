/*
Viết chương trình nhập vào một xâu ký tự S, thực hiện phân tích xâu đã nhập chứa
bao nhiêu chữ cái, chữ số và các ký tự khác.


Input:
Chỉ có một dòng ghi xâu S.

Output:
Ghi ra kết quả theo mẫu trong ví dụ: số chữ cái, số chữ số, số các ký tự khác.

Ví dụ:
Input:
mon thcs mon THCS 2 ...

Output:
14 1 8
*/

#include <ctype.h>
#include <stdio.h>

int main() {
	unsigned a = 0, d = 0, o = 0;
	char c;
	do {
		scanf("%c", &c);
		if (isalpha(c)) a++;
		else if (isdigit(c)) d++;
		else if (c != '\n') o++;
	} while (c != '\n');
	printf("%d %d %d\n", a, d, o);
	return 0;
}
