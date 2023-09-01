/*
Cho số tự nhiên N và số K. Hãy đưa ta các tổ hợp chập K của 1, 2, .., N.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ đôi N, K được viết
trên 1 dòng. T, N, K thỏa mãn ràng buộc: 1 ≤ T, K, N ≤ 20.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
5 3

Output:
123 124 125 134 135 145 234 235 245 345
*/

#include <stdio.h>
#include <stdlib.h>

char OK;
unsigned *arr, n, k;

void init(void) {

	arr = (unsigned *)malloc(sizeof(unsigned) * (k + 1));

	for (unsigned i = 1; i <= k; ++i) {
		arr[i] = i;
	}

	OK = 1;
}

void gen_next_comb(void) {

	unsigned i = k, j;
	while (i > 0 && arr[i] == n - k + i) {
		--i;
	}

	if (i == 0) {
		OK = 0;
		return;
	}

	++arr[i];

	for (j = i + 1; j <= k; ++j) {
		arr[j] = arr[j - 1] + 1;
	}
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		scanf("%u%u", &n, &k);

		init();

		while (OK) {

			for (unsigned i = 1; i <= k; ++i) {
				printf("%u", arr[i]);
			}
			putchar(' ');

			gen_next_comb();
		}

		putchar('\n');
		fflush(stdout);

		free(arr);
	}

	return 0;
}
