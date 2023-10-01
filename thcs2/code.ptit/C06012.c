/*
Một số được coi là đẹp nếu đó là số thuận nghịch và chỉ toàn các chữ số nguyên
tố. Viết chương trình đọc vào các số nguyên dương có không quá 500 chữ số và
kiếm tra xem số đó có đẹp hay không.

Input:
Dòng đầu tiên ghi số bộ test.
Mỗi bộ test viết trên một dòng số nguyên dương n không quá 500 chữ số.

Output:
Mỗi bộ test viết ra trên một dòng chữ YES nếu đó là số đẹp, chữ NO
nếu ngược lại

Ví dụ
Input:
3
123456787654321
235755557532
2222333355557777235775327777555533332222

Output:
NO
YES
YES
*/

#include <stdio.h>
#include <string.h>

char beautyof(char *x) {
	char *num = "2357";
	int len = strlen(x);
	for (int i = 0; i <= len / 2; i++)
		if (strchr(num, x[i]) == NULL || //
		    x[i] - x[len - i - 1])
			return 0;
	return 1;
}

int main() {
	unsigned int n;
	scanf("%d%*c", &n);
	char num[500], result[n];
	for (int i = 0; i < n; i++) {
		scanf("%499[^\n]%*c", num);
		result[i] = beautyof(num);
	};
	for (int i = 0; i < n; i++) //
		puts(result[i] ? "YES" : "NO");
	return 0;
}
