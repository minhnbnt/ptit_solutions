/*
Cho trước một xâu S.  Bạn hãy thay đổi đúng 1 kí tự, sao cho xâu mới thu được là
một xâu đối xứng.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤  20). Mỗi test ghi trên một dòng
1 xâu S có độ dài không quá 20 kí tự.

Output: Với mỗi test, in ra “YES” nếu có thể biến đổi xâu S thành xâu đối xứng,
in ra “NO” trong trường hợp ngược lại.

Ví dụ:
Input:
3
abccaa
abbcca
abcda

Output:
YES
NO
YES
*/

#include <stdio.h>
#include <string.h>

char revertable(char *str) {
	unsigned len = strlen(str), i, count = 0;
	for (i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]) count++;
	}
	if (len % 2 && count < 2) return 1;
	else if (len % 2 == 0 && count == 1) return 1;
	return 0;
}

int main(void) {
	unsigned test;
	scanf("%u%*c", &test);
	while (test--) {
		char str[20];
		fgets(str, 20, stdin);
		strtok(str, "\n");
		puts(revertable(str) ? "YES" : "NO");
	}
	return 0;
}
