/*
Nhập một dãy số nguyên có n phần tử (n không quá 100, các phần tử trong dãy
không quá 10^9). Hãy viết chương trình kiểm tra xem dãy có phải đối xứng hay
không. Nếu đúng in ra YES, nếu sai in ra NO.

Input: Dòng đầu ghi số bộ test, mỗi bộ test gồm hai dòng. Dòng đầu là số phần tử
của dãy, dòng sau ghi ra dãy đó, mỗi số cách nhau một khoảng trống.

Output: In ra kết quả kiểm tra.

Ví dụ:
Input:

2
4
1 4 4 1
5
1 5 5 5 3

Ouput:
YES
NO
*/

#include <stdio.h>
#include <stdlib.h>

char symmetrical_array(long *arr, unsigned ele) {
	for (unsigned i = 0; i <= ele / 2; i++)
		if (arr[i] != arr[ele - i - 1]) return 0;
	return 1;
}

int main() {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		unsigned ele, i;
		scanf("%u", &ele);
		long *arr = malloc(sizeof(long long) * ele);
		for (i = 0; i < ele; i++) scanf("%ld", &arr[i]);
		puts(symmetrical_array(arr, ele) ? "YES" : "NO");
	}
	return 0;
}
