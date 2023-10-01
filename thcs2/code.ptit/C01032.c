/*
Cho một số nguyên dương không quá 9 chữ số. Người ta phân tích số đó thành tích
các thừa số nguyên tố sau đó tính lại một giá trị mới bằng cách nhân các thừa số
nguyên tố khác nhau của số đó.

Ví dụ: Số 72 được phân tích thành 23 * 32. Giá trị tính được sẽ lã 2 * 3 = 6

Dữ liệu vào
Dòng đầu ghi số bộ test, không quá 10
Mỗi bộ test là một số nguyên dương không quá 10^9

Kết quả
Với mỗi bộ test, ghi ra kết quả tính được.

Ví dụ:
Input:
3
72
1000
997

Output:
6
10
997
*/

#include <math.h>
#include <stdio.h>

int main() {
	unsigned n;
	scanf("%u", &n);
	long result[n];
	long a;
	for (int i = 0; i < n; i++) {
		result[i] = 1;
		scanf("%ld", &a);
		for (int j = 2; j <= sqrt(a); j++) {
			char flag = 1;
			while (a % j == 0) {
				if (flag) {
					result[i] *= j;
					flag = 0;
				}
				a /= j;
			}
		}
		if (a > 1) result[i] *= a;
	}
	for (int i = 0; i < n; i++) //
		printf("%ld\n", result[i]);
	return 0;
}
