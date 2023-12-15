/*
Cho ba điểm A, B, C trong không gian hai chiều 0xy.

Hãy tính diện tích hình tròn ngoại tiếp tam giác tạo bởi 3 điểm trên.

Input
Dòng đầu ghi số bộ test (không quá 20).
Mỗi bộ test ghi trên 1 dòng 6 số thực lần lượt là tọa độ của 3 điểm A, B, C. Giá trị tọa độ không
quá 1000.

Output
Nếu 3 điểm không thể tạo thành tam giác, in ra INVALID
Nếu 3 điểm tạo thành tam giác, in ra diện tích hình tròn ngoại tiếp với độ chính xác 3 số phần thập
phân.

Ví dụ
Input
3
0 0 0 5 0 199
1 1 1 1 1 1
0 0 0 5 5 0

Output
INVALID
INVALID
39.270
*/

#include <math.h>
#include <stdio.h>

typedef struct {
	double x, y;
} Point;

double distance(Point a, Point b) {
	const double dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(pow(dx, 2) + pow(dy, 2));
}

double area(double ab, double bc, double ac) {

	if (ab + bc <= ac || ab + ac <= bc || ac + bc <= ab) {
		return -1;
	}

	const double p = (ab + bc + ac) / 2;

	return sqrt(p * (p - ab) * (p - bc) * (p - ac));
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		Point a, b, c;
		scanf("%lf%lf", &a.x, &a.y);
		scanf("%lf%lf", &b.x, &b.y);
		scanf("%lf%lf", &c.x, &c.y);

		const double ab = distance(a, b);
		const double bc = distance(b, c);
		const double ac = distance(a, c);

		const double S = area(ab, bc, ac);

		if (S < 0) {
			puts("INVALID");
			fflush(stdout);

			continue;
		}

		const double r = ab * bc * ac / (4 * S);

		printf("%.3f\n", r * r * M_PI);
		fflush(stdout);
	}

	return 0;
}
