#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	int *array;
	size_t size, capacity;

	size_t begin, end;

} Deque;

Deque Deque_new(void) {

	Deque new_deque = { .array = (int *)malloc(sizeof(int) * 10),
		                .size = 0,
		                .capacity = 10,
		                .begin = 0,
		                .end = 0 };

	return new_deque;
}

int *Deque_get(Deque *dq, size_t index) {

	if (index >= dq->size) {
		return NULL;
	}

	const size_t array_index = (dq->begin + index) % dq->capacity;
	return dq->array + array_index;
}

int *Deque_get_back(Deque *dq) {

	if (dq->size == 0) {
		return NULL;
	}

	if (dq->end == 0) {
		return dq->array + dq->capacity - 1;
	}

	return dq->array + dq->end - 1;
}

void Deque_grow(Deque *dq) {

	const size_t new_capacity = dq->capacity * 1.6;

	int *new_array = (int *)malloc(sizeof(int) * new_capacity);
	for (size_t i = 0; i < dq->size; i++) {
		new_array[i] = *Deque_get(dq, i);
	}

	free(dq->array);

	dq->array = new_array;
	dq->capacity = new_capacity;

	dq->begin = 0, dq->end = dq->size;
}

void Deque_push_back(Deque *dq, int value) {

	if (dq->size == dq->capacity) {
		Deque_grow(dq);
	}

	dq->array[dq->end] = value;

	++dq->end, ++dq->size;
	dq->end %= dq->capacity;
}

void Deque_pop_back(Deque *dq) {

	if (dq->size == 0) {
		return;
	}

	if (dq->end == 0) {
		dq->end = dq->capacity;
	}

	--dq->end, --dq->size;
}

void Deque_push_front(Deque *dq, int value) {

	if (dq->size == dq->capacity) {
		Deque_grow(dq);
	}

	if (dq->begin == 0) {
		dq->begin = dq->capacity;
	}

	--dq->begin, ++dq->size;

	dq->array[dq->begin] = value;
}

void Deque_pop_front(Deque *dq) {

	if (dq->size == 0) {
		return;
	}

	--dq->size, ++dq->begin;

	if (dq->begin == dq->capacity) {
		dq->begin = 0;
	}
}

void Deque_free(Deque *dq) {
	free(dq->array);
}

int main(void) {

	__attribute__((cleanup(Deque_free))) // RAII
	Deque dq = Deque_new();

	unsigned queries;
	scanf("%u", &queries);

	while (queries--) {

		char command[21];
		scanf("%*c%20s", command);

		if (strcmp(command, "PUSHBACK") == 0) {

			int new_element;
			scanf("%d", &new_element);

			Deque_push_back(&dq, new_element);
			continue;
		}

		if (strcmp(command, "PUSHFRONT") == 0) {

			int new_element;
			scanf("%d", &new_element);

			Deque_push_front(&dq, new_element);
			continue;
		}

		if (strcmp(command, "POPBACK") == 0) {
			Deque_pop_back(&dq);
			continue;
		}

		if (strcmp(command, "POPFRONT") == 0) {
			Deque_pop_front(&dq);
			continue;
		}

		if (strcmp(command, "PRINTFRONT") == 0) {

			const int *front = Deque_get(&dq, 0);

			if (front != NULL) {
				printf("%d\n", *front);
			} else {
				puts("NONE");
			}

			continue;
		}

		if (strcmp(command, "PRINTBACK") == 0) {

			const int *back = Deque_get_back(&dq);

			if (back != NULL) {
				printf("%d\n", *back);
			} else {
				puts("NONE");
			}
		}
	}

	return 0;
}
