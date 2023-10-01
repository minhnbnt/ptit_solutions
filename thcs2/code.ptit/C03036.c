/*
Viết chương trình kiểm tra các số N thỏa mãn cả ba điều kiện:

N là số thuận nghịch
Tất cả các chữ số của N đều là số lẻ
Tổng chữ số của N cũng là một số lẻ

Input
Dòng đầu ghi số bộ test
Mỗi bộ test ghi số N không quá 18 chữ số

Output
Với mỗi bộ test, ghi ra YES hoặc NO trên một dòng.
Ví dụ:

Input:
2
131
3779

Output:
YES
NO
*/

#include <stdio.h>

char beautyOf(unsigned long long n) {
	char digit[50];
	unsigned size = 0, sum = 0, i;
	while (n > 0) {
		digit[size++] = n % 10;
		sum += n % 10;
		if (n % 2 == 0) return 0;
		n /= 10;
	}
	for (i = 0; i < size / 2; i++)
		if (digit[i] != digit[size - i - 1]) return 0;
	return sum % 2;
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
