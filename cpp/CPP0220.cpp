/*
Cho ma trận vuông A[N][N]. Hãy in các phần tử thuộc vùng biên.

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
4
1 2 3 4 5 6 7 8 1 2 3 4 5 6 7 8
3
45 48 54 21 89 87 70 78 15

Output:
1 2 3 4
5     8
1     4
5 6 7 8
45 48 54
21   87
70 78 15
*/

#include <iostream>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned rank, i, j;
		std::cin >> rank;

		int arr[rank][rank];
		for (i = 0; i < rank; ++i)
			for (int &x : arr[i]) {
				std::cin >> x;
			}

		for (i = 0; i < rank; ++i) {
			for (j = 0; j < rank; ++j) {
				if (i != 0 && j != 0 && i != rank - 1 && j != rank - 1) {
					std::cout << "  ";
					continue;
				}

				std::cout << arr[i][j] << ' ';
			}

			std::cout.put(0xa);
		}

		std::cout.flush();
	}

	return 0;
}
