/*
Các cán bộ, giảng viên PTIT khi tham gia hội nghị quốc tế sẽ được viết lại xâu
họ tên theo dạng chuẩn trong đó họ được viết sau cùng, phân tách với phần tên
đệm và tên bởi dấu phẩy. Các chữ cái của họ đều viết hoa.

Cho trước các xâu họ tên (có thể không chuẩn). Hãy đưa về dạng chuẩn tương ứng.

Input:
Dòng 1 ghi số N là xâu họ tên trong danh sách
N dòng tiếp theo ghi lần lượt các xâu họ tên (không quá 50 ký tự)

Output: Ghi ra các xâu chuẩn.

Ví dụ:
Input
4
    nGUYEn    quaNG   vInH
   tRan   thi THU    huOnG
   nGO   quoC  VINH
 lE            tuAn    aNH

Output:
Quang Vinh, NGUYEN
Thi Thu Huong, TRAN
Quoc Vinh, NGO
Tuan Anh, LE
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

char *strupr(char *str) {
	char *p = str;
	while (*p != '\0') //
		*p = toupper(*p), p++;
	return str;
}

char *strproper(char *str) {
	char *p = str;
	*p = toupper(*p);
	while (*(++p) != '\0') //
		*p = tolower(*p);
	return str;
}

int main(void) {
	unsigned test;
	scanf("%u%*c", &test);
	while (test--) {
		char str[100];
		fgets(str, 100, stdin);
		strtok(str, "\n");
		char *q = strtok(str, " ");
		char *p = strtok(NULL, " ");
		while (p != NULL) {
			puts(strproper(p));
			p = strtok(NULL, " ");
			if (p != NULL) putchar(' ');
		}
		printf(", %s\n", strupr(q));
	}
	return 0;
}
