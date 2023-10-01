/*
Cho hai số nguyên dương X1, X2. Ta chỉ được phép thay đổi chữ số 5 thành 6 và
ngược lại chữ số 6 thành chữ số 5 của các số X1 và X2. Hãy đưa ra tổng nhỏ nhất
và tổng lớn nhất các số X1 và X2 được tạo ra theo nguyên tắc kể trên.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là cặp các số X1, X2.
T, X1, X2 thỏa mãn ràng buộc: 1≤ T ≤100; 0≤ X1, X2 ≤10^18.
Output:

Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
645  666
5466 4555

Output:
1100  1312
10010 11132
*/

#include <stdio.h>

int main() {
	unsigned n;
	scanf("%u", &n);
	long long arr[2], max[n], min[n];
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &arr[0], &arr[1]);
		max[i] = min[i] = arr[0] + arr[1];
		for (int j = 0; j < 2; j++) {
			long long a = 1;
			while (arr[j] > 0) {
				if (arr[j] % 10 == 6) min[i] -= a;
				else if (arr[j] % 10 == 5) max[i] += a;
				arr[j] /= 10, a *= 10;
			};
		};
	};
	for (int i = 0; i < n; i++) //
		printf("%lld %lld\n", min[i], max[i]);
	return 0;
}
