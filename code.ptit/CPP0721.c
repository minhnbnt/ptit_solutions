/*
Cho mảng A[] gồm n số được sinh ra ngẫu nhiên. Hãy tìm độ dài dãy tăng dài nhất
các phần tử của mảng. Chú ý, dãy con của mảng không nhất thiết là liên tục. Hai
phần tử giống nhau của mảng ta chỉ xem là 1 trong độ dài dãy tăng.
Ví dụ với mảng A[] = {5, 8, 3, 7, 9, 1}, ta có kết quả là 3.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào n là số phần tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng;
các số được viết cách nhau một vài khoảng trống.

T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^3; 0≤ A[i] ≤10^3;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1

Output:
6
3
*/

#include <stdio.h>
#include <string.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned n, i, j;
		scanf("%u", &n);

		int arr[n];
		unsigned tmp[n], result = 0;
		for (i = 0; i < n; ++i) {
			tmp[i] = 0;
			scanf("%d", &arr[i]);

			unsigned max = 0;

			for (j = 0; j < i; ++j)
				if (max < tmp[j] && arr[j] < arr[i]) {
					max = tmp[j];
				}

			tmp[i] = max + 1;
			if (tmp[i] > result) {
				result = tmp[i];
			}
		}

		printf("%u\n", result);
		fflush(stdout);
	}

	return 0;
}
