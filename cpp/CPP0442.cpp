/*
Cho mảng A[] gồm n phần tử đã được sắp xếp. Hãy đưa ra 1 nếu X có mặt trong mảng A[], ngược lại đưa
ra -1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào n, X là số
các phần tử của mảng A[] và số X cần tìm; dòng tiếp theo đưa vào n số A[i] (1≤i≤n) các số được viết
cách nhau một vài khoảng trống.
T, n, A, X thỏa mãn ràng buộc: 1≤T≤100; 1≤N, X, A[i] ≤10^6.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5 16
9 7 2 16 4
7 98
1 22 57 47 34 18 66

Output:
1
-1
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	using u64 = unsigned long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 ele, target;
		std::cin >> ele >> target;

		std::vector<u64> vec(ele);
		for (u64 &x : vec) {
			std::cin >> x;
		}

		if (!std::is_sorted(vec.begin(), vec.end())) {
			std::sort(vec.begin(), vec.end());
		}

		bool result = std::binary_search(vec.begin(), vec.end(), target);
		std::cout << (result ? 1 : -1) << std::endl;
	}

	return 0;
}
