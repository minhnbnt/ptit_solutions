/*
Nhập một số nguyên dương không quá 9 chữ số. Hãy kiểm tra xem đó có phải số
chính phương hay không.

Input:
Dòng đầu của dữ liệu vào ghi số bộ test, mỗi bộ test ghi một số nguyên dương N.

Output:
Ghi ra YES nếu đúng và NO nếu không.

Ví dụ
Input:
3
11
121
361

Output:
NO
YES
YES
*/

#include <math.h>
#include <stdio.h>

int main() {
	unsigned int n;
	scanf("%d", &n);
	unsigned long int x;
	for (int i = 0; i < n; i++) {
		scanf("%ld", &x);
		if ((int)sqrt(x) == sqrt(x)) {
			puts("YES");
		} else puts("NO");
	}
	return 0;
}
