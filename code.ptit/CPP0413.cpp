/*
Cho mảng A[] gồm n số nguyên khác nhau. Hãy đưa ra các phần tử của mảng theo
khuôn dạng lớn nhất, nhỏ nhất, lớn thứ hai, nhỏ thứ 2, … Ví dụ với A[] = {9, 7,
12, 8, 6, 5} ta đưa ra : 12, 5, 9, 6, 8, 7.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là
số phần tử của mảng n; dòng tiếp theo là n số A [i] của mảng A [];các số được
viết cách nhau một vài khoảng trống.
T, n thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
Input:
2
7
7 1 2 3 4 5 6
8
1 6 9 4 3 7 8 2

Output:
7 1 6 2 5 3 4
9 1 8 2 7 3 6 4
*/

#include <algorithm>
#include <deque>
#include <iostream>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		std::deque<int> deq(ele);
		for (int &x : deq) {
			std::cin >> x;
		}

		std::sort(deq.begin(), deq.end());

		unsigned i = 0;
		while (!deq.empty()) {
			if (i % 2 == 0) {
				std::cout << deq.back() << ' ';
				deq.pop_back();
			} else {
				std::cout << deq.front() << ' ';
				deq.pop_front();
			}

			++i;
		}

		std::cout << std::endl;
	}

	return 0;
}
