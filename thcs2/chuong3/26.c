#include <stdio.h>

int main() {
	int a, arr[100], i = 0;
	scanf("%d", &a);
	while (a != 1) {
		int flag = 1, num;
		for (int j = 2; j <= a; j++)
			if (!(a % j)) {
				num = j;
				break;
			};
		a /= num;
		for (int j = 0; j < i; j++)
			if (!(num % arr[j])) {
				flag = 0;
				break;
			};
		if (flag) {
			arr[i] = num;
			i++;
		};
	};
	for (int j = 0; j < i; j++) printf("%d ", arr[j]);
	printf("\n");
	return 0;
}
