/*
Cho N số nguyên. Nhiệm vụ của bạn là phân tích các số nguyên đã cho dưới dạng
tích của các thừa số nguyên tố, sau đó tính tổng các ước số nguyên tố này.

Input:

Dòng đầu tiên số nguyên N (1 ≤ N ≤ 10^6).
N dòng tiếp theo, mỗi dòng gồm một số nguyên có giá trị không vượt quá 2*10^6.
Output:

In ra một số nguyên là đáp án tìm được.

Ví dụ:
Input:
5
7
9
10
13
100

Output:
47

Giải thích test:
7 = 7
9 = 3 x 3 à 3 + 3 = 6
10 = 2 x 5 à 2 + 5 = 7
13 = 13
100 = 2 x 2 x 5 x 5 à 2+2+5+5 = 14
Cộng lại, 7 + 6 + 7 + 13 + 14 = 47.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	long n;
	scanf("%ld", &n);
	long a[n], max = a[0], sum = 0;
	for (long i = 0; i < n; i++) {
		scanf("%ld", &a[i]);
		if (a[i] > max) max = a[i];
	};
	long *arr = calloc(max + 1, sizeof(long));
	for (long i = 2; i <= max; i++)
		if (!arr[i]) {
			long interval = i;
			while (interval <= max) {
				for (long j = interval; j <= max; j += interval) {
					arr[j] += i;
				}
				interval *= i;
			};
		};
	for (long i = 0; i < n; i++) sum += arr[a[i]];
	printf("%ld\n", sum);
	return 0;
}
