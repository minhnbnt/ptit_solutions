/*
Cho mảng A[] gồm n số nguyên không âm. Hãy sắp đặt lại các phần tử trong mảng theo nguyên tắc:

Phần tử đầu tiên được thay bằng tích của nó và phần tử kế tiếp.
Phần  tử cuối cùng được thay bằng tích của nó và sau nó.
Các phần tử còn lại được thay bằng tích của phẩn tử sau nó và phẩn tử trước nó.

Ví dụ với mảng A[] = { 2, 3, 4, 5, 6 } thực hiện theo nguyên tắc trên ta được mảng A[] = {6, 8, 15,
24, 30}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần
tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng; các số được viết cách nhau một vài khoảng
trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤105; 1≤ A[i] ≤105;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5
2 3 4 5 6
6
9 7 12 8 6 5

Output:
6 8 15 24 30
63 108  56  72  40  30
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

		for (i = 0; i < ele; ++i) {

			if (i == 0) {
				printf("%lld ", arr[i] * arr[i + 1]);
				continue;
			}
			if (i == ele - 1) {
				printf("%lld\n", arr[i] * arr[i - 1]);
				continue;
			}

			printf("%lld ", arr[i - 1] * arr[i + 1]);
		}
		fflush(stdout);
	}

	return 0;
}
