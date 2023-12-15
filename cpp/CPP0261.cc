/*
Cho ma trận vuông A cỡ N*N. Một ma trận vuông B nhỏ hơn cỡ M*M có thể dùng làm “cửa sổ trượt” trên
ma trận A nếu M là ước số của N.

Hãy thực hiện tính tích chập của ma trận B với từng “khung cửa số” tương ứng trên ma trận A. Tích
chập được hiểu là tính giá trị tích từng vị trí tương ứng trên 2 ma trận kích thước bằng nhau.

Xem ví dụ để hiểu rõ hơn.

Input
Dòng đầu ghi số N (3 < N < 100) . Tiếp theo là N dòng ghi ma trận A. Các giá trị đều nguyên dương và
không quá 1000.
Tiếp theo là một dòng ghi số M (1 < M <10). Tiếp theo là M dòng ghi ma trận B. Các giá trị lớn hơn
hoặc bằng 0 và không quá 20.
Dữ liệu vào đảm bảo M là ước số của N.

Output

Ghi ra N dòng mô tả ma trận kết quả.

Ví dụ
Input
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
1 0
0 2

Output
1 0 3 0
0 12 0 16
9 0 11 0
0 28 0 32
*/

#include <iostream>
#include <vector>

int main(void) {

	using i64 = long long;

	unsigned rank1;
	std::cin >> rank1;

	std::vector<std::vector<i64>> vec1(rank1);
	for (std::vector<i64> &v : vec1) {
		v = std::vector<i64>(rank1);
		for (i64 &x : v) {
			std::cin >> x;
		}
	}

	unsigned rank2;
	std::cin >> rank2;

	std::vector<std::vector<int>> vec2(rank2);
	for (std::vector<int> &v : vec2) {
		v = std::vector<int>(rank2);
		for (int &x : v) {
			std::cin >> x;
		}
	}

	for (unsigned i = 0; i < rank1; ++i) {
		for (unsigned j = 0; j < rank1; ++j) {
			vec1[i][j] *= vec2[i % rank2][j % rank2];
		}
	}

	for (const std::vector<i64> &v : vec1) {
		for (const i64 &x : v) {
			std::cout << x << ' ';
		}
		std::cout.put(0xa);
	}
	std::cout.flush();

	return 0;
}
