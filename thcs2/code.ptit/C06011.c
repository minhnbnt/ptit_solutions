/*
Một số được coi là đẹp nếu đó là số thuận nghịch, bắt đầu và kết thúc bằng chữ
số 8 và tổng chữ số chia hết cho 10. Viết chương trình đọc vào các số nguyên
dương có không quá 500 chữ số và kiếm tra xem số đó có đẹp hay không.

Input:
Dòng đầu tiên ghi số bộ test.

Mỗi bộ test viết trên một dòng số nguyên dương n không quá 500 chữ số.

Output:
Mỗi bộ test viết ra trên một dòng chữ YES nếu đó là số đẹp, chữ NO nếu ngược lại

Ví dụ
Input:
4
123456787654321
8644281154664511824468
8006000444400000000000044440006008
82123400000000000000000000000432128

Output:
NO
NO
YES
YES
*/

#include <stdio.h>
#include <string.h>

char beautyof(char *s) {
	int len = strlen(s), sum = 0;
	if (s[0] != '8' || s[len - 1] != '8') {
		return 0;
	}
	for (int i = 0; i < len; i++) {
		sum += s[i] - '0';
	}
	if (sum % 10) return 0;
	for (int i = 0; i < len / 2; i++)
		if (s[i] != s[len - i - 1]) return 0;
	return 1;
}

int main() {
	unsigned int n;
	scanf("%d%*c", &n);
	char num[500], result[n];
	for (int i = 0; i < n; i++) {
		scanf("%s", num);
		result[i] = beautyof(num);
	};
	for (int i = 0; i < n; i++) {
		puts(result[i] ? "YES" : "NO");
	}
	return 0;
}
