/*
Cho ma trận vuông A[][] cấp n. Các phần tử của ma trận A[][] đã được sắp xếp
theo hàng, cột. Hãy tìm phần nhỏ nhất thứ k của ma trận. Ví dụ với ma trận cấp 4
dưới đây sẽ cho ta số nhỏ nhất thứ 3 là 20, số nhỏ nhất thứ 7 là 30.

10 20 30 40
15 25 35 45
24 29 37 48
32 33 39 50

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là
n và k; phần thứ hai là n2 các phần tử của ma trận vuông A[][]; các số được viết
cách nhau một vài khoảng trống.

T, n, k, A[i][i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤100; 1≤ k, A[i][j] ≤10^4;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
4 7
10 20 30 40
15 25 35 45
24 29 37 48
32 33 39 50

Output:
30
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned rank, target;
		std::cin >> rank >> target;

		std::vector<int> vec(rank * rank);
		for (int &x : vec) {
			std::cin >> x;
		}

		std::sort(vec.begin(), vec.end());

		std::cout << vec.at(target - 1) << std::endl;
	}

	return 0;
}
