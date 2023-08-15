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
