/*
Dãy số Fibonacci được định nghĩa theo công thức như sau:

F1 = F2 =1
Fn = Fn-1 + Fn-2 với n>2

Viết chương trình tính số Fibonacci thứ n (với n không quá 92)

Input: Dòng đầu ghi số bộ test. Mỗi bộ test là một số nguyên n.

Output: Với mỗi bộ test, ghi ra số Fibonacci thứ n trên một dòng.

Ví dụ:
Input:
3
2
5
20

Output:
1
5
6765
*/

#include <stdio.h>

int main() {
	unsigned test, i;
	scanf("%u", &test);
	int arr[test], max = -32767;
	for (i = 0; i < test; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > max) max = arr[i];
	}
	unsigned long f[max];
	f[0] = f[1] = 1;
	for (i = 2; i < max; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	for (i = 0; i < test; i++) {
		printf("%lu\n", f[arr[i] - 1]);
	}
	return 0;
}
