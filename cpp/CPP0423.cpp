/*
Cho mảng A[] gồm n số nguyên dương và số k. Nhiệm vụ của bạn là hãy sắp đặt lại các phần tử của mảng
sao cho các số nhỏ hơn hoặc bằng k đứng cạnh nhau. Ví dụ với mảng A[] = {2, 1, 5, 6, 3}, k = 3 ta
chỉ cần thực hiện 1 phép đổi chỗ để có mảng A[] = {2, 1, 3, 6, 5}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần
tử của mảng A[] và số k; dòng kế tiếp đưa vào n số A[i] của mảng; các số được viết cách nhau một vài
khoảng trống.
T, n, k, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤107; 1≤ A[i], k ≤107;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5 3
2 1 5 6 3
7 5
2 7 9 5 8 7 4

Output:
1
2
*/

#include <iostream>
#include <vector>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, i;
		int target;
		std::cin >> ele >> target;

		size_t window_size = 0;
		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
			if (x <= target) {
				++window_size;
			}
		}

		size_t result, counter = 0;
		for (i = 0; i < window_size; ++i) {
			if (vec[i] <= target) ++counter;
		}
		result = window_size - counter;
		for (i = window_size; i < ele; ++i) {

			if (vec[i] <= target) {
				++counter;
			}

			if (vec[i - window_size] <= target) {
				--counter;
			}

			result = std::min(result, window_size - counter);
		}

		std::cout << result << std::endl;
	}

	return 0;
}
