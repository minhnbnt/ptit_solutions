/*
Cho k mảng mỗi mảng gồm n phần tử đã được sắp xếp. Hãy đưa ra kết quả là một dãy
đã được sắp xếp. Ví dụ với k = 3, n=4 và mảng

A[] = { {1, 3,  5,  7},
        {2, 4,  6,  8},
        {0, 9, 10, 11} };

sẽ cho ta kết quả A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất
dòng thứ nhất đưa là hai số k, n; k dòng tiếp, mỗi dòng gồm n số của mảng
A[k][n]. Các số được viết cách nhau một vài khoảng trống.

T, n, k, A[i][j] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤103; 1≤ k ≤10; 1≤ A1[i][j]
≤10^6.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
3 4
1 3 5 7
2 4 6 8
0 9 10 11

Output:
0 1 2 3 4 5 6 7 8 9 10 11
*/

#include <deque>
#include <iostream>
#include <limits>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ndeq, ele, i;
		std::cin >> ndeq >> ele;

		std::deque<std::deque<i64>> deqs(ndeq, std::deque<i64>(ele));
		for (std::deque<i64> &deq : deqs)
			for (i64 &x : deq) {
				std::cin >> x;
			}

		std::deque<i64> base;
		while (true) {

			size_t pos;
			i64 min = std::numeric_limits<i64>::max();

			for (i = 0; i < ndeq; ++i) {

				if (deqs[i].empty()) {
					continue;
				}

				if (deqs[i].front() < min) {
					min = deqs[i].front();
					pos = i;
				}
			}

			if (min == std::numeric_limits<i64>::max()) {
				break;
			}

			base.push_back(deqs[pos].front());
			deqs[pos].pop_front();
		}

		for (const i64 &x : base) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
