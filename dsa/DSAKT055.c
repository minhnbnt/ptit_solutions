#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	int price, weight;
} Item;

int main() {

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

		int dp[capacity + 1][number_of_item + 1];
		memset(dp[0], 0, sizeof(int) * number_of_item);

		for (i = 1; i <= capacity; i++) {

			dp[i][0] = 0;

			for (j = 1; j <= number_of_item; j++) {

				dp[i][j] = dp[i][j - 1];

				const Item current_item = items[j - 1];

				const int weight_remaining = i - current_item.weight;

				if (weight_remaining < 0) {
					continue;
				}

				const int price_if_take =
				    dp[weight_remaining][j - 1] + current_item.price;
				if (price_if_take > dp[i][j]) {
					dp[i][j] = price_if_take;
				}
			}
		}

		printf("%d\n", dp[capacity][number_of_item]);
	}
}
