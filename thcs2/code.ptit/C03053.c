/*
Cho số nguyên dương chẵn N>2. Hãy liệt kê các cặp số nguyên tố p, q có tổng đúng
bằng N. Ví dụ N = 6 ta có 1 cặp số nguyên tố là 3 + 3 =6.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số chẵn N.
T, N thỏa mãn ràng buộc : 1≤T≤100; 4≤N≤10000.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:
Input:
2
6
32

Output:
3 3
3 29 13 19
*/

#include <stdio.h>

char prime(int n) {
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) return 0;
	return n > 1;
}

int main(void) {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		int a, i;
		scanf("%d", &a);
		for (i = 0; i <= a / 2; i++)
			if (prime(i) && prime(a - i)) //
				printf("%d %d ", i, a - i);
		putchar('\n');
	}
	return 0;
}
