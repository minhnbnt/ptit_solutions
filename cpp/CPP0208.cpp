/*
Cho mảng A[] gồm n số và số k. Hãy tìm phần tử nhỏ nhất thứ k của mảng.
Ví dụ với mảng A[] = {7, 10, 4, 3, 20, 15 }, k=3 ta nhận được số nhỏ nhất thứ k là 7.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần
tử của mảng A[] và số k; dòng kế tiếp đưa vào n số A[i] của mảng; các số được viết cách nhau một vài
khoảng trống.
T, n, k, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ k ≤ n ≤ 10^5; 1 ≤ A[i] ≤ 10^5;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
6  3
7  10  4  3  20  15
6  4
9  7  12  8  6  5

Output:
7
8
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, target;
		std::cin >> ele >> target;

		std::vector<i64> vec(ele);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		std::sort(vec.begin(), vec.end());

		std::cout << vec.at(target - 1) << std::endl;
	}

	return 0;
}
