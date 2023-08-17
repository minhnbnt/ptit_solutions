/*
Cho mảng A[] gồm n phần tử. Nhiệm vụ của bạn là tìm giá trị nhỏ nhất lớn hơn
A[i] (i=0, 1, 2,.., n-1). Đưa ra ‘_’ nếu A[i] không có phần tử nhỏ hơn nó. Ví dụ
với mảng A[] = {13, 6, 7, 12}, ta có kết quả là { _ , 7 . 12, 13}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào n là số phần tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng;
các số được viết cách nhau một vài khoảng trống.

T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤106; 10-6≤ A[i] ≤106;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
9
6 3 9 8 10 2 1 15 7
4
13 6 7 12

Output:
7 6 10 9 15 3 2 _ 8
_ 7 12 13
*/

#include <iostream>
#include <set>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		std::set<int> set;
		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
			set.insert(x);
		}

		for (int x : vec) {

			std::set<int>::iterator it = std::next(set.find(x));

			if (it != set.end()) {
				std::cout << *it << ' ';
			} else std::cout << "_ ";
		}
		std::cout << std::endl;
	}

	return 0;
}
