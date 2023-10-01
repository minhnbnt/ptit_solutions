/*
Viết chương trình liệt kê N số nguyên tố đầu tiên với N là một số nguyên dương
không quá 105.

Input
Dữ liệu vào chỉ có duy nhất một số N.

Output
Kết quả ghi mỗi số nguyên tố trên một dòng, theo thứ tự từ nhỏ đến lớn.

Ví dụ:
Input:
5

Output:
2
3
5
7
11
*/

// recursive function only

#include <stdio.h>

char prime(unsigned long n, unsigned i) {
	if (i * i > n) return n > 1;
	else if (n % i == 0) return 0;
	return prime(n, i + 1);
}

void execute(unsigned n, unsigned long a) {
	if (prime(a, 2)) printf("%lu\n", a), --n;
	if (n > 0) execute(n, a + 1);
}

int main(void) {
	unsigned n;
	scanf("%u", &n);
	execute(n, 0);
	return 0;
}
