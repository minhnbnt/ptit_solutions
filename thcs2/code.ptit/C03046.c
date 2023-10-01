/*
Nam rất ghét chữ số 4 nên không muốn xuất hiện chữ số 4 trong các số may mắn của
mình. Dãy số may mắn của Nam có N chữ số và phải thỏa mãn tính chất thuận
nghịch, tổng chữ số phải chia hết cho 10.

Cho số N, hãy liệt kê các số may mắn của Nam với đúng N chữ số.

Input:
Dòng đầu ghi số bộ test
Mỗi bộ test ghi số N (1<N<7)

Output:
Với mỗi bộ test, ghi ra lần lượt các số may mắn có N chữ số, các số cách nhau
một khoảng trống. Hết một bộ test thì xuống dòng.

Ví dụ:
Input:
2
2
3

Output:
55
181 262 505 686 767 929
*/

#include <math.h>
#include <stdio.h>

unsigned sum_of_digits(unsigned long long n) {
	if (n < 10) return n;
	return n % 10 + sum_of_digits(n / 10);
}

char lucky_number(unsigned long long num) {
	if (sum_of_digits(num) % 10) return 0;
	char digit[30];
	unsigned size = 0, i;
	while (num > 0) {
		digit[size] = num % 10;
		if (digit[size++] == 4) return 0;
		num /= 10;
	}
	for (i = 0; i < size / 2; i++)
		if (digit[i] != digit[size - i - 1]) return 0;
	return 1;
}

int main(void) {
	unsigned test_case;
	scanf("%u", &test_case);
	while (test_case--) {
		unsigned digits;
		scanf("%u", &digits);
		unsigned long long start = pow(10, digits - 1),
						   end = pow(10, digits) - 1, i;
		for (i = start; i <= end; i++)
			if (lucky_number(i)) printf("%llu ", i);
		putchar('\n');
	}
	return 0;
}
