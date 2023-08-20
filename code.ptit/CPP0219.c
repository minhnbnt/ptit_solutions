/*
Cho mảng A[] gồm n phần tử, hãy tìm k phần tử lớn nhất của mảng. Các phần tử
được đưa ra theo thứ tự giảm dần.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất
đưa vào N và K; dòng tiếp theo đưa vào n số A[i]; các số được viết cách nhau một
vài khoảng trống.

T, N, K, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤K < N ≤10^3, 1≤A[i] ≤10^6.

Output:
Đưa ra kết quả mỗi bộ test trên một dòng.

Input:
2
5 3
10 7 9 12 6
6 2
9 7 12 8 6 5

Output:
12 10 9
12 9
*/

#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned row, col, i, j, k;
		scanf("%u%u", &row, &col);

		int arr[row][col], fill[row][col];
		for (i = 0; i < row; ++i)
			for (j = 0; j < col; ++j) {
				scanf("%d", &arr[i][j]);
				fill[i][j] = 0;
			}

		for (i = 0; i < row; ++i)
			for (j = 0; j < col; ++j) {

				if (arr[i][j] == 0) continue;

				for (k = 0; k < row; ++k) {
					fill[k][j] = 1;
				}
				for (k = 0; k < col; ++k) {
					fill[i][k] = 1;
				}
			}

		for (i = 0; i < row; ++i) {
			for (j = 0; j < col; ++j) {
				printf("%d ", fill[i][j]);
			}
			putchar(0xa);
		}
	}

	return 0;
}
