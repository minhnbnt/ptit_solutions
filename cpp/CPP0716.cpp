/*
Cho ma trận vuông A[N][N] gồm các số nguyên dương và số tự nhiên K. Hãy tìm số
các cách di chuyển từ phần tử đầu tiên (A[0][0] đến phần tử cuối cùng
A[N-1][N-1] sao cho tổng các phần tử của phép di chuyển đúng bằng K. Biết từ
phần tử A[i][j], ta chỉ được phép dịch chuyển đến phần tử A[i+1][j] hoặc
A[i][j+1]. Ví dụ với ma trận dưới đây sẽ có 2 phép di chuyển theo nguyên tắc kể
trên để có tổng bằng 12.

1  2  3
4  6  5      Cách 1: 1 -> 2 -> 6 -> 2 -> 1
3  2  1      Cách 2: 1 -> 2 -> 3 -> 5 -> 1

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: Dòng đầu tiên
đưa vào hai số N, K ; dòng tiếp là N×N các phần tử của ma trận A[][]; các phần
tử được viết cách nhau một vài khoảng trống.

T, N, A[i][j] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N ≤20; 1≤ A[i][j] ≤200.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
Input:
2
3 16
1 2 3
4 6 5
9 8 7

3 12
1 2 3
4 6 5
3 2 1

Output:
0
2
*/

#include <iostream>
#include <vector>

using u64 = unsigned long long;

u64 count(std::vector<std::vector<int>> &vec, int x, int y, u64 target) {

	const size_t &rank = vec.size();

	if (x >= rank || y >= rank) return 0;

	if (target < vec[x][y]) return 0;

	target -= vec[x][y];

	if (target == 0 && x == rank - 1 && y == rank - 1) {
		return 1;
	}

	return count(vec, x + 1, y, target) + count(vec, x, y + 1, target);
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 target;
		unsigned rank;
		std::cin >> rank >> target;

		std::vector<std::vector<int>> vec(rank);
		for (std::vector<int> &v : vec) {
			v = std::vector<int>(rank);
			for (int &x : v) {
				std::cin >> x;
			}
		}

		std::cout << count(vec, 0, 0, target) << std::endl;
	}

	return 0;
}
