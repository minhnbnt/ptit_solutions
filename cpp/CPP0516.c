#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	unsigned id;
	double profit;
	char *name, *category;
} Item;

void input(Item *it) {

	static unsigned id = 0;
	it->id = ++id;

	getchar();

	size_t size = 0;
	getline(&it->name, &size, stdin);
	strtok(it->name, "\n");

	size = 0;
	getline(&it->category, &size, stdin);
	strtok(it->category, "\n");

	double buy, sell;
	scanf("%lf%lf", &buy, &sell);

	it->profit = sell - buy;
}

int comparator(const void *a, const void *b) {

	const Item *it1 = (Item *)a, *it2 = (Item *)b;

	return it1->profit < it2->profit;
}

int main(void) {

	size_t ele, i;
	scanf("%zu", &ele);

	Item arr[ele];
	for (i = 0; i < ele; ++i) {
		input(arr + i);
	}

	qsort(arr, ele, sizeof(Item), comparator);

	for (i = 0; i < ele; ++i) {

		printf("%u %s %s %.2lf\n", //
		       arr[i].id, arr[i].name, arr[i].category, arr[i].profit);

		free(arr[i].name), free(arr[i].category);
	}

	fflush(stdout);

	return 0;
}
