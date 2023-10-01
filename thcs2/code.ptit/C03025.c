/*
Một số được coi là thuần nguyên tố nếu nó là số nguyên tố, tất cả các chữ số là
nguyên tố và tổng chữ số của nó cũng là một số nguyên tố.
Bài toán đặt ra là đếm xem trong một đoạn giữa hai số nguyên cho trước có bao
nhiêu số thuần nguyên tố.

Input: Dòng đầu tiên ghi số bộ test. Mỗi bộ test viết trên một dòng hai số
nguyên dương tương ứng, cách nhau một khoảng trống. Các số đều không vượt quá 9
chữ số.

Output: Mỗi bộ test viết ra số lượng các số thuần nguyên tố tương ứng.

Ví dụ:

Input:
2
23 199
2345 6789

Output:
1
15
*/

#include <math.h>
#include <stdio.h>

char prime(long int n) {
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return 0;
	return n > 1;
}

char pure_prime(long int n) {
	long int temp = n;
	int sum = 0;
	while (temp) {
		int a = temp % 10;
		if (prime(a)) sum += a;
		else return 0;
		temp /= 10;
	}
	if (prime(n) && prime(sum)) return 1;
	return 0;
}

int main() {
	unsigned int n;
	scanf("%d", &n);
	int result[n];
	for (int i = 0; i < n; i++) {
		long int a, b;
		scanf("%ld %ld", &a, &b);
		result[i] = 0;
		for (long int j = a; j <= b; j++)
			if (pure_prime(j)) result[i]++;
	};
	for (int i = 0; i < n; i++) //
		printf("%d\n", result[i]);
	return 0;
}
