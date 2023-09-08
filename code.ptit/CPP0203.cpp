/*
Cho mảng A[] gồm n số nguyên bao gồm cả số 0. Nhiệm vụ của bạn là tìm số nguyên
dương nhỏ nhất không có mặt trong mảng. Ví dụ với mảng A[] = {5, 8, 3, 7, 9, 1},
ta có kết quả là 2.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào n là số phần tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng;
các số được viết cách nhau một vài khoảng trống.

T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤106; -10^6≤ A[i] ≤10^6;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20

Output:
6
2
*/

#include <iostream>
#include <unordered_set>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, i;
		std::cin >> ele;
		std::unordered_set<i64> set;

		for (i = 0; i < ele; ++i) {

			i64 x;
			std::cin >> x;

			set.insert(x);
		}

		i = 1;
		while (set.find(i) != set.end()) ++i;

		std::cout << i << std::endl;
	}

	return 0;
}
