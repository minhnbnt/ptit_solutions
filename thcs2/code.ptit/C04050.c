/*
Cho dãy số a[] có n phần tử và dãy số b[] có m phần tử là các số nguyên dương
nhỏ hơn 1000. Gọi tập hợp A là tập các số khác nhau trong a[], tập hợp B là tập
các số khác nhau trong b[].

Hãy tìm tập giao của A và B, hiệu A – B và hiệu B – A. Mỗi tập kết quả viết trên
một dòng theo thứ tự từ nhỏ đến lớn.

Input
Dòng đầu ghi 2 số n và m (1 < n,m <100).
Dòng thứ 2 ghi n số của a[].
Dòng thứ 3 ghi m số của b[].
Các số đều dương và nhỏ hơn 1000.

Output
Dòng đầu ghi tập giao của A và B
Dòng thứ 2 ghi tập A – B
Dòng thứ 3 ghi tập B - A

Ví dụ:
Input:
5 6
1 2 3 4 5
3 4 5 6 7 8

Output:
3 4 5
1 2
6 7 8
*/

#include <stdio.h>
#include <stdlib.h>

int *input(unsigned ele, unsigned *mod) {
	int *arr = NULL;
	unsigned i, j, size = 0;
	for (i = 0; i < ele; i++) {
		char flag = 0;
		int temp;
		scanf("%d", &temp);
		for (j = 0; j < size; j++)
			if (arr[j] == temp) {
				flag = 1;
				break;
			}
		if (flag) continue;
		arr = realloc(arr, (size + 1) * sizeof(int));
		arr[size] = temp, j = size++;
		while (j > 0 && arr[j] < arr[j - 1]) {
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[--j] = temp;
		}
	}
	*mod = size;
	return arr;
}

void print_if_not_same(int *arr, unsigned ele, //
                       int *same, unsigned size) {
	unsigned i, j;
	for (i = 0; i < ele; i++) {
		char flag = 1;
		for (j = 0; j < size; j++)
			if (arr[i] == same[j]) {
				flag = 0;
				break;
			}
		if (flag) printf("%d ", arr[i]);
	}
	putchar('\n');
}

int main() {
	unsigned ele1, ele2, size = 0, i, j;
	scanf("%u %u", &ele1, &ele2);
	int *arr1 = input(ele1, &ele1);
	int *arr2 = input(ele2, &ele2);
	int *same = NULL;
	for (i = 0; i < ele1; i++)
		for (j = 0; j < ele2; j++)
			if (arr1[i] == arr2[j]) {
				printf("%d ", arr1[i]);
				same = realloc(same, (size + 1) * sizeof(int));
				same[size++] = arr1[i];
			}
	printf("\n");
	print_if_not_same(arr1, ele1, same, size);
	print_if_not_same(arr2, ele2, same, size);
	return 0;
}
