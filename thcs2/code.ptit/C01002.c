/*
Cho số tự nhiên N không quá 9 chữ số. Hãy in ra giá trị gấp đôi của N.

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
2
46
*/

#include <stdio.h>

int main() {
	unsigned int n;
	scanf("%d", &n);
	while (n--) {
		long x;
		scanf("%ld", &x);
		printf("%ld\n", x * 2);
	}
	return 0;
}
