/*
Cho mảng A[] gồm n phần tử. Hãy tìm số phép đổi chỗ ít nhất giữa các phần tử của mảng để mảng A[]
được sắp xếp. Ví dụ với A[] = {4, 3, 2, 1} ta cần thực hiện ít nhất 2 phép đổi chỗ: Swap(A[0],
A[3]),  Swap(A[1], A[2]).

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng
n và X; dòng tiếp theo là n số A [i] của mảng A [];các số được viết cách nhau một vài khoảng trống.
T, n thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
4
4 3 2 1
5
1 5 4 3 2

Output:
2
2
*/

#include <algorithm>
#include <iostream>
#include <vector>

using u64 = unsigned long long;

u64 minimum_swap(const std::vector<int> &vec) {

	std::vector<std::pair<int, size_t>> vec_pair(vec.size());
	for (size_t i = 0; i < vec.size(); ++i) {
		vec_pair[i] = std::make_pair(vec[i], i);
	}

	std::sort(vec_pair.begin(), vec_pair.end());

	u64 result = 0;
	std::vector<bool> is_visited(vec.size(), false);
	for (size_t i = 0; i < vec.size(); ++i) {

		if (is_visited[i] || vec_pair[i].second == i) {
			continue;
		}

		size_t cycle_size = 0, j = i;
		while (!is_visited[j]) {

			is_visited[j] = true;
			j = vec_pair[j].second;

			++cycle_size;
		}

		if (cycle_size > 0) {
			result += cycle_size - 1;
		}
	}

	return result;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		size_t ele;
		std::cin >> ele;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		std::cout << minimum_swap(vec) << std::endl;
	}

	return 0;
}
