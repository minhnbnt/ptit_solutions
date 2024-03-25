#include <stdio.h>
#include <string.h>

typedef struct {

	unsigned price;
	unsigned weight;

} Item;

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned number_of_item, capacity, i, j;
		scanf("%u%u", &number_of_item, &capacity);

		Item items[number_of_item];
		for (i = 0; i < number_of_item; i++) {
			scanf("%u", &items[i].weight);
		}
		for (i = 0; i < number_of_item; i++) {
			scanf("%u", &items[i].price);
		}

		unsigned dp[capacity + 1];
		memset(dp, 0, sizeof(dp));

		for (i = 0; i < number_of_item; i++) {

			unsigned prev_dp[capacity + 1];
			memcpy(prev_dp, dp, sizeof(dp));

			for (j = items[i].weight; j <= capacity; j++) {

				const unsigned capacity_remaining = j - items[i].weight;
				const unsigned price_if_take =
				    prev_dp[capacity_remaining] + items[i].price;

				if (price_if_take > dp[j]) {
					dp[j] = price_if_take;
				}
			}
		}

		printf("%u\n", dp[capacity]);
		fflush(stdout);
	}

	return 0;
}
