/*
Một số được coi là đẹp nếu đó là số thuận nghịch và chỉ toàn các chữ số chẵn.
Viết chương trình đọc vào các số nguyên dương có không quá 500 chữ số và kiếm
tra xem số đó có đẹp hay không.

Input:
Dòng đầu tiên ghi số bộ test.

Mỗi bộ test viết trên một dòng số nguyên dương n không quá 500 chữ số.

Output:
Mỗi bộ test viết ra trên một dòng chữ YES nếu đó là số đẹp, chữ NO nếu ngược lại

Ví dụ
Input:
4
123456787654321
86442824468
8006000444422220000222244440006008
235365789787654324567856578654356786556

Output:
NO
YES
YES
NO
*/

#include <stdio.h>
#include <string.h>

char beautyof(char *num) {
	int len = strlen(num), i;
	for (i = 0; i < len / 2 + 1; i++)
		if (num[i] % 2 || num[i] != num[len - i - 1]) return 0;
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
	for (int i = 0; i < n; i++) //
		puts(result[i] ? "YES" : "NO");
	return 0;
}
