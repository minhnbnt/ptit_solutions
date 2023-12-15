/*
Cho mảng A[] gồm n số nguyên không âm và số k. Hãy tìm số lớn nhất của mỗi dãy con liên tục gồm k
phần tử của mảng. Ví dụ với mảng A[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3, ta có kết quả 3 3 4 5 5
5 6.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần
tử của mảng A[] và số k; dòng kế tiếp đưa vào n số A[i] của mảng; các số được viết cách nhau một vài
khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ k < n ≤10^7; 0≤ A[i] ≤10^7;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90
*/

#include <deque>
#include <iostream>
#include <vector>

class Solution {
public:
	static std::vector<int> maxSlidingWindow(const std::vector<int> &vec, size_t length) {

		std::vector<int> result;
		std::deque<size_t> deq;

		for (size_t i = 0; i < vec.size(); ++i) {

			while (!deq.empty() && vec[deq.back()] <= vec[i]) {
				deq.pop_back();
			}

			deq.push_back(i);

			if (deq.front() == i - length) {
				deq.pop_front();
			}

			if (i >= length - 1) {
				result.push_back(vec[deq.front()]);
			}
		}

		return result;
	}
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, length;
		std::cin >> ele >> length;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		for (int x : Solution::maxSlidingWindow(vec, length)) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
