/*
Cho ma trận A[N][M] bao gồm các số 0 và 1. Ta gọi mỗi miền của ma trận A[][] là
nhóm các số 1 được bao quanh bởi các số 0. Hãy tìm số miền của ma trận. Ví dụ số
miền của ma trận A[][] là 4.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào N, M là cấp của ma trận A[][]; dòng tiếp theo đưa vào N×M số A[i][j];
các số được viết cách nhau một vài khoảng trống.
T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ M, N ≤100; 0≤ A[i][j] ≤1.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
3 3
1 1 0 0 0 1 1 0 1
4 4
1 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0

Output:
2
2
*/

#include <iostream>
#include <vector>

void spread(std::vector<std::vector<bool>> &vec, int x, int y) {

	const size_t &row = vec.size(), &col = vec[0].size();

	static const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	if (vec[x][y] == false) {
		return;
	}

	vec[x][y] = false;

	for (int i = 0; i < 8; ++i) {

		const int _x = x + dx[i], _y = y + dy[i];

		if (_x >= 0 && _x < col && _y >= 0 && _y < row) {
			spread(vec, _x, _y);
		}
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		int row, col, i, j;
		std::cin >> row >> col;

		std::vector<std::vector<bool>> vec(row);
		for (std::vector<bool> &v : vec)
			for (i = 0; i < col; ++i) {

				bool b;
				std::cin >> b;

				v.push_back(b);
			}

		unsigned long long count = 0;
		for (i = 0; i < row; ++i)
			for (j = 0; j < col; ++j) {

				if (!vec[i][j]) {
					continue;
				}

				++count;

				spread(vec, i, j);
			}

		std::cout << count << std::endl;
	}

	return 0;
}
