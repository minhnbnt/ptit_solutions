/*
Gọi gcd(a,b) là thao tác tính ước số chung lớn nhất của hai số nguyên a,b.

Cho dãy số A[] nguyên dương có N phần tử. Hãy xây dựng dãy số B có N+1 phần tử
sao cho gcd(B[i], B[i+1]) = A[i] với mọi i thỏa mãn 1 ≤ i ≤ n. Vì có rất nhiều
dãy số B[] thỏa mãn, nên bạn cần tìm được dãy số có tổng các phần tử là nhỏ
nhất.

Input
Dòng đầu tiên là số lượng bộ test T (1 ≤ T ≤ 10).
Mỗi test bắt đầu bằng số nguyên N (2 ≤ N ≤ 1000).
Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 10 000).

Output
Với mỗi test in ra dãy số B[] trên một dòng.

Ví dụ:
Input:
2
3
1 2 3
3
5 10 5

Output:
1 2 3 6 3
5 10 10 5
*/

#include <stdio.h>

long lcm(int a, int b) {
	long result = a * b;
	while (a != b)
		if (a > b) a -= b;
		else b -= a;
	return result / a;
}

int main() {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		unsigned ele, i;
		scanf("%u", &ele);
		int arr[ele + 2];
		arr[0] = arr[ele + 1] = 1;
		for (i = 1; i <= ele; i++) {
			scanf("%d", &arr[i]);
		}
		for (i = 0; i <= ele; i++) {
			printf("%ld ", lcm(arr[i], arr[i + 1]));
		}
		putchar('\n');
	}
	return 0;
}
