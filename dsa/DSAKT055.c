#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int price, weight;
} Item;

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases-- > 0) {

		int number_of_item, capacity, i, j;
		scanf("%d%d", &number_of_item, &capacity);

		Item items[number_of_item];
		for (i = 0; i < number_of_item; i++) {
			scanf("%d", &items[i].weight);
		}
		for (i = 0; i < number_of_item; i++) {
			scanf("%d", &items[i].price);
		}

		int *dp[number_of_item];
		dp[0] = (int *)calloc(capacity + 1, sizeof(int));

		for (i = 1; i <= number_of_item; i++) {

			dp[i] = (int *)malloc((capacity + 1) * sizeof(int));
			dp[i][0] = 0;

			const Item *current_item = &items[i - 1];

			for (j = 1; j <= capacity; j++) {

				dp[i][j] = dp[i - 1][j];

				const int capacity_if_take = j - current_item->weight;
				if (capacity_if_take < 0) continue;

				const int price_if_take =
				    dp[i - 1][capacity_if_take] + current_item->price;

				if (price_if_take > dp[i][j]) {
					dp[i][j] = price_if_take;
				}
			}

			free(dp[i - 1]);
		}

		free(dp[number_of_item]);

		printf("%d\n", dp[number_of_item][capacity]);
		fflush(stdout);
	}

	return 0;
}
