/*
Cho mảng A[] gồm n phần tử. Nhiệm vụ của bạn là hãy sắp đặt lại các phần tử của mảng sao cho A[i] =
i. Nếu phần tử A[j] của có giá trị khác j, hãy đưa ghi vào -1. Ví dụ với mảng A[] = {-1,-1,6,1,9, 3,
2, -1, 4, -1} ta có kết quả A[] = {-1, 1, 2, 3, 4, -1, 1, -1, -1, 9}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần
tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng; các số được viết cách nhau một vài khoảng
trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤107; 1≤ A[i] ≤1018;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
10
-1 -1 6 1 9 3 2 -1 4 -1
6
0 -3 1 -2 3 -4

Output:
-1 1 2 3 4 -1 6 -1 -1 9
0 1 -1 3 -1 -1
*/

#include <iostream>
#include <unordered_set>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		using i64 = long long;

		size_t ele, i;
		std::cin >> ele;

		std::vector<i64> vec(ele);
		std::unordered_set<i64> set;
		for (i64 &x : vec) {

			std::cin >> x;

			if (x >= 0) {
				set.insert(x);
			}
		}

		for (i = 0; i < ele; ++i) {

			if (set.find(i) != set.end()) {
				std::cout << i << ' ';
				continue;
			}

			std::cout << "-1 ";
		}

		std::cout << std::endl;
	}

	return 0;
}
