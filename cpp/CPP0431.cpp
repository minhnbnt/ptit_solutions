/*
Cho mảng A[] gồm n số nguyên dương và số k. Nhiệm vụ của bạn là đếm số các cặp phần tử có hiệu nhỏ
hơn k. Ví dụ A[] = {1, 10, 4, 2 }, k=3 ta nhận được kết quả là 2 tương ứng với hiệu các cặp (1, 2),
(4, 2).

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n, tương ứng
với số phần tử của mảng A[] và số k; dòng tiếp theo là n số A[i] ; các số được viết cách nhau một
vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤105; 1≤ k ≤103; 1≤ A[i] ≤105.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
4 3
1 10 4 2
3 5
2 3 4

Output:
2
3
*/

#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

size_t count_gap(std::vector<i64> vec, const i64 &target) {

	size_t result = 0;

	std::sort(vec.begin(), vec.end());

	for (size_t i = 0; i < vec.size(); ++i) {

		auto it = std::upper_bound(vec.begin(), vec.begin() + i, vec[i] - target);

		result += vec.begin() - it + i;
	}

	return result;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		i64 target;
		size_t ele, i, j;
		std::cin >> ele >> target;

		std::vector<i64> vec(ele);
		for (auto &i : vec) {
			std::cin >> i;
		}

		std::cout << count_gap(vec, target) << std::endl;
	}

	return 0;
}
