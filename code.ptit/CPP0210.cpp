/*
Cho mảng A[] gồm n số nguyên. Hãy tìm hiệu lớn nhất của bất kể hai phần tử nào
của mảng dãy con thỏa mãn ràng buộc số lớn hơn xuất hiện sau số nhỏ hơn. Nếu
không tìm được cặp phần tử của mảng hãy đưa ra -1. Ví dụ với mảng A[] = {2, 3,
10, 6, 4, 8, 1} ta nhận được kết quả là 8 = 10-2. Với mảng A[] = {7, 9, 5, 6, 3,
2} ta có kết quả là 2 = 9-7.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào n là số phần tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng;
các số được viết cách nhau một vài khoảng trống.

T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^3; 1≤ A[i] ≤10^5;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
7
2 3 10 6 4 8 1
3
3 2 1

Output:
8
-1
*/

#include <iostream>
#include <limits>
#include <vector>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, i, j;
		std::cin >> ele;

		std::vector<i64> vec(ele);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		i64 result = std::numeric_limits<i64>::min();

		for (i = 0; i < ele; ++i)
			for (j = i + 1; j < ele; ++j) {

				if (vec[i] >= vec[j]) {
					continue;
				}

				i64 gap = vec[j] - vec[i];
				if (gap > result) {
					result = gap;
				}
			}

		if (result == std::numeric_limits<i64>::min()) {
			std::cout << -1 << std::endl;
			continue;
		}

		std::cout << result << std::endl;
	}

	return 0;
}
