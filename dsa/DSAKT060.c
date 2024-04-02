#include <stdio.h>
#include <stdlib.h>

char *input(void);

int main(void) {

	char *target = input();

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		char command;
		scanf("%*c%c", &command);

		if (command == 'c') {

			size_t pos;
			char new_char;
			scanf("%zu%*c%c", &pos, &new_char);

			target[pos - 1] = new_char;

			continue;
		}

		size_t left, right;
		scanf("%zu%zu", &left, &right);

		char result = 1;

		left -= 1, right -= 1;

		while (left < right) {

			if (target[left] != target[right]) {
				result = 0;
				break;
			}

			left++, right--;
		}

		puts(result ? "YES" : "NO");
	}

	return EXIT_SUCCESS;
}

#define INITIAL_CAPACITY 5

char *input(void) {

	char *result = (char *)calloc(INITIAL_CAPACITY, sizeof(char));
	size_t size = 0, capacity = INITIAL_CAPACITY;

	while (1) {

		const char c = getchar();

		if (size == capacity) {
			capacity *= 1.6;
			result = (char *)realloc(result, sizeof(char) * capacity);
		}

		if (c == '\n') {
			result[size] = 0;
			return result;
		}

		result[size] = c;
		size++;
	}
}
