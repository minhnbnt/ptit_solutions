/*
Số hoàn hảo là số có tổng các ước số (nhỏ hơn chính nó) bằng nó. Ví dụ: 6 = 1 +
2 + 3. Nhập vào số N và kiểm tra xem n có phải là số hoàn hảo hay không. Nếu
đúng in ra 1, sai in ra 0.

Input
Chỉ có một dòng ghi số N (không quá 6 chữ số)

Output
Ghi ra 1 hoặc 0

Ví dụ:
Input:
6

Output:
1
*/

#include <stdio.h>

char perfect(long n) {
	long sum = 0;
	for (long i = 1; i < n; i++)
		if (n % i == 0) sum += i;
	return sum == n;
}

int main() {
	long n;
	scanf("%ld", &n);
	printf("%d\n", perfect(n));
	return 0;
}
