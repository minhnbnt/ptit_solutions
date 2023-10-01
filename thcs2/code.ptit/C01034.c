/*
Nhập vào 2 số tự nhiên  m và n, sao cho  m<n và cả hai số đều không quá 9 chữ
số. Hãy liệt kê các số chính phương trong đoạn [m,n].

Input
Dữ liệu vào chỉ bao gồm hai số m và n ghi trên một dòng.

Output
Dòng đầu tiên của kết quả ghi số lượng số chính phương tìm được. Tiếp theo, mỗi
số chính phương được ghi trên một dòng.

Ví dụ
Input:
9 50

Output:
5
9
16
25
36
49
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	long a, b;
	int size = 0;
	scanf("%ld %ld", &a, &b);
	int *result = malloc(sizeof(int)), initial = sqrt(a);
	if (initial < sqrt(a)) ++initial;
	for (int i = initial; i <= sqrt(b); i++) {
		result = realloc(result, sizeof(int) * ++size);
		result[size - 1] = i;
	}
	printf("%d\n", size);
	for (int i = 0; i < size; i++) {
		printf("%.0f\n", pow(result[i], 2));
	}
	return 0;
}
