/*
Viết chương trình in ra các số chẵn trong một dãy số cho trước.

Input: Dòng đầu ghi số bộ test. Mỗi test gồm 2 dòng, dòng đầu ghi số N là số
phần tử của dãy. Dòng sau ghi N số của dãy. N không quá 100, các số trong dãy
đều nguyên dương và không quá 1000.

Output: Với mỗi bộ test ghi trên một dòng lần lượt là các số chẵn của dãy số ban
đầu, theo thứ tự xuất hiện.

Ví dụ:
Input:
1
5
1 2 3 4 5

Output
2 4
*/

#include <stdio.h>

int main() {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		unsigned ele, i;
		scanf("%u", &ele);
		int arr[ele];
		for (i = 0; i < ele; i++) {
			scanf("%d", &arr[i]);
		}
		for (i = 0; i < ele; i++)
			if (arr[i] % 2 == 0) {
				printf("%d ", arr[i]);
			}
		putchar('\n');
	}
	return 0;
}
