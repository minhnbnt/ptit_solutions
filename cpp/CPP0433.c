#include <stdio.h>
#include <stdlib.h>

typedef struct __node {

	long long value;
	size_t appear;

	struct __node *next;

} Node;

typedef struct {

	Node **bucket;
	size_t bucket_size;

} Hash_map;

void Hash_map_init(Hash_map *map) {

	const size_t size = map->bucket_size;
	map->bucket = (Node **)calloc(size, sizeof(Node *));
}

void free_node(Node *current) {

	while (current != NULL) {

		Node *next = current->next;

		free(current);
		current = next;
	}
}

void add_element(Hash_map *map, long long value) {

	const size_t index = value % map->bucket_size;

	Node *target = map->bucket[index];

	while (target != NULL) {

		if (target->value == value) {
			++target->appear;
			return;
		}

		target = target->next;
	}

	target = (Node *)malloc(sizeof(Node));

	target->value = value;
	target->appear = 1;
	target->next = map->bucket[index];

	map->bucket[index] = target;
}

inline int comparator(const void *a, const void *b) {

	Node *left = *(Node **)a, *right = *(Node **)b;

	if (left->appear < right->appear) {
		return 1;
	}

	return left->value > right->value;
}

int main(void) {

	Hash_map map;
	map.bucket_size = 1000;

	Hash_map_init(&map);

	unsigned cases;
	scanf("%u", &cases);

	while (cases-- > 0) {

		size_t ele;
		scanf("%zu", &ele);

		while (ele-- > 0) {

			long long value;
			scanf("%lld", &value);

			add_element(&map, value);
		}

		size_t i, size = 0, capacity = 5;
		Node **arr = (Node **)malloc(sizeof(Node *) * capacity);

		for (i = 0; i < map.bucket_size; ++i) {

			Node *target = map.bucket[i];

			while (target != NULL) {

				if (size == capacity) {
					capacity *= 1.6;
					arr = (Node **)realloc(arr, sizeof(Node *) * capacity);
				}

				arr[size] = target;
				++size;

				target = target->next;
			}
		}

		qsort(arr, size, sizeof(Node *), comparator);

		for (i = 0; i < size; ++i) {

			size_t appear = arr[i]->appear;
			const long long value = arr[i]->value;

			while (appear-- > 0) {
				printf("%lld ", value);
			}
		}
		putchar('\n');

		free(arr);

		for (i = 0; i < map.bucket_size; ++i) {
			free_node(map.bucket[i]);
			map.bucket[i] = NULL;
		}
	}

	free(map.bucket);

	return 0;
}
