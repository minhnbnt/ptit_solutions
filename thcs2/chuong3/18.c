#include <stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	int flag = 0;
	while (a) {
		int num = a % 10;
		if (num) flag = 1;
		if (flag) printf("%d", num);
		a /= 10;
	};
	printf("\n");
	return 0;
}
