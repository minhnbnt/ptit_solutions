/*
Cho số tự nhiên N. Nhiệm vụ của bạn là hãy đưa ra ước số nguyên tố thứ k của N.
Đưa ra -1 nếu không tồn tại ước số thứ k của N. Ví dụ N = 225, k =2 ta có kết
quả là 3 vì 225 = 3×3×5×5. Với N = 81, k = 5 ta có kết quả -1 vì 81 = 3×3×3×3.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một bộ đôi N và k.
T, N thỏa mãn ràng buộc 1≤T≤100; 1≤N, k≤104.

Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input:
2
225 2
81 5

Output:
3
-1
*/

#include <math.h>
#include <stdio.h>

int calculate(unsigned N, unsigned k) {

	for (unsigned i = 2; i <= sqrt(N); i++)
		while (N % i == 0) {

			N /= i, --k;

			if (k == 0) return i;
		}

	if (N > 1 && k == 1) return N;
	return -1;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned N, k;
		scanf("%u%u", &N, &k);

		int result = calculate(N, k);

		printf("%d\n", result);
		fflush(stdout);
	}

	return 0;
}
