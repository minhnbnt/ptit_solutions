/*
Cho 2 điểm A  và B trong không gian Oxy. Hãy tính khoảng cách giữa hai điểm đó.

Input

Dòng đầu ghi số bộ test, không quá 20.
Mỗi bộ test có 4 số thực lần lượt là tọa độ của 2 điểm A và B, giá trị tuyệt đối
không quá 1000. Ouput

Với mỗi bộ test, viết ra khoảng cách giữa 2 điểm với 4 chữ số sau dấu phẩy.

Ví dụ:
Input:
2
0 0 0 5
0 199 5 6

Output:
5.0000
193.0648
*/

#include <math.h>
#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		double a_x, a_y;
		scanf("%lf%lf", &a_x, &a_y);

		double b_x, b_y;
		scanf("%lf%lf", &b_x, &b_y);

		double distance = sqrt(pow(a_x - b_x, 2) + pow(a_y - b_y, 2));

		printf("%.4lf\n", distance);

		fflush(stdout);
	}

	return 0;
}
