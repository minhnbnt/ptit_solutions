/*
Viết chương trình in ra các số nguyên tố trong một dãy số cho trước.

Input: Dòng đầu ghi số bộ test. Mỗi test gồm 2 dòng, dòng đầu ghi số N là số
phần tử của dãy. Dòng sau ghi N số của dãy. N không quá 100, các số trong dãy
đều nguyên dương và không quá 1000.

Output: Với mỗi bộ test ghi trên một dòng lần lượt là các số nguyên tố của dãy
số ban đầu, theo thứ tự xuất hiện.

Ví dụ:

Input:
1
5
1 2 3 4 5

Output:
2 3 5
*/

#include <math.h>
#include <stdio.h>

char prime(int x) {
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0) return 0;
	return x > 1;
}

int main() {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		int ele;
		scanf("%d", &ele);
		int arr[ele];
		for (int i = 0; i < ele; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 0; i < ele; i++)
			if (prime(arr[i])) printf("%d ", arr[i]);
		putchar('\n');
	}
	return 0;
}
