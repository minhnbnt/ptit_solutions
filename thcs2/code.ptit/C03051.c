/*
Cho hai số L, R. Nhiệm vụ của bạn là hãy đếm tất cả các số có đúng ba ước số
trong khoảng [L, R]. Ví dụ L = 1, R = 10, ta có kết quả là 2 vì chỉ có số 4 và 9
là có đúng 3 ước số.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là cặp số L, R.
T, N thỏa mãn rang buộc 1≤T≤100; 1≤L, R ≤10^12.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:
Input:
2
1 10
1 1000000000000

Output:
2
78498
*/

#include <math.h>
#include <stdio.h>

char display(long long x) {
	char flag = 0;
	for (int i = 2; i <= sqrt(x); i++)
		while (x % i == 0)
			if (!flag) flag = 1;
			else return 0;
	return flag;
}

int main() {
	int n;
	scanf("%d", &n);
	long result[n];
	long long a, b;
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a, &b);
		result[i] = 0;
		for (long long j = a; j <= b; j++)
			if (display(j)) result[i]++;
	}
	for (int i = 0; i < n; i++) {
		printf("%ld\n", result[i]);
	}
	return 0;
}
