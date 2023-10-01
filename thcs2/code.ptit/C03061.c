/*
Một số được coi là đẹp nếu chữ số đầu gấp đôi chữ số cuối hoặc ngược lại; đồng
thời các chữ số  từ vị trí thứ 2 đến gần cuối thỏa mãn là một số thuận nghịch.

Ví dụ: các số 36788766; 12345654322 là các số đẹp.

Viết chương trình kiểm tra số đẹp theo tiêu chí trên.

Input
Dòng đầu ghi số bộ test
Mỗi test là một số nguyên dương không quá 18 chữ số

Output
Ghi ra YES tương ứng với số đẹp, NO trong trường hợp ngược lại

Ví dụ:
Input:
3
36788766
22345654321
12345654321

Output:
YES
YES
NO
*/

#include <stdio.h>

char beautyOf(unsigned long long n) {
	char digit[50];
	unsigned size = 0, i;
	while (n > 0) {
		digit[size++] = n % 10;
		n /= 10;
	}
	for (i = 1; i < size / 2; i++)
		if (digit[i] != digit[size - i - 1]) return 0;
	if (digit[0] == digit[size - 1] * 2) return 1;
	return 2 * digit[0] == digit[size - 1];
}

int main(void) {
	unsigned test;
	scanf("%u%*c", &test);
	while (test--) {
		unsigned long long n;
		scanf("%llu", &n);
		puts(beautyOf(n) ? "YES" : "NO");
	}
	return 0;
}
