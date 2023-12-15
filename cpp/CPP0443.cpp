/*
Cho mảng A[] gồm n-1 phần tử bao gồm các khác nhau từ 1, 2, .., n. Hãy tìm số nguyên dương nhỏ nhất
không có mặt trong mảng A[].

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào n; dòng tiếp
theo đưa vào n-1 số A[i]; các số được viết cách nhau một vài khoảng trống. T, n, A thỏa mãn ràng
buộc: 1≤T≤100; 1≤N, A[i] ≤10^7.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5
1 2 3 5
10
1 2 3 4 5 6 7 8 10

Output:
4
9
*/

#include <iostream>
#include <unordered_set>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, i;
		std::cin >> ele;

		std::unordered_set<i64> set;
		for (i = 1; i < ele; ++i) {
			i64 x;
			std::cin >> x;

			set.insert(x);
		}

		i64 result = 1;
		while (set.find(result) != set.end()) {
			++result;
		}

		std::cout << result << std::endl;
	}

	return 0;
}
