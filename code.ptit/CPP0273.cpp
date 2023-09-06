/*
Cho dãy số A[] gồm có N phần tử nguyên dương. Phần tử thứ i được gọi là điểm cân
bằng của dãy số nếu như tổng các số bên trái bằng tổng các số bên phải của nó.

Nhiệm vụ của bạn là điểm cân bằng đầu tiên của dãy A[] cho trước. Nếu không có
đáp án, in ra -1.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm số nguyên N (1≤ N ≤ 100 000), số lượng phần tử trong dãy số ban
đầu. Dòng tiếp theo gồm N số nguyên A[i] (-1000 ≤ A[i] ≤ 1000).

Output:
Với mỗi test, in ra trên một dòng vị trí của điểm cân bằng tìm được.

Ví dụ:
Input:
2
7
-7 1 5 2 -4 3 0
5
1 2 3 4 5

Output:
4
-1
*/

#include <iostream>
#include <vector>

size_t balance_pos(const std::vector<int> &vec) {

	using i64 = long long;

	i64 sum_of_vec = 0;
	for (const int &x : vec) {
		sum_of_vec += x;
	}

	i64 sum_of_left = 0;
	i64 sum_of_remaining = sum_of_vec;

	for (size_t i = 0; i < vec.size(); ++i) {

		if (sum_of_left == sum_of_remaining - vec.at(i)) {
			return i;
		}

		sum_of_left += vec.at(i);
		sum_of_remaining -= vec.at(i);
	}

	return -1;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele;
		std::cin >> ele;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		size_t pos = balance_pos(vec);
		if (pos == size_t(-1)) {
			std::cout << -1 << std::endl;
			continue;
		}
		std::cout << pos + 1 << std::endl;
	}

	return 0;
}
