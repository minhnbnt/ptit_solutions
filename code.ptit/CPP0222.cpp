/*
Cho ma trận vuông A[][] cấp N. Nhiệm vụ của bạn là đưa ra số các phần tử giống
nhau ở tất cả các hàng. Ví dụ với ma trận A[][] dưới đây sẽ cho ta kết quả là 2
tương ứng với số 2, 3 xuất hiện ở tất cả các hàng.

2  1  4  3
1  2  3  2
3  6  2  3
5  2  5  3

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào N là cấp của ma trận A[][]; dòng tiếp theo đưa vào N×N số A[i][j] ; các
số được viết cách nhau một vài khoảng trống.

T, N, A[i][j] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ N ≤100; 1≤ A[i][j] ≤10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
4
2 1 4 3 1 2 3 2 3 6 2 3 5 2 5 3

Output:
2
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned rank, i;
		std::cin >> rank;

		std::unordered_map<i64, unsigned> map;
		for (i = 0; i < rank; ++i) {

			std::unordered_set<i64> set;
			unsigned remaining = rank;
			while (remaining--) {

				i64 input;
				std::cin >> input;

				set.insert(input);
			}

			for (const i64 &x : set) {
				++map[x];
			}
		}

		unsigned result = 0;
		for (const std::pair<i64, unsigned> &pr : map)
			if (pr.second == rank) ++result;

		std::cout << result << std::endl;
	}

	return 0;
}
