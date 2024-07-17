/*
Cho hai mảng đã được sắp xếp A[], B[] gồm M, N phần tử theo thứ tự và số K.
Nhiệm vụ của bạn là tìm phần tử ở vị trí số K sau khi trộn hai mảng để nhận được
một mảng được sắp xếp.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test.

Mỗi bộ test gồm 3 dòng:
dòng thứ nhất đưa vào số M, N, K;
dòng tiếp theo đưa vào M số của mảng A[];
dòng tiếp theo đưa vào N số của mảng B[];
các số được viết cách nhau một vài khoảng trống.

T, M, N, A[i], B[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N, A[i], B[i]≤10^6; 1≤ K ≤
N+M.

Output:
Đưa ra giá trị phần tử thứ K của mỗi test theo từng dòng.

Ví dụ:

Input:
1
5 4 5
2 3 6 7 9
1 4 8 10

Output:
6
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		int target_index;
		size_t size1, size2;
		std::cin >> size1 >> size2 >> target_index;

		std::vector<int> vec1(size1), vec2(size2);
		for (int &x : vec1) std::cin >> x;
		for (int &x : vec2) std::cin >> x;

		std::vector<int> merged;
		std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(),
		           std::back_inserter(merged));

		std::cout << merged.at(target_index - 1) << std::endl;
	}

	return 0;
}
