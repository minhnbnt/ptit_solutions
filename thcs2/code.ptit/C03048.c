/*
Một số được gọi là số ưu thế chẵn nếu nó là số chẵn và số chữ số chẵn nhiều hơn
số chữ số lẻ. Hãy viết chương trình kiểm tra một số có phải ưu thế chẵn hay
không.

Input
Dòng đầu ghi số bộ test
Mỗi dòng tiếp theo ghi một số nguyên dương không quá 18 chữ số

Output
Ghi ra YES hoặc NO tùy thuộc kết quả kiểm tra

Ví dụ:
Input:
2
12345
22566678800

Output:
NO
YES
*/

#include <stdio.h>

char more_even(unsigned long long a) {
	if (a % 2 == 0) {
		char odd = 0, even = 0;
		while (a) {
			char c = a % 10;
			if (c % 2) odd++;
			else even++;
			a /= 10;
		}
		return even > odd;
	}
	return 0;
}

int main() {
	unsigned n;
	scanf("%u", &n);
	unsigned long long a;
	while (n--) {
		scanf("%llu", &a);
		puts(more_even(a) ? "YES" : "NO");
	}
	return 0;
}
