/*
Cho mảng A[] gồm n phần tử, mảng B[] gồm m phần tử khác nhau. Các phần tử của
mảng A[] và B[] đã được sắp xếp. Hãy tìm mảng hợp và giao được sắp giữa A[] và
B[]. Ví dụ với A[] = {1, 3, 4, 5, 7}, B[]={2, 3, 5, 6} ta có mảng hợp Union =
{1, 2, 3, 4, 5, 6, 7}, mảng giao Intersection = {3, 5}. In ra đáp án theo giá
trị phần tử từ nhỏ đến lớn.

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
5 3
1 2 3 4 5
1 2 3

Output:
1 2 3 4 5
1 2 3
*/

#include <iostream>
#include <set>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t eleA, eleB, i;
		std::cin >> eleA >> eleB;

		std::set<i64> setA, intersct;

		for (i = 0; i < eleA; ++i) {

			i64 x;
			std::cin >> x;

			setA.insert(x);
		}

		std::set<i64> uni(setA);

		for (i = 0; i < eleB; ++i) {

			i64 x;
			std::cin >> x;

			uni.insert(x);

			if (setA.find(x) != setA.end()) {
				intersct.insert(x);
			}
		}

		for (const i64 &x : uni) {
			std::cout << x << ' ';
		}
		std::cout.put(10);

		for (const i64 &x : intersct) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
