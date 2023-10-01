/*
Viết chương trình nhập mảng n (1<n<100) phần tử số nguyên dương. Các giá trị
trong mảng không quá 1000.
Đếm các phần tử là số nguyên tố trong mảng và in ra lần lượt theo thứ tự xuất
hiện.

Input
Dòng 1 ghi số n. Dòng 2 ghi n số của mảng.

Output
Ghi số lượng các số nguyên tố, sau đó lần lượt là các số nguyên tố theo thứ tự
xuất hiện.

Ví dụ:
Input:
6
1 5 3 19 18 25

Output:
3 5 3 19
*/

#include <math.h>
#include <stdio.h>

int main() {
	unsigned ele, i, j;
	scanf("%u", &ele);
	int arr[ele], max = -32767, count = 0;
	for (i = 0; i < ele; i++) {
		scanf("%u", &arr[i]);
		if (arr[i] > max) max = arr[i];
	}
	char prime[max + 1];
	prime[0] = prime[1] = 0;
	for (i = 2; i <= max; i++) prime[i] = 1;
	for (i = 2; i <= sqrt(max); i++)
		if (prime[i])
			for (j = 2 * i; j <= max; j += i) //
				prime[j] = 0;
	for (i = 0; i < ele; i++)
		if (prime[arr[i]]) count++;
	printf("%d ", count);
	for (i = 0; i < ele; i++)
		if (prime[arr[i]]) printf("%d ", arr[i]);
	return 0;
}
