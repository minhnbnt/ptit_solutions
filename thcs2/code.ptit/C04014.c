/*
Viết chương trình nhập vào mảng một chiều n phần tử (1 < n < 100) và thực hiện
in ra các phần tử cùng số lần xuất hiện của chúng trong mảng. Các phần tử liệt
kê theo thứ tự xuất hiện.

Input
Dòng 1 ghi số n. Dòng 2 ghi n số của mảng.

Output
Ghi ra kết quả kết quả gồm các số khác nhau và số lần xuất hiện. Mỗi số trên một
dòng.

Ví dụ:
Input:
7
2 3 3 2 1 9 5

Output:
2 2
3 2
1 1
9 1
5 1
*/

#include <stdio.h>

int main() {
	unsigned ele, i, j;
	scanf("%u", &ele);
	int arr[ele], app[ele];
	for (i = 0; i < ele; i++) {
		app[i] = 1;
		scanf("%d", &arr[i]);
		for (j = 0; j < i; j++)
			if (arr[i] == arr[j]) {
				app[i] = 0, app[j]++;
				break;
			};
	}
	for (i = 0; i < ele; i++)
		if (app[i]) //
			printf("%d %d\n", arr[i], app[i]);
	return 0;
}
