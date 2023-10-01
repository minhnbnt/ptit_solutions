/*
Cho mảng A[] gồm n phần tử và số X. Hãy đưa sắp xếp các phần tử của mảng theo
trị tuyệt đối của |X - A[i] |. Ví dụ với A[] = {10, 5, 3, 9, 2} và X = 7 ta đưa
ra mảng được sắp xếp theo nguyên tắc kể trên: A[] = {5, 9, 10, 3, 2} vì
|7-10|=3, |7-5|=2, |7-3|=4, |7-9|=2, |7-2|=5. Trong trường hợp có nhiều phần tử
có giá trị tuyệt đối như nhau, ưu tiên theo thứ tự số xuất hiện trước trong mảng
ban đầu.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là
số phần tử của mảng n và X; dòng tiếp theo là n số A [i] của mảng A [];các số
được viết cách nhau một vài khoảng trống.

T, n, X thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, X, A[i] ≤10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5 7
10 5 3 9 2
5 6
1 2 3 4 5

Output:
5 9 10 3 2
5 4 3 2 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef long long i64;

i64 ll_abs(i64 x) {
	if (x < 0) x = -x;
	return x;
}

i64 target;
int cmp(const void *a, const void *b) {
	i64 x = ll_abs(*(i64 *)a - target);
	i64 y = ll_abs(*(i64 *)b - target);

	return x - y;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		i64 ele, i;
		scanf("%lld%lld", &ele, &target);

		i64 arr[ele];
		for (i = 0; i < ele; ++i) {
			scanf("%lld", &arr[i]);
		}

		qsort(arr, ele, sizeof(i64), cmp);
		for (i = 0; i < ele; ++i) {
			printf("%lld ", arr[i]);
		}
		putchar(0xa), fflush(stdout);
	}

	return 0;
}
