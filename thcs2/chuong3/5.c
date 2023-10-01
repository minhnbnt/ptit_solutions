#include <math.h>
#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int delta = b * b - 4 * a * c;
	if (delta < 0) {
		printf("NO\n");
	} else if (delta) {
		float x1 = -b - sqrt(delta) / (2 * a);
		float x2 = -b + sqrt(delta) / (2 * a);
		printf("%.2f %.2f\n", x1, x2);
	} else {
		float x = -b / (2 * a);
		printf("%.2f\n", x);
	};
	return 0;
}
