/*
Cho số nguyên dương n (2<=n<=10^9), hãy phân tích n ra thừa số nguyên tố.

Dữ liệu:
Một dòng duy nhất chứa số n.

Kết quả:
Mỗi dòng ghi một thừa số nguyên tố và số mũ tương ứng cách nhau bởi dấu cách.
Các thừa số nguyên tố in ra theo thứ tự tăng dần.

Ví dụ:
Input:
4

Output:
2 2
--------------
Input:
168

Output:
2 3
3 1
7 1
*/

#include <math.h>
#include <stdio.h>

int main(void) {

	unsigned long long n;
	scanf("%llu", &n);

	for (unsigned long i = 2; i <= sqrt(n); ++i) {

		unsigned count = 0;

		while (n % i == 0) {
			n /= i;
			++count;
		}

		if (count > 0) printf("%lu %u\n", i, count);
	}

	if (n > 1) printf("%llu 1\n", n);

	return 0;
}
