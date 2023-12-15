/*
Một mảng được sắp được chia thành hai đoạn tăng dần được gọi là mảng sắp xếp vòng. Ví dụ mảng A[] =
{ 5, 6, 7, 8, 9, 10, 1, 2, 3, 4} là mảng sắp xếp vòng. Cho mảng A[] gồm n phần tử, hãy tìm vị trí
của phần tử x trong mảng A[].

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào n và x; dòng
tiếp theo đưa vào n số A[i]; các số được viết cách nhau một vài khoảng trống.
T, n, A[i], x  thỏa mãn ràng buộc: 1≤T≤100; 1≤N, x, A[i] ≤10^7.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
10 3
5 6 7 8 9 10 1 2 3 4
10 3
1 2 3 4 5 6 7 8 9 10

Output:
9
3
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

		size_t ele;
		int target;
		std::cin >> ele >> target;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		auto it = std::find(vec.cbegin(), vec.cend(), target);
		std::cout << std::distance(vec.cbegin(), it) + 1 << std::endl;
	}

	return 0;
}
