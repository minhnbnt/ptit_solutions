#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int arr[n], temp = 0;
	for (int i = 0; i < n; i++) {
		int flag = 1;
		scanf("%d", &arr[i]);
		for (int j = 0; j < temp; j++)
			if (arr[j] == arr[i]) flag = 0;
		if (flag) arr[temp++] = arr[i];
	};
	for (int i = 0; i < temp; i++) printf("%d ", arr[i]);
	return 0;
}
