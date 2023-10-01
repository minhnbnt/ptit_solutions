/*
Viết chương trình kiểm tra một số có thỏa mãn tính chất tổng chữ số của nó chia
hết cho 10 hay không.

Input
Dòng đầu tiên ghi số bộ test. Mỗi bộ test viết trên một dòng một số nguyên
dương, ít nhất 2 chữ số nhưng không quá 9 chữ số.

Output
Mỗi bộ test viết ra YES hoặc NO tùy thuộc kết quả kiểm tra.

Ví dụ:
Input:
3
3333
555555
123455

Output:
NO
YES
YES
*/

// recursive function only :D

#include <stdio.h>

int sum_of_digits(long n) {
	if (n == 0) return 0;
	return (n % 10) + sum_of_digits(n / 10);
}

void execute(unsigned test) {
	long n;
	scanf("%ld", &n);
	if (sum_of_digits(n) % 10) puts("NO");
	else puts("YES");
	if (--test) execute(test);
}

int main(void) {
	unsigned test;
	scanf("%u", &test);
	execute(test);
	return 0;
}
