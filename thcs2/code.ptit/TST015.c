/*
Cho một tập N bộ 3 số là các cạnh của một tam giác.

Định nghĩa kiểu dữ liệu bản ghi có thẻ là tamgiac với thành phần trường dữ liệu
là a, b, c là ba cạnh

Xây dựng hàm nhập thông tin cho bản ghi tam giác
Xây dựng hàm tính diện tích cho tam giác
Xây dựng hàm in thông tin tam giác theo định dạng (a,b,c) ra màn hình
Áp dụng các hàm xây dựng được, đọc thông tin vào cho các bản ghi, in ra lần lượt
các bộ cạnh tam giác theo thứ tự diện tích tăng dần

Vào:
Gồm 02 dòng, dòng đầu là số bộ số, các dòng tiếp theo là ba bộ số tương ứng là
ba cạnh của tam giác, cách nhau bởi dấu cách

Ra: Các dòng tương ứng các cạnh của tam giác theo thứ tự diện tích tăng dần

Ví dụ:
In:
2
9 9 9
3 4 5

Out:
3 4 5
9 9 9
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned a, b, c;
	double area;
} triangle;

double area(triangle *x) {
	unsigned a = x->a, b = x->b, c = x->c;
	float p = (a + b + c) / 2;
	x->area = sqrt(p * (p - a) * (p - b) * (p - c));
	return x->area;
}

void input(triangle *x) {
	scanf("%u %u %u", &x->a, &x->b, &x->c);
	area(x);
}

int cmp(const void *a, const void *b) {
	triangle c = *(triangle *)a;
	triangle d = *(triangle *)b;
	return c.area - d.area;
}

int main(void) {
	unsigned n, i;
	scanf("%u", &n);
	triangle arr[n];
	for (i = 0; i < n; i++) input(&arr[i]);
	qsort(arr, n, sizeof(triangle), cmp);
	for (i = 0; i < n; i++)
		printf("%u %u %u\n", //
		       arr[i].a, arr[i].b, arr[i].c);
	return 0;
}
