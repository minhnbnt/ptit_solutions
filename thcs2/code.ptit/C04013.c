/*
Viết chương trình cho phép nhập vào mảng A có n phần tử số nguyên (2 < n < 100).
Đếm các phần tử chỉ xuất hiện một lần và liệt kê.

Input
Dòng thứ nhất là số phần tử của mảng A.
Dòng thứ hai là các phần tử của mảng A

Output
Dòng đầu tiên là số các phần tử thỏa mãn
Dòng thứ hai là các phần tử thỏa mãn.

Ví dụ:
Input:
7
1 5 10 10 5 2 3

Output:
3
1 2 3
*/

#include <stdio.h>

int main() {
	unsigned ele, i, j;
	scanf("%u", &ele);
	int arr[ele], count = 0;
	char flag[ele];
	for (i = 0; i < ele; i++) {
		flag[i] = 1;
		scanf("%d", &arr[i]);
		for (j = 0; j < i; j++)
			if (arr[i] == arr[j]) {
				flag[i] = flag[j] = 0;
				break;
			}
	}
	for (i = 0; i < ele; i++)
		if (flag[i]) count++;
	printf("%d\n", count);
	for (i = 0; i < ele; i++)
		if (flag[i]) printf("%d ", arr[i]);
	putchar('\n');
	return 0;
}
