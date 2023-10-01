/*
Viết chương trình nhập vào mảng A gồm n phần tử (1 < n < 100). Các giá trị trong
dãy không quá 1000. Thực hiện tách mảng đã cho thành mảng các số chẵn và mảng
các số lẻ.

Input
Dòng thứ nhất là số phần tử của mảng A.
Dòng thứ hai là các phần tử của mảng A
Các phần tử không vượt quá 1000.

Output
Dòng thứ nhất là mảng các số chẵn
Dòng thứ hai là mảng các số lẻ.

Ví dụ:
Input:
5
1 2 3 4 5

Output:
2 4
1 3 5
*/

#include <stdio.h>

void print_arr(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

int main() {
	int ele, size_odd = 0, size_even = 0;
	scanf("%d", &ele);
	int arr, odd[ele], even[ele], i;
	for (i = 0; i < ele; i++) {
		scanf("%d", &arr);
		if (arr % 2) odd[size_odd++] = arr;
		else even[size_even++] = arr;
	}
	print_arr(even, size_even);
	print_arr(odd, size_odd);
	return 0;
}
