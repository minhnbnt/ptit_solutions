/*
Cho mảng A[] gồm n số nguyên dương. Hãy tìm tổng lớn nhất của dãy con tăng dần của dãy số A[]. Ví dụ
với A[] = { 1, 101, 2, 3, 100, 4, 5} ta có câu trả lời là 106=1+2+3+100. Với dãy A[] = {10, 5, 4, 3}
ta có câu trả lời là 10.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng
n; dòng tiếp theo là n số A[i] của mảng A[]; các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n  ≤10^3; 1≤ A[i]  ≤10^7.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10
*/

#include <stdio.h>
#include <string.h>

typedef long long i64;

i64 gen_result(const i64 *arr, const size_t ele) {

	i64 result[ele];
	memcpy(result, arr, sizeof(i64) * ele);

	size_t i, j;
	for (i = 1; i < ele; ++i)

		for (j = 0; j < i; ++j) {

			const i64 with_i = result[j] + arr[i];

			if (arr[i] > arr[j] && result[i] < with_i) {
				result[i] = with_i;
			}
		}

	i64 max = result[0];
	for (i = 1; i < ele; ++i)
		if (max < result[i]) {
			max = result[i];
		}

	return max;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		size_t ele, i;
		scanf("%zu", &ele);

		i64 arr[ele];
		for (i = 0; i < ele; ++i) {
			scanf("%lld", arr + i);
		}

		printf("%lld\n", gen_result(arr, ele));
		fflush(stdout);
	}

	return 0;
}
