/*
Cho mảng A[] gồm N phần tử và số X. Nhiệm vụ của bạn là tìm cặp phần tử A[i] -
A[j] = X.  Nếu tồn tại A[i] - A[j] = X đưa ra 1, ngược lại đưa ra -1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất
là cặp số N, X; dòng tiếp theo là N số A[i] là các phần tử của mảng A[]. T, N,
X, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N ≤10^5, 1≤ X, A[i] ≤10^5.

Output:

Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
6 78
5 20 3 2 5 80
5 45
90 70 20 80 50

Output:
1
-1
*/

#include <iostream>
#include <unordered_set>
#include <vector>

int two_gap(std::vector<int> nums, int target) {

	std::unordered_set<int> set;
	for (const int &num : nums) {

		if (set.find(num + target) != set.end()) {
			return 1;
		}
		if (set.find(num - target) != set.end()) {
			return 1;
		}

		set.insert(num);
	}

	return -1;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele, target;
		std::cin >> ele >> target;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		std::cout << two_gap(vec, target) << std::endl;
	}

	return 0;
}
