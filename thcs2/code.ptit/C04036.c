/*
Tại ngân hàng có các mệnh giá bằng 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, số
lượng tờ tiền mỗi mệnh giá là không hạn chế. Một người cần đổi số tiền có giá
trị bằng N. Hãy xác định xem số tờ tiền ít nhất sau khi đổi là bao nhiêu?

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 50). Mỗi test gồm 1 số nguyên N
(1 ≤ N ≤ 100000). Output: Với mỗi test, in ra đáp án trên một dòng.

Test ví dụ:
Input:
2
70
121

Output:
2
3
*/

#include <stdio.h>

int main() {
	int arr[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000 };
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		unsigned long money;
		scanf("%lu", &money);
		unsigned count = 0;
		for (int i = 9; i >= 0; i--) {
			count += money / arr[i];
			money = money % arr[i];
		}
		printf("%u\n", count);
	}
	return 0;
}
