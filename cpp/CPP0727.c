/*
Cho mảng A[] gồm n số nguyên dương. Hãy tìm tổng lớn nhất của dãy con thỏa mãn ràng buộc không có
hai phần tử kề nhau thuộc một dãy con. Ví dụ với mảng A[] = {3, 2, 7, 10} ta nhận được kết quả là 13
= 10 + 3. Với mảng A[] = {3, 2, 5, 10, 7} ta có kết quả là 15 = 3 + 5 +7.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần
tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng; các số được viết cách nhau một vài khoảng
trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤105; 1≤ A[i] ≤10^5;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
6
5 5 10 100 10 5
3
1 20 3

Output:
110
20
*/

#include <stdio.h>

#define i64 long long
#define max(a, b) a > b ? a : b

i64 max_noncontinuous(const i64 *arr, const size_t ele) {

	i64 has_i = arr[0], without_i = 0;

	for (size_t i = 1; i < ele; ++i) {

		const i64 result_until_i = max(has_i, without_i);

		has_i = result_until_i + arr[i];
		without_i = result_until_i;
	}

	return max(has_i, without_i);
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		size_t ele, i;
		scanf("%lu", &ele);

		i64 arr[ele];
		for (i = 0; i < ele; ++i) {
			scanf("%lld", &arr[i]);
		}

		printf("%lld\n", max_noncontinuous(arr, ele));
		fflush(stdout);
	}

	return 0;
}
