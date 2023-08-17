/*
Cho số tự nhiên N. Nhiệm vụ của bạn là hãy kiểm tra N có phải là số Smith hay
không. Một số được gọi là số Smith nếu N không phải là số nguyên tố và có tổng
các chữ số của N bằng tổng các chữ số của các ước số nguyên tố của N. Ví dụ N =
666 có các ước số nguyên tố là 2, 3, 3, 37 có tổng các chữ số là 18.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số nguyên N.
T, N thỏa mãn ràng buộc 1≤T≤100; 1≤N≤100000.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
4
666

Output:
YES
YES
*/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define u64 unsigned long long

unsigned sum_of_digits(u64 x) {
	unsigned sum = 0;
	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

bool is_smith(u64 x) {

	bool is_prime = true;
	int tmp = sum_of_digits(x);

	for (u64 i = 2; i <= sqrt(x); ++i) {
		unsigned count = 0;
		while (x % i == 0) {
			is_prime = false;
			x /= i;
			++count;
		}
		if (count > 0) {
			tmp -= sum_of_digits(i) * count;
			if (tmp < 0) return false;
		}
	}
	if (x > 1) tmp -= sum_of_digits(x);
	return tmp == 0 && !is_prime;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {
		u64 x;
		scanf("%llu", &x);

		puts(is_smith(x) ? "YES" : "NO");
	}

	return 0;
}
