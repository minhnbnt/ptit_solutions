/*
Cho số tự nhiên N không quá 9 chữ số. Hãy in ra giá trị bình phương của N.

Input:
Dòng đầu ghi số bộ test. Mỗi bộ test có duy nhất một số tự nhiên không quá 9 chữ
số.

Output:
Với mỗi bộ test, ghi ra kết quả trên một dòng.

Ví dụ:
Input:
2
1
23

Output:
1
529
*/

#include <stdio.h>

int main() {
	unsigned int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long int x;
		scanf("%ld", &x);
		printf("%lld\n", (long long)x * x);
	};
	return 0;
}
