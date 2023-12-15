/*
Cho mảng A[] gồm n số nguyên dương. Hãy biến mảng A[] thành một mảng đối xứng sao cho phép thay thế
A[i] = Merge(A[i], A[i+1]) được thực hiện ít nhất. Trong đó, Merge(A[i], A[i+1]) = A[i] + A[i+1]. Ví
dụ với A[] = {3, 2, 3, 3, 5} ta chỉ cần thực hiện 1 phép Merge(A[0], A[1]) để trở thành mảng A[] =
{5, 3, 3, 5}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng
n; dòng tiếp theo là n số A[i] của mảng A[]; các số được viết cách nhau một vài khoảng trống.

T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^3; 1≤ A[i]  ≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5
3 2 3 3 5
4
5 3 3 4

Output:
1
3
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;

u64 number_of_operator(unsigned *begin, unsigned *end) {

	u64 counter = 0;

	while (begin < end) {

		const unsigned left = *begin;
		const unsigned right = *(end - 1);

		if (left < right) {

			++begin;
			*begin += left;

			++counter;
			continue;
		}

		if (left > right) {

			--end;
			*(end - 1) += right;

			++counter;
			continue;
		}

		++begin, --end;
	}

	return counter;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases-- > 0) {

		size_t ele, i;
		scanf("%zu", &ele);

		unsigned *ptr = (unsigned *)malloc(sizeof(int) * ele);
		for (i = 0; i < ele; ++i) {
			scanf("%u", &ptr[i]);
		}

		printf("%llu\n", number_of_operator(ptr, ptr + ele));
		fflush(stdout);

		free(ptr);
	}

	return 0;
}
