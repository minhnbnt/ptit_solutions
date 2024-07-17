/*
Cho số nguyên dương N (2 < N <10). Một số nguyên dương K có N chữ số được gọi là
số xa cách nếu thỏa mãn:

K không chứa chữ số 0
Tất cả các chữ số từ 1 đến N đều xuất hiện trong K đúng 1 lần
Không có hai chữ số liên tiếp nào trong K có hiệu bằng 1.

Hãy liệt kê tất cả các số thỏa mãn theo thứ tự tăng dần.

Input
Dòng đầu ghi số bộ test (không quá 10)
Mỗi bộ test là 1 số nguyên dương N (2 < N < 10)

Output
Liệt kê tất cả các số thỏa mãn, mỗi số trên một dòng.
Sau mỗi test in ra một khoảng trống.

Ví dụ
Input
2
3
4

Output
2413
3142
*/

#include <algorithm>
#include <iostream>
#include <vector>

bool is_valid(const std::vector<int> &vec) {

	for (size_t i = 1; i < vec.size(); i++) {
		if (std::abs(vec[i] - vec[i - 1]) < 2) {
			return false;
		}
	}

	return true;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	for (; cases > 0; cases--) {

		int i, size;
		std::cin >> size;

		std::vector<int> vec(size);
		for (i = 0; i < size; i++) {
			vec[i] = i + 1;
		}

		do {

			if (!is_valid(vec)) {
				continue;
			}

			for (int x : vec) {
				std::cout << x;
			}

			std::cout.put('\n');

		} while (std::next_permutation(vec.begin(), vec.end()));

		std::cout.flush();
	}

	return 0;
}
