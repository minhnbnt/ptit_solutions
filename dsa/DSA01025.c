#include <stdio.h>
#include <stdlib.h>

char *print;
size_t size = 0;

void generate_name(const char *begin, const char *end, size_t length) {

	if (size == length) {
		puts(print);
		return;
	}

	while (begin != end) {

		print[size] = *begin;
		++begin, ++size;

		generate_name(begin, end, length);

		--size;
	}
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases-- > 0) {

		size_t size, name_length;
		scanf("%zu%zu", &size, &name_length);

		char *array = (char *)malloc(sizeof(char) * size);

		print = (char *)malloc(sizeof(char) * (name_length) + 1);
		print[name_length] = '\0';

		for (size_t i = 0; i < size; i++) {
			array[i] = 'A' + i;
		}

		generate_name(array, array + size, name_length);

		free(print);
		free(array);
	}

	return 0;
}
