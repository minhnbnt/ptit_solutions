/*
Cho mảng A[] gồm n số nguyên dương. Gọi L, R là max và min các phần tử của A[]. Nhiệm vụ của bạn là
tìm số phần tử cần thiết cần thêm vào mảng để mảng có đầy đủ các số trong khoảng [L, R]. Ví dụ A[] =
{ 5, 7, 9, 3, 6, 2 } ta nhận được kết quả là 2 tương ứng với các số còn thiếu là 4, 8.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n, tương ứng
với số phần tử của mảng A[]; dòng tiếp theo là n số A[i] ; các số được viết cách nhau một vài khoảng
trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, A[i] ≤103.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5
4 5 3 8 6
3
2 1 3

Output:
1
0
*/

#include <iostream>
#include <set>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		std::set<int> set;
		while (ele--) {

			int x;
			std::cin >> x;

			set.insert(x);
		}

		const int &L = *set.cbegin(), &R = *set.crbegin();

		std::cout << R - L - set.size() + 1 << std::endl;
	}

	return 0;
}
