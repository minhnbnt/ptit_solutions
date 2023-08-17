/*
Cho hai số nguyên dương a và m. Nhiệm vụ của bạn là tìm x nhỏ nhất trong khoảng
[0,m-1] sao cho a * x  ≡ 1( mod m). Ví dụ a = 3, m=11 ta tìm được x = 4 vì
4*3%11=1.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp mỗi dòng đưa vào một test. Mỗi test là bộ đôi a, m được viết
cách nhau một vài khoảng trống. T, a, m thỏa mãn ràng buộc : 1≤T≤100; 1≤a
≤m≤100.

Output:
Đưa ra kết quả mỗi test theo từng dòng. Nếu phương trình đồng dư không có
nghiệm, hày đưa ra -1

Input:
2
3 11
10 17

Output:
4
12
*/

#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned a, m;
		scanf("%u%u", &a, &m);

		int result = 1;
		while (result * a % m != 1) {

			++result;

			if (result > m) {
				result = -1;
				break;
			}
		}

		printf("%d\n", result);
		fflush(stdout);
	}

	return 0;
}
