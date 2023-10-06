#include <math.h>
#include <stdio.h>

typedef struct {
	int x, y;
} Point;

const double distance(Point a, Point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

const double area_of_triangle(Point a, Point b, Point c) {

	const double ab = distance(a, b);
	const double ac = distance(a, c);
	const double bc = distance(b, c);

	const double P = (ab + ac + bc) / 2;

	return sqrt(P * (P - ab) * (P - bc) * (P - ac));
}

const double area_of(Point *arr, size_t points) {

	double result = 0;

	for (size_t i = 1; i < points - 1; ++i) {
		result += area_of_triangle(arr[0], arr[i], arr[i + 1]);
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
