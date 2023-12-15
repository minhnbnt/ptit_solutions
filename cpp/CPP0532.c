/*
Cho một đa giác lồi có N đỉnh trên mặt phẳng Oxy.

Nhiệm vụ của bạn là hãy tính diện tích đa giác này.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
Mỗi test bắt đầu bởi số nguyên N (N ≤ 1000).
N dòng tiếp theo, mỗi dòng gồm 2 số nguyên x[i], y[i] (-1000 ≤ x[i], y[i] ≤ 1000) là tọa độ của điểm
thứ i. Các điểm được liệt kê theo thứ tự ngược chiều quay kim đồng hồ.

Output:
Với mỗi test, in ra đáp án tìm được trên một dòng.

Input:
2
3
0 0
1 0
0 1
4
0 0
2 0
2 2
0 2

Output:
0.500
4.000
*/

#include <math.h>
#include <stdio.h>

typedef struct {
	int x, y;
} Point;

double distance(Point a, Point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double area_of_triangle(Point a, Point b, Point c) {

	const double ab = distance(a, b);
	const double ac = distance(a, c);
	const double bc = distance(b, c);

	const double P = (ab + ac + bc) / 2;

	return sqrt(P * (P - ab) * (P - bc) * (P - ac));
}

double area_of(const Point *arr, size_t points) {

	double result = 0;

	for (size_t i = 2; i < points; ++i) {
		result += area_of_triangle(arr[0], arr[i], arr[i - 1]);
	}

	return result;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		size_t points, i;
		scanf("%zu", &points);

		Point arr[points];
		for (i = 0; i < points; ++i) {
			scanf("%d%d", &arr[i].x, &arr[i].y);
		}

		printf("%.3lf\n", area_of(arr, points));
		fflush(stdout);
	}

	return 0;
}
