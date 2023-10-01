/*
Cho một dãy số nguyên dương có n phần tử (2<=n<=50). Hãy liệt kê số các phần tử
trong dãy không nhỏ hơn các số đứng trước nó (tính cả phần tử đầu tiên).

Input: Dòng 1 ghi số bộ test. Mỗi bộ test ghi ra 2 dòng: dòng 1 là số phần tử,
dòng thứ 2 ghi dãy số.

Output: ghi ra số phần tử thỏa mãn.

Ví dụ:
Input:
1
7
3 5 6 8 4 2 9

Output
5
*/

#include <stdio.h>

int main() {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		unsigned ele, i, j, count = 0;
		scanf("%u", &ele);
		int arr[ele];
		for (i = 0; i < ele; i++) {
			char flag = 1;
			scanf("%d", &arr[i]);
			for (j = 0; j < i; j++)
				if (arr[i] < arr[j]) flag = 0;
			if (flag) count++;
		}
		printf("%u\n", count);
	}
	return 0;
}
