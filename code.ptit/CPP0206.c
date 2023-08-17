/*
Cho mảng A[] gồm n phần tử. Hãy tìm phần tử lớn nhất của mảng. Ví dụ với mảng
A[] = { 7, 10, 4, 3, 20, 15 } ta nhận được kết quả là 20.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào n là số phần tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng;
các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤105; 1≤ A[i] ≤105;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
6
7 10 4 3 20 15
6
9 7 12 8 6 5

Output:
20
12
*/

#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned ele;
		scanf("%u", &ele);

		int max = -__INT16_MAX__;
		while (ele--) {
			int num;
			scanf("%d", &num);
			if (num > max) {
				max = num;
			}
		}

		printf("%d\n", max);
		fflush(stdout);
	}

	return 0;
}
