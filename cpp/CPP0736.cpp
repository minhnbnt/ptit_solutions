/*
Cho mảng A[] gồm n số nguyên và số X. Hãy tìm độ dài dãy con liên tục nhỏ nhất có tổng lớn hơn X. Ví
dụ với A[] = { 1, 4, 45, 6, 0, 19} và X = 51 ta có câu trả lời là 3 tương ứng với dãy con {4, 45,
6}. Với dãy A[] = {1, 10, 5, 2, 7} và X =9 ta có câu trả lời là 1 tương ứng với dãy con {10}. Với
dãy A[] = {1, 2, 4}và X=8 ta có câu trả lời là -1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng
n và số X; dòng tiếp theo là n số A[i] của mảng A[]; các số được viết cách nhau một vài khoảng
trống.
T, n, X, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n  ≤107; 1≤ A[i]  ≤107.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
6 51
1 4 45 6 0 19
3 8
1 2 4

Output:
3
-1
*/

#include <iostream>
#include <limits>
#include <vector>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		using i64 = long long;

		i64 target, sum;
		size_t ele, i, j;
		std::cin >> ele >> target;

		std::vector<i64> vec(ele);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		sum = i = j = 0;
		size_t result = std::numeric_limits<size_t>::max();

		while (true) {

			if (sum > target && i < ele) {

				result = std::min(result, j - i);

				sum -= vec[i];
				++i;

				continue;
			}

			if (j < ele) {

				sum += vec[j];
				++j;

				continue;
			}

			break;
		}

		if (result == std::numeric_limits<size_t>::max()) {
			std::cout << -1 << std::endl;
			continue;
		}

		std::cout << result << std::endl;
	}

	return 0;
}
