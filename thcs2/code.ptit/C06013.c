/*
Cho một số nguyên dương lớn có nhiều hơn 20 chữ số nhưng không quá 1000 chữ số.
Hãy kiểm tra xem số đó có đầy đủ tất cả các chữ số từ 0 đến 9 hay không.

Dữ liệu vào
Dòng đầu ghi số bộ test, không quá 10
Mỗi bộ test là một dãy ký tự có độ dài không quá 1000, không có khoảng trống

Kết quả
Nếu dữ liệu vào không phải là một số nguyên hợp lệ (có ký tự không phải số hoặc
bắt đầu bằng chữ số 0) thì in ra INVALID Nếu dữ liệu vào thỏa mãn đầy đủ thì in
ra YES, nếu không in ra NO

Ví dụ
Input:
3
01234aa32432432432534545b987978
123444444444444566666666667890
324562783924723543243243242354354354333234324

Output:
INVALID
YES
NO
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

char fullNum(const char *str) {
	if (*str == '0') return -1;
	char *p, a[] = "1234567890";
	for (p = (char *)str; *p != '\n'; p++)
		if (isdigit(*p)) {
			char *q = strchr(a, *p);
			if (q != NULL) *q = ' ';
		} else return -1;
	for (p = a; *p != '\0'; p++)
		if (*p != ' ') return 0;
	return 1;
}

int main(int argc, char *argv[]) {
	unsigned test;
	scanf("%u%*c", &test);
	while (test--) {
		char str[1000];
		fgets(str, 1000, stdin);
		char result = fullNum(str);
		if (result == 1) puts("YES");
		else if (result == 0) puts("NO");
		else puts("INVALID");
	}
	return 0;
}
