/*
Cho mảng A[] gồm n số và số nguyên dương k. Hãy tìm dãy con liên tục độ dài k có giá trị trung bình
các phần tử lớn nhất. Ví dụ với A[] = { 1, 12, -5, -6, 50, 3} và k = 4 ta có câu trả lời là {12, -5,
-6, 50} có trung bình các phần tử lớn nhất là (12-5-6+30)/4=7.75.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng
n và số k; dòng tiếp theo là n số A[i] của mảng A[]; các số được viết cách nhau một vài khoảng
trống.
T, n, k, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ k≤n ≤10^3; -10^3≤ A[i]  ≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5 2
10 4 5 15 20
4 2
-12 34 56 7

Output:
15 20
34 56
*/

#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		size_t ele, length, i;
		scanf("%zu %zu", &ele, &length);

		int arr[ele];
		for (i = 0; i < ele; ++i) {
			scanf("%d", arr + i);
		}

		long long sum = 0;
		for (i = 0; i < length; ++i) {
			sum += arr[i];
		}
		size_t start = 0;
		long long max_sum = sum;
		for (i = 1; i <= ele - length; ++i) {
			sum += arr[i + length - 1] - arr[i - 1];

			if (sum > max_sum) {
				max_sum = sum;
				start = i;
			}
		}
		for (i = start; i < start + length; ++i) {
			printf("%d ", arr[i]);
		}
		putchar(0xa);
	}

	return 0;
}
