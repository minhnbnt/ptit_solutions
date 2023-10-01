/*
Cho một dãy các số nguyên dương không quá 9 chữ số, mỗi số cách nhau vài khoảng
trống, có thể xuống dòng. Hãy tìm các số không giảm (các chữ số theo thứ tự từ
trái qua phải tạo thành dãy không giảm) và đếm số lần xuất hiện của các số đó.

Input: Gồm các số nguyên dương không quá 9 chữ số. Không quá 100000 số.

Kết quả Ghi ra các số không giảm kèm theo số lần xuất hiện. Các số được liệt kê
theo thứ tự sắp xếp số lần xuất hiện giảm dần.

Ví dụ:
Input:
123 321 23456 123 123 23456 3523 123 321 8988 7654 9899 3456 123 999 3456
987654321 4546 63543 4656 13432 4563 123471 659837 454945 34355 9087 9977 98534
3456 23134

Output:
123 5
3456 3
23456 2
999 1
*/

#include <stdio.h>

char decease_num(int n) {
	int a = n % 10, b;
	while (n /= 10) {
		b = n % 10;
		if (a < b) break;
		a = b;
	};
	return n == 0;
}

void swap(void *a, void *b, size_t size) {
	while (size--) {
		char tmp = *(char *)a;
		*(char *)a++ = *(char *)b;
		*(char *)b++ = tmp;
	}
}

int main() {
	long int arr[100000], size = 0;
	while (scanf("%ld", &arr[size]) != EOF) size++;
	int appear[size];
	for (int i = 0; i < size; i++)
		if (decease_num(arr[i])) {
			appear[i] = 1;
			for (int j = 0; j < i; j++)
				if (arr[i] == arr[j]) {
					appear[j] += appear[i];
					appear[i] = 0;
				};
		} else appear[i] = 0;
	for (int i = 0; i < size; i++)
		if (appear[i])
			for (int j = i; j < size; j++)
				if (appear[j] && appear[i] < appear[j]) {
					swap(&arr[i], &arr[j], sizeof(long int));
					swap(&appear[i], &appear[j], sizeof(int));
				};
	for (int i = 0; i < size; i++)
		if (appear[i] && decease_num(arr[i]))
			printf("%ld\t%d\n", arr[i], appear[i]);
	return 0;
}
