/*
Cho dãy số A[] gồm có N phần tử. Nhiệm vụ của bạn là hãy tìm số xuất hiện nhiều
hơn 1 lần trong dãy số và số thứ tự là nhỏ nhất.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 10). Mỗi test gồm số nguyên N
(1≤ N ≤ 100 000), số lượng phần tử trong dãy số ban đầu. Dòng tiếp theo gồm N số
nguyên A[i] (0 ≤ A[i] ≤ 109).

Output:  Với mỗi test in ra đáp án của bài toán trên một dòng. Nếu không tìm
được đáp án, in ra “NO”.

Ví dụ:

Input:
2
7
10 5 3 4 3 5 6

4
1 2 3 4

Output:
5
NO
*/

#include <stdio.h>

long *firstdup(long a[], long m) {
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
			if (a[i] == a[j]) return &a[i];
	return NULL;
}

int main() {
	unsigned n;
	scanf("%u", &n);
	long result[n];
	char flag[n];
	for (long i = 0; i < n; i++) {
		long m;
		scanf("%ld", &m);
		long a[m];
		for (int j = 0; j < m; j++) scanf("%ld", &a[j]);
		flag[i] = 1;
		if (firstdup(a, m) == NULL) flag[i] = 0;
		else result[i] = *firstdup(a, m);
	}
	for (int i = 0; i < n; i++) {
		if (flag[i]) printf("%ld", result[i]);
		else puts("NO");
		putchar('\n');
	}
	return 0;
}
