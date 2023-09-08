/*
Cho mảng A[] gồm n phần tử, mảng B[] gồm m phần tử khác nhau. Các phần tử của
mảng A[] và B[] chưa được sắp xếp. Hãy tìm mảng hợp và giao được sắp giữa A[] và
B[]. Ví dụ với A[] = {7, 1, 5, 2, 3, 6}, B[]={3, 8, 6, 20, 7} ta có mảng hợp
Union = {1, 2, 3, 5, 6, 7, 8, 20}, mảng giao Intersection = {3, 6}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm ba dòng: dòng đầu tiên đưa
vào n, m là số phần tử của mảng A[] và B[]; dòng tiếp theo là n số A [i] của
mảng A [];dòng tiếp theo là m số B[i] của mảng B[]; các số được viết cách nhau
một vài khoảng trống.
T, n, m, A[i], B[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, m, A[i], B[i] ≤10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
6 5
7 1 5 2 3 6
3 8 6 20 7

Output:
1 2 3 5 6 7 8 20
3 6
*/

#include <iostream>
#include <set>

using i64 = long long;

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t elea, eleb;
		std::cin >> elea >> eleb;

		std::set<i64> uni, a, b;
		while (elea--) {
			i64 x;
			std::cin >> x;

			a.insert(x);
			uni.insert(x);
		}

		while (eleb--) {
			i64 x;
			std::cin >> x;

			b.insert(x);
			uni.insert(x);
		}

		for (auto &x : uni) {
			std::cout << x << ' ';
		}
		std::cout.put(0xa);
		for (auto &x : a) {
			if (b.find(x) == b.end()) {
				continue;
			}
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
