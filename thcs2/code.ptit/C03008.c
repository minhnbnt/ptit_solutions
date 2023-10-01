/*
Số hoàn hảo là số có tổng các ước số (nhỏ hơn chính nó) bằng nó.
Ví dụ: 6 = 1 + 2 + 3.

Viết chương trình cho phép nhập vào số n (không quá 6 chữ số) và liệt kê các số
hoàn hảo nhỏ hơn n.

Input:
Chỉ có một dòng ghi số n.

Output:
Ghi ra kết quả tính toán trên một dòng

Ví dụ:

Input:
1000

Output:
6 28 496
*/

#include <stdio.h>

int main(void) {
	long n;
	scanf("%ld", &n);
	long arr[n + 1];
	for (long i = 0; i <= n; i++) {
		arr[i] = 0;
	}
	for (long i = 1; i <= n; i++)
		for (long j = i * 2; j <= n; j += i) {
			arr[j] += i;
		}
	for (long i = 1; i <= n; i++)
		if (arr[i] == i) printf("%ld ", i);
	return 0;
}
