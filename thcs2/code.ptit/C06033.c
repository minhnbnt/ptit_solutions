/*
Cho hai xâu ký tự S1 và S2 với độ dài N và chỉ chứa các ký tự từ A đến H. Chúng
ta thực hiện thao tác như sau:

Bước đầu tiên tạo S12 bằng cách lấy các ký tự lần lượt trong S1 và S2 từ trái
sang phải, lấy một ký tự trong S2 trước, sau đó đến 1 ký tự trong S1 và cứ như
vậy. Ví dụ S1 =  ABCHAD, S2= DEFDAC thì S12 = DAEBFCDHAACD Sau đó ta lại lấy nữa
bên trái của S12 thành S1 mới, nửa bên phải thành S2 mới. Trong ví dụ trên S1
mới là DAEBFC, S2 mới là DHAACD. Rồi lại tiếp tục như vậy trong các bước tiếp
theo. Cho trước một xâu S có độ dài 2*N. Bài toán đặt ra là liệu có thể tạo ra
xâu S sau một số lần lặp hay không.

Dữ liệu vào
Có nhiều bộ test, mỗi bộ test có bốn dòng. Dòng đầu ghi số N không quá 200. Dòng
thứ 2 ghi S1, dòng thứ 3 ghi S2. Dòng cuối ghi xâu S. Input kết thúc với một
dòng ghi số 0.

Kết quả
Ghi ra số bước lặp cần thiết. Nếu không thể tìm được thì ghi ra -1.

Ví dụ
Input:
4
AHAH
HAHA
HHAAAAHH
3
CDE
CDE
EEDDCC

Output:
0
2
-1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mix(const char *str1, const char *str2) {
	unsigned len1 = strlen(str1), len2 = strlen(str2);
	unsigned len = len1 + len2, i = 0;
	char *str = malloc(len + 5);
	do
		if (i % 2) str[i] = *str1++;
		else str[i] = *str2++;
	while (++i < len);
	str[len] = 0;
	return str;
}

void split(char *str, char *str1, char *str2) {
	unsigned k = strlen(str) / 2;
	strncpy(str1, str, k), strcpy(str2, str + k);
}

void getstr(char *str, unsigned len) {
	fgets(str, len + 5, stdin);
	strtok(str, "\n");
}

int execute(unsigned len) {
	char *tmp1 = malloc(len + 5), *tmp2 = malloc(len + 5);
	char *str1 = malloc(len + 5), *str2 = malloc(len + 5);
	char *res = malloc(len * 2 + 5);
	getstr(str1, len), getstr(str2, len), getstr(res, len * 2);
	strcpy(tmp1, str1), strcpy(tmp2, str2);
	tmp1[len] = tmp2[len] = 0;
	int count = 0;
	while (++count) {
		char *str = mix(str1, str2);
		if (!strcmp(str, res)) break;
		split(str, str1, str2), free(str);
		if (!strcmp(str1, tmp1) && !strcmp(str2, tmp2)) {
			count = -1;
			break;
		}
	}
	free(str1), free(str2), free(res);
	free(tmp1), free(tmp2);
	return count;
}

int main(void) {
	while (1) {
		unsigned len;
		scanf("%u%*c", &len);
		if (len == 0) break;
		printf("%d\n", execute(len));
	}
	return 0;
}
