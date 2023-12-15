/*
Cho mảng A[] gồm n phần tử và số X. Hãy đưa sắp xếp các phần tử của mảng theo trị tuyệt đối của |X -
A[i] |. Ví dụ với A[] = {10, 5, 3, 9, 2} và X = 7 ta đưa ra mảng được sắp xếp theo nguyên tắc kể
trên: A[] = {5, 9, 10, 3, 2} vì |7-10|=3, |7-5|=2, |7-3|=4, |7-9|=2, |7-2|=5. Trong trường hợp có
nhiều phần tử có giá trị tuyệt đối như nhau, ưu tiên theo thứ tự số xuất hiện trước trong mảng ban
đầu.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng
n và X; dòng tiếp theo là n số A [i] của mảng A [];các số được viết cách nhau một vài khoảng trống.
T, n, X thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, X, A[i] ≤10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5 7
10 5 3 9 2
5 6
1 2 3 4 5

Output:
5 9 10 3 2
5 4 3 2 1
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele;
		i64 target;
		std::cin >> ele >> target;

		std::vector<i64> vec(ele);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		std::stable_sort(vec.begin(), vec.end(), [target](i64 a, i64 b) {
			const i64 a_gap = std::abs(a - target);
			const i64 b_gap = std::abs(b - target);

			return a_gap < b_gap;
		});

		for (const i64 x : vec) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
