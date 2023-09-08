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
