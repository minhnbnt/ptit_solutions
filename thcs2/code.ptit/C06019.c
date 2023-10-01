/*
Địa chỉ email của cán bộ PTIT được cấp theo nguyên tắc ghép tên với chữ cái đầu
tiên của họ và tên đệm. Viết chương trình cho phép tạo các địa chỉ email theo
tên cán bộ(có thể không chuẩn).

Input:
Chỉ có một dòng ghi xâu họ tên (độ dài không quá 50)

Output:
Ghi ra kết quả.

Ví dụ:
Input:
ngUYEN van nam

Output:
nvnam@ptit.edu.vn
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100];
	fgets(str, 100, stdin);
	strtok(str, "\n");
	char *p = strtok(str, " "), *q;
	while (1) {
		q = p;
		p = strtok(NULL, " ");
		if (p == NULL) break;
		putchar(tolower(*q));
	}
	for (p = q; *p != '\0'; p++) {
		putchar(tolower(*p));
	}
	puts("@ptit.edu.vn");
	return 0;
}
