/*
Cho số tự nhiên N. Hãy đưa ta các hoán vị của 1, 2, .., N.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N được viết trên 1
dòng. T, N thỏa mãn ràng buộc :1 ≤ T, N ≤ 20.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
Input:
1
3

Output:
123 132 213 231 312 321
*/

#include <stdio.h>
#include <stdlib.h>

char OK;
unsigned *arr, n;

void swap(unsigned *a, unsigned *b) {

	unsigned tmp = *a;
	*a = *b, *b = tmp;
}

void init(void) {

	arr = (unsigned *)malloc((n + 1) * sizeof(unsigned));
	for (unsigned i = 1; i <= n; ++i) {
		arr[i] = i;
	}

	OK = 1;
}

void gen_next_perm(void) {

	unsigned i = n - 1;
	while (i > 0 && arr[i + 1] < arr[i]) {
		--i;
	}

	if (i == 0) {
		OK = 0;
		return;
	}

	unsigned j = n;
	while (arr[i] > arr[j]) --j;

	swap(&arr[i], &arr[j]);

	unsigned left = i + 1, right = n;
	while (left < right) {

		swap(&arr[left], &arr[right]);

		++left, --right;
	}
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		scanf("%u", &n);

		init();

		while (OK) {

			for (unsigned i = 1; i <= n; ++i) {
				printf("%u", arr[i]);
			}
			putchar(' ');

			gen_next_perm();
		}

		free(arr);

		putchar('\n');
		fflush(stdout);
	}

	return 0;
}
