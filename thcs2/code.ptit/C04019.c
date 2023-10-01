/*
Cho một dãy số nguyên dương không quá 100 phần tử, các giá trị trong dãy không
quá 30000. Hãy xác định xem số nào là số xuất hiện nhiều lần nhất trong dãy. Chú
ý: trong trường hợp nhiều số khác nhau cùng xuất hiện số lần bằng nhau và là lớn
nhất thì in ra tất cả các số đó theo thứ tự xuất hiện trong dãy ban đầu.

Input: Dòng đầu là số bộ test, không quá 20. Mỗi bộ test gồm hai dòng. Dòng đầu
ghi số phần tử của dãy, dòng tiếp theo ghi các phần tử của dãy.

Output: Với mỗi bộ test, đưa ra số xuất hiện nhiều lần nhất trong dãy đã cho.

Ví dụ:
Input:
2
10
1 2 3 1 2 3 1 2 3 1
10
1 2 3 4 5 6 7 8 9 0

Output:
1
1 2 3 4 5 6 7 8 9 0
*/

#include <stdio.h>

int main() {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		unsigned ele;
		scanf("%u", &ele);
		int arr[ele], app[ele], max = 1;
		for (int i = 0; i < ele; i++) {
			app[i] = 1;
			scanf("%d", &arr[i]);
			for (int j = 0; j < i; j++)
				if (arr[i] == arr[j]) {
					app[i] = 0, app[j]++;
					if (app[j] > max) max = app[j];
					break;
				}
		}
		for (int i = 0; i < ele; i++)
			if (app[i] == max) printf("%d ", arr[i]);
		putchar('\n');
	}
	return 0;
}
