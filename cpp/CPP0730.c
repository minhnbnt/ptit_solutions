/*
Cho mảng A[] gồm n phần tử. Nhiệm vụ của bạn là tìm tổng lớn nhất các dãy con liên tục của mảng A[].
Ví dụ với A[] = { -2, -3, 4, -1, -2, 1, 5, -3} ta có câu trả lời là 7 tương ứng với tổng lớn nhất
của dãy con liên tục {4, -1, -2, 1, 5}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng
n; dòng tiếp theo là n số A[i] của mảng A[]; các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n  ≤106; 10-6≤ A[i]  ≤106.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5
1 2 3 -2 5
4
-1 -2 -3 -4

Output:
9
-1
*/

#include <stdio.h>

#define i64 long long

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

		i64 max_so_far = -__INT_FAST64_MAX__, max_here = 0;
		for (i = 0; i < ele; ++i) {

			max_here += arr[i];

			if (max_here > max_so_far) {
				max_so_far = max_here;
			}

			if (max_here < 0) {
				max_here = 0;
			}
		}

		printf("%lld\n", max_so_far);
		fflush(stdout);
	}

	return 0;
}
