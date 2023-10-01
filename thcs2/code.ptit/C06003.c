/*
Một từ trong xâu ký tự được định nghĩa là một dãy ký tự liên tiếp không có
khoảng trống. Hãy đếm số từ của xâu và in kết quả ra màn hình.

Dữ liệu vào: Dòng đầu ghi số bộ test. Mỗi bộ test có một xâu không quá 200 ký
tự.

Kết quả: Ghi ra số từ đếm được.

Ví dụ
Input:
2
Lap trinh     C va C++
ACBDSDS kdfjdkgfdgkhfgjlfgdkjfdgdgfdgfd

Output:
5
2
*/

#include <stdio.h>
#include <string.h>

int main() {
	unsigned int n;
	scanf("%d%*c", &n);
	while (n--) {
		char str[200] = { 0 };
		fgets(str, 200, stdin);
		str[strlen(str) - 1] = 0;
		int count = 0;
		char *p = strtok(str, " ");
		while (p != NULL) {
			count++;
			p = strtok(NULL, " ");
		}
		printf("%d\n", count);
	}
	return 0;
}
