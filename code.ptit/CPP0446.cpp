/*
Cho mảng A[] gồm n phần tử, hãy tìm cặp phần tử có tổng gần nhất so với 0.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất
đưa vào n là số phần tử của mảng A[]; dòng tiếp theo đưa vào n số A[i]; các số
được viết cách nhau một vài khoảng trống. T, n, A[i] thỏa mãn ràng buộc:
1≤T≤100; 2≤N ≤10^3, -10^6≤A[i] ≤10^6.

Output:
Đưa ra tổng gần nhất với 0 của cặp phần tử.

Input:
2
3
-8 -66 -60
6
-21 -67 -37 -18 4 -65

Output:
-68
-14
*/

#include <iostream>
#include <limits>
#include <vector>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		std::vector<i64> vec(ele);
		for (i64 &i : vec) {
			std::cin >> i;
		}

		i64 result = std::numeric_limits<i64>::max();

		unsigned i, j;
		for (i = 0; i < ele; ++i)
			for (j = i + 1; j < ele; ++j) {

				i64 sum = vec[i] + vec[j];

				if (std::abs(sum) < std::abs(result)) {
					result = sum;
				}
			}

		std::cout << result << std::endl;
	}

	return 0;
}
