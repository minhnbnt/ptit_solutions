/*
Cho dãy số A[] gồm có N phần tử. Bạn cần tìm chênh lệch nhỏ nhất giữa hai phần
tử bất kì trong dãy số đã cho.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm số nguyên N (1≤ N ≤ 100 000).
Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 109).

Output:
Với mỗi test, in ra trên một dòng là đáp án tìm được.
Ví dụ:

Input:
3
6
1 5 3 19 18 25
4
30 5 20 9
7
1 19 2 31 38 25 100

Output:
1
4
1
*/

#include <stdio.h>
#include <stdlib.h>

#define i64 long long
#define u64 unsigned long long

int comparator(const void *a, const void *b) {
	return *(i64 *)a > *(i64 *)b;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		u64 ele, i;
		scanf("%llu", &ele);

		i64 arr[ele];
		for (i = 0; i < ele; ++i) {
			scanf("%lld", &arr[i]);
		}

		qsort(arr, ele, sizeof(i64), comparator);
		i64 result = arr[1] - arr[0];
		for (i = 1; i < ele - 1; ++i) {
			i64 gap = arr[i + 1] - arr[i];
			if (gap < result) result = gap;
		}

		printf("%lld\n", result);
		fflush(stdout);
	}

	return 0;
}
