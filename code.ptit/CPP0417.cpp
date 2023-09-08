/*
Cho mảng A[] gồm n phần tử. Hãy tìm dãy con liên tục của mảng A[R], .., A[L] sao
cho khi sắp xếp lại dãy con ta nhận được một mảng được sắp xếp. Ví dụ với A[] =
{10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60} ta chỉ cần sắp xếp lại dãy con từ
A[4],.., A[9]: {30, 25, 40, 32, 31, 35} để có mảng được sắp.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào n là số phần tử của mảng A[]; dòng tiếp theo là n số A [i] của mảng A
[]các số được viết cách nhau một vài khoảng trống.

T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤106; 0≤ A[i] ≤10^7.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
11
10 12 20 30 25 40 32 31 35 50 60
9
0 1 15 25 6 7 30 40 50

Output:
4 9
3 6
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

		size_t ele, i;
		std::cin >> ele;

		std::vector<i64> vec(ele);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		std::vector<i64> cloned(vec);
		std::sort(cloned.begin(), cloned.end());

		size_t begin = 0, end = vec.size() - 1;
		while (vec[end] == cloned[end]) --end;
		while (vec[begin] == cloned[begin]) ++begin;

		std::cout << begin + 1 << ' ' << end + 1 << std::endl;
	}

	return 0;
}
