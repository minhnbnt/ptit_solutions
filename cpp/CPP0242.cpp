/*
Cho mảng các số nhị phân A1[] và A2[] gồm n 0, 1. Hãy tìm khoảng chung dài nhất thỏa mãn: j ≥i và
span(i, j) = A1[i] + A1[i+1] + …+A1[j] = A2[i] + A2[i+1] + …+A2[j]. Ví dụ với A1[] = {0, 1, 0, 0, 0,
0}, A2[] = {1, 0, 1, 0, 0, 1} ta có kết quả là 4 tương ứng với A1[1]+ A1[2]+ A1[3]+ A1[4] = A2[1]+
A2[2]+ A2[3]+ A2[4] = 1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm ba dòng: dòng đầu tiên là số phần tử của mảng
n; dòng tiếp theo là n số A1[i] của mảng A1[];dòng tiếp theo là n số A2[i] của mảng A2[];các số được
viết cách nhau một vài khoảng trống.

T, n thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
6
0 1 0 0 0 0
1 0 1 0 0 1

Output:
4
*/

#include <iostream>
#include <limits>
#include <vector>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, i, j;
		std::cin >> ele;

		std::vector<int> vec1(ele), vec2(ele);
		for (int &x : vec1) std::cin >> x;
		for (int &x : vec2) std::cin >> x;

		size_t result = 0;
		for (size_t i = 0; i < ele; ++i) {

			size_t length = 0;
			long long sum1 = 0, sum2 = 0;

			for (size_t j = i; j < ele; ++j) {

				sum1 += vec1[j], sum2 += vec2[j];

				++length;

				if (sum1 == sum2 && result < length) {
					result = length;
				}
			}
		}

		std::cout << result << std::endl;
	}

	return 0;
}
