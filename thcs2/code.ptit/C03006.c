/*
Hãy phân tích một số nguyên dương thành tích các thừa số nguyên tố.

Input
Dòng đầu tiên ghi số bộ test. Mỗi bộ test viết trên một dòng số nguyên dương n
không quá 9 chữ số.

Output
Mỗi bộ test viết ra thứ tự bộ test, sau đó lần lượt là các số nguyên tố khác
nhau có trong tích, với mỗi số viết thêm số lượng số đó. Xem ví dụ để hiểu rõ
hơn về cách viết kết quả.

Ví dụ:
Input:
3
60
128
10000

Output:
Test 1: 2(2) 3(1) 5(1)
Test 2: 2(7)
Test 3: 2(4) 5(4)
*/

#include <stdio.h>

int main(void) {
	unsigned test, pos = 0;
	scanf("%u", &test);
	while (pos++ < test) {
		unsigned long n;
		scanf("%ld", &n);
		printf("Test %d: ", pos);
		for (unsigned i = 2; i * i <= n; i++) {
			unsigned exp = 0;
			while (n % i == 0) n /= i, exp++;
			if (exp) printf("%u(%u) ", i, exp);
		}
		if (n != 1) printf("%ld(1)", n);
		printf("\n");
	}
	return 0;
}
