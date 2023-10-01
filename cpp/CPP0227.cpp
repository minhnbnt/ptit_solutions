/*
Cho ma trận vuông A[N][N]. Hãy in các phần tử thuộc theo hình con rắn.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào N là cấp của ma trận A[N][N]; dòng tiếp theo đưa vào N×N số A[i][j] ;
các số được viết cách nhau một vài khoảng trống.
T, N, A[i][j] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ N ≤100; 1≤ A[i][j] ≤150.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
Input:
2
3
45 48 54 21 89 87 70 78 15
2
25 27 23 21

Output:
45 48 54 87 89 21 70 78 15
25 27 21 23
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

		unsigned rank, i;
		std::cin >> rank;

		std::vector<std::vector<int>> vec(rank);
		for (i = 0; i < rank; ++i) {

			vec[i].resize(rank);

			for (int &x : vec[i]) {
				std::cin >> x;
			}

			if (i % 2 == 1) {
				std::reverse(vec[i].begin(), vec[i].end());
			}
		}

		for (const std::vector<int> &row : vec)
			for (const int &x : row) {
				std::cout << x << ' ';
			}
		std::cout << std::endl;
	}

	return 0;
}
