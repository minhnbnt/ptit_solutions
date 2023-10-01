/*
Cho một văn bản. Hãy tìm ra từ thỏa mãn tính chất thuận nghịch có độ dài lớn
nhất trong và cho biết từ đó xuất hiện bao nhiêu lần. Nếu có nhiều từ cùng có độ
dài lớn nhất thì in ra tất cả các từ đó theo thứ tự xuất hiện.

Input: Văn bản không quá 1000 từ.

Output:
Ghi ra trên một dòng từ thuận nghịch có độ dài lớn nhất và số lần xuất hiện của
nó. Nếu có nhiều từ cùng có độ dài lớn nhất thì các từ được liệt kê theo thứ tự
xuất hiện ban đầu.

Ví dụ:
Input:
AAA BAABA HDHDH ACBSD SRGTDH DDDDS
DUAHD AAA AD DA HDHDH AAA AAA AAA AAA
DDDAS HDHDH HDH AAA AAA AAA AAA AAA
AAA AAA AAA
DHKFKH DHDHDD HDHDHD DDDHHH HHHDDD
TDTD

Output:
HDHDH 3
*/

#include <stdio.h>
#include <string.h>

char unrevertable(char *str) {
	unsigned len = strlen(str), i;
	for (i = 0; i < len / 2; i++)
		if (str[i] != str[len - i - 1]) return 1;
	return 0;
}

int main(void) {
	unsigned max_len = 0, i, size = 0;
	char str[100], src[1000][100];
	unsigned a[1000];
	while (scanf("%s", str) != EOF) {
		if (unrevertable(str)) continue;
		unsigned len = strlen(str);
		if (len > max_len) {
			max_len = len, size = 0;
			strcpy(src[size], str), a[size++] = 1;
		} else if (len == max_len) {
			char flag = 1;
			for (i = 0; i < size; i++)
				if (strcmp(src[i], str) == 0) {
					++a[i], flag = 0;
					break;
				}
			if (flag) a[size] = 1;
			strcpy(src[size++], str);
		}
	}
	for (i = 0; i < size; i++) //
		printf("%s %u\n", src[i], a[i]);
	return 0;
}
