/*
Viết chương trình kiểm tra một số nguyên dương có phải số nguyên tố hay không.

Input
Dòng đầu của dữ liệu vào ghi số bộ test. Mỗi dòng tiếp theo có một nguyên dương
không quá 9 chữ số.

Output
Kết quả in ra YES nếu đó là số nguyên tố, in ra NO nếu ngược lại.

Ví dụ:
Input:
3
123456
997
111111111

Output:
NO
YES
NO
*/

#include <math.h>
#include <stdio.h>

char prime(long x) {
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0) return 0;
	return x > 1;
}

int main() {
	unsigned n;
	scanf("%u", &n);
	while (n--) {
		long x;
		scanf("%ld", &x);
		puts(prime(x) ? "YES" : "NO");
	}
	return 0;
}
