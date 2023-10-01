/*
Một số được gọi là số nguyên tố nếu nó chỉ có 2 ước là 1 và chính nó. Số 0 và 1
không được coi là số nguyên tố. Yêu cầu: Cho số n, hãy kiểm tra xem n có là số
nguyên tố hay không.

Dữ liệu:
Một dòng duy nhất chứa số n (0<=n<=10^9)

Kết quả:
In ra “YES” nếu n là số nguyên tố, và “NO” trong trường hợp còn lại.

Input        Output
2            YES
4            NO
*/

#include <math.h>
#include <stdio.h>

#define u64 unsigned long long

char is_prime(u64 n) {

	for (unsigned long i = 2; i <= sqrt(n); ++i)
		if (n % i == 0) return 0;

	return n > 1;
}

int main(void) {

	u64 n;
	scanf("%llu", &n);

	puts(is_prime(n) ? "YES" : "NO");

	return 0;
}
