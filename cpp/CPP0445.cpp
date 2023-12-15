/*
Cho mảng A[] gồm n phần tử, hãy đưa ra số nhỏ nhất và số nhỏ thứ hai của mảng. Nếu không có số nhỏ
thứ hai, hãy đưa ra -1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào n là số phần
tử của mảng A[]; dòng tiếp theo đưa vào n số A[i]; các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N, A[i] ≤10^7.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
10
5 6 7 8 9 10 1 2 3 4
5
1 1 1 1 1

Output:
1 2
-1
*/

#include <iostream>
#include <limits>
#include <vector>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		i64 first = std::numeric_limits<i64>::max(), second;

		std::vector<i64> vec(ele);
		for (i64 &x : vec) {
			std::cin >> x;
			if (x < first) {
				second = first;
				first = x;
			} else if (x != first && x < second) {
				second = x;
			}
		}

		if (second == std::numeric_limits<i64>::max()) {
			std::cout << -1 << std::endl;
			continue;
		}

		std::cout << first << ' ' << second << std::endl;
	}

	return 0;
}
