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

#define i64 long long
#define u64 unsigned long long

void gen_diff(u64 *min, u64 *max, u64 x) {

	u64 base = 1;

	while (x > 0) {

		switch (x % 10) {

		case 5:
			*max += base;
			break;

		case 6:
			*min -= base;
			break;
		}

		base *= 10;
		x /= 10;
	}
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		u64 x1, x2;
		scanf("%llu%llu", &x1, &x2);

		u64 min, max;
		min = max = x1 + x2;

		gen_diff(&min, &max, x1);
		gen_diff(&min, &max, x2);

		printf("%llu %llu\n", min, max);
		fflush(stdout);
	}

	return 0;
}
