/*
Viết chương trình nhập vào mảng một chiều n phần tử (1 < n < 100) và thực hiện
in ra các phần tử xuất hiện nhiều hơn 1 lần trong mảng theo thứ tự xuất hiện
(Nếu không có phần tử nào thỏa mãn in ra 0).

Input
Dòng 1 ghi số n. Dòng 2 ghi n số của mảng.

Output
Ghi ra kết quả trên một dòng.

Ví dụ:

Input:
7
2 3 3 2 1 9 5

Output
2 3
*/

#include <stdio.h>

int main() {
	unsigned ele, i, j;
	scanf("%u", &ele);
	int arr[ele];
	char flag[ele], flag2 = 1;
	for (i = 0; i < ele; i++) {
		flag[i] = 0;
		scanf("%d", &arr[i]);
		for (j = 0; j < i; j++)
			if (arr[i] == arr[j]) {
				flag[j] = 1, flag2 = 0;
				break;
			}
	}
	if (flag2) putchar('0');
	else
		for (i = 0; i < ele; i++)
			if (flag[i]) printf("%d ", arr[i]);
	putchar('\n');
	return 0;
}
