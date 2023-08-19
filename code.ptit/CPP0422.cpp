/*
Cho mảng A[] gồm n phần tử. Nhiệm vụ của bạn là hãy sắp đặt lại các phần tử của
mảng sao cho các số 0 để ở cuối cùng, các phần tử khác không được bảo toàn thứ
tự trước sau. Ví dụ với mảng A[] = {1, 2, 0, 0, 0, 3, 6} ta có kết quả
A[] = {1, 2, 3, 6, 0, 0, 0}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào n là số phần tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng;
các số được viết cách nhau một vài khoảng trống. T, n, A[i] thỏa mãn ràng buộc:
1≤ T ≤100; 1≤ n ≤10^7; 0≤ A[i] ≤10^18;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
7
1 2 0 0 0 3 6
6
0 1 0 2 0 3

Output:
1 2 3 6 0 0 0
1 2 3 0 0 0
*/

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T> int comparator(const T &a, const T &b) {
	return b == 0;
}

int main(void) {

	using i64 = long long;
	using u64 = unsigned long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 n;
		std::cin >> n;

		std::vector<i64> vec(n);
		for (i64 &i : vec) {
			std::cin >> i;
		}

		std::stable_sort(vec.begin(), vec.end(), comparator<i64>);
		for (const i64 &x : vec) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
