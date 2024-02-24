#include <stdio.h>
#include <string.h>

typedef unsigned long long u64;

u64 number_of_pair(int *begin, int *end) {

	const size_t distance = end - begin;

	if (distance < 2) return 0;

	int *middle = begin + (distance / 2);

	u64 result = number_of_pair(begin, middle);
	result += number_of_pair(middle, end);

	int merged[distance], *ptr = merged;
	const int *ptr_left = begin, *ptr_right = middle;

	while (1) {

		if (ptr_left == middle) {
			memcpy(ptr, ptr_right, (end - ptr_right) * sizeof(int));
			break;
		}

		if (ptr_right == end) {
			memcpy(ptr, ptr_left, (middle - ptr_left) * sizeof(int));
			break;
		}

		if (*ptr_left > *ptr_right) {

			result += middle - ptr_left;

			*ptr = *ptr_right;
			++ptr_right;

		} else {
			*ptr = *ptr_left;
			++ptr_left;
		}

		++ptr;
	}

	memcpy(begin, merged, sizeof(merged));

	return result;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		size_t size, i;
		scanf("%zu", &size);

		int array[size];
		for (i = 0; i < size; i++) {
			scanf("%d", &array[i]);
		}

		printf("%llu\n", number_of_pair(array, array + size));
		fflush(stdout);
	}

	return 0;
}
