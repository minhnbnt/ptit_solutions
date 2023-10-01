/*
Cho mảng A[] gồm n số chưa được sắp xếp. Hãy tìm Min(A[i]-A[j]) : i ≠j và i, j
=0, 1, 2, .., n-1. Ví dụ với A[] = {1, 5, 3, 19, 18, 25} ta có kết quả là 1 =
19-18. với A[] = {1, 19, -4, 31, 28, 35, 100} ta có kết quả là 3 = 31-28.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là
số phần tử của mảng n; dòng tiếp theo là n số A[i] của mảng A[]; các số được
viết cách nhau một vài khoảng trống. T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100;
1≤ n ≤10^3; -10^3≤ A[i]  ≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5
2 4 5 7 9
10
87 32 99 75 56 43 21 10 68 49

Output:
1
6
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele, i;
		std::cin >> ele;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		std::sort(vec.begin(), vec.end());

		unsigned result = std::numeric_limits<unsigned>::max();
		for (i = 1; i < ele; ++i) {
			unsigned gap = vec[i] - vec[i - 1];
			if (gap < result) {
				result = gap;
			}
		}

		std::cout << result << std::endl;
	}

	return 0;
}
