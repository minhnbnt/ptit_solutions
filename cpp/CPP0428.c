/*
Cho mảng A[] gồm n phần tử và mảng B[] gồm m phần tử. Nhiệm vụ của bạn là hợp
nhất hai mảng A[] và B[] để được một mảng mới đã được sắp xếp. Ví dụ A[] = {10,
5, 15}, B[] = {20, 3, 2} ta có kết quả là C[] = {2, 3, 5, 10, 15, 20}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm ba dòng: dòng đầu tiên đưa
vào n, m tương ứng với số phần tử của mảng A[] và B[]; dòng tiếp theo là n số
A[i] ; dòng cuối cùng là m số B[i]; các số được viết cách nhau một vài khoảng
trống.

T, n, m, A[i], B[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, m ≤10^6; -10^8≤ A[i]
≤10^8.
Output: Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
3 3
10 5 15
20 3 2

Output:
2 3 5 10 15 20
*/

#include <stdio.h>
#include <stdlib.h>

typedef long long i64;

int cmp(const void *a, const void *b) {
	return *(i64 *)a > *(i64 *)b;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		size_t eleA, eleB, i;
		scanf("%lu%lu", &eleA, &eleB);
		const size_t ele = eleA + eleB;

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
