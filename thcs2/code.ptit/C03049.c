/*
Một số được gọi là số ưu thế lẽ nếu nó là số lẻ và số chữ số lẻ nhiều hơn số chữ
số chẵn. Hãy viết chương trình kiểm tra một số có phải ưu thế lẻ hay không.

Input
Dòng đầu ghi số bộ test
Mỗi dòng tiếp theo ghi một số nguyên dương không quá 18 chữ số

Output
Ghi ra YES hoặc NO tùy thuộc kết quả kiểm tra

Ví dụ:
Input:
2
12345
22566678801

Output:
YES
NO
*/

#include <stdio.h>

char more_odd(unsigned long long a) {
	if (a % 2) {
		char odd = 0, even = 0;
		while (a) {
			char c = a % 10;
			if (c % 2) odd++;
			else even++;
			a /= 10;
		}
		return odd > even;
	}
	return 0;
}

int main() {
	unsigned n;
	scanf("%u", &n);
	unsigned long long a;
	while (n--) {
		scanf("%llu", &a);
		puts(more_odd(a) ? "YES" : "NO");
	}
	return 0;
}
