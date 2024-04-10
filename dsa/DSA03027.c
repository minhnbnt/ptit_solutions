#include <stdio.h>
#include <stdlib.h>

int main(void) {

	size_t size, i;
	scanf("%zu", &size);

	int array[size];
	for (i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	}

	long long result = 0;
	for (i = 0; i < size; i++) {
		result += abs(array[i]);
		result += array[i];
	}

	printf("%lld\n", result);
	fflush(stdout);

	return EXIT_SUCCESS;
}
