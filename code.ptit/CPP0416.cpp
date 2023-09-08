/*
Cho mảng A[] gồm n phần tử và số k. Đếm tất cả các cặp phần tử của mảng có tổng
bằng k.
Ví dụ A[] = {1, 5, 3, 4, 2 }, k = 7 ta có kết quả là 2 cặp (3, 4), (5, 2).

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào n là số phần tử của mảng A[] và k; dòng tiếp theo là n số A[i] của mảng
A[]các số được viết cách nhau một vài khoảng trống. T, n, k, A[i] thỏa mãn ràng
buộc: 1≤ T ≤100; 1≤ n ≤100; 0≤ k ≤100, 0≤ A[i] ≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5 0
1 5 4 1 2
3 2
1 1 1

Output:
0
3
*/

#include <iostream>
#include <unordered_set>
#include <vector>

unsigned count_two_sum(const std::vector<int> &nums, int target) {

	unsigned count = 0;

	std::unordered_multiset<int> mtset;
	for (const int &x : nums) {

		count += mtset.count(target - x);

		mtset.insert(x);
	}

	return count;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		int target;
		unsigned ele;

		std::cin >> ele >> target;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		std::cout << count_two_sum(vec, target) << std::endl;
	}

	return 0;
}
