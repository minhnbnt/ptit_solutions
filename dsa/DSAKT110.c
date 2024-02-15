#include <stdio.h>

#define max(a, b) a > b ? a : b

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases-- > 0) {

		size_t size, i;
		scanf("%zu", &size);

		int array[size];
		for (i = 0; i < size; i++) {
			scanf("%d", &array[i]);
		}

		typedef long long i64;

		i64 if_take = array[0], if_ignore = 0;
		i64 result = max(if_take, if_ignore);

		for (i = 1; i < size; i++) {

			if_take = if_ignore + array[i];
			if_ignore = result;

			result = max(if_take, if_ignore);
		}

		printf("%lld\n", result);
	}

	return 0;
}
