/*
Cho mảng A[] gồm n phần tử gồm các số âm và dương. Hãy tìm giá trị lớn nhất tích các phần tử của tất
cả các dãy con liên tục trong mảng A[]. Ví dụ với mảng A[] = {6, -3, - 10, 0, 2 } ta có kết quả là
180 tương ứng với tích các phần tử của dài dãy con {6, -3, -10}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số lượng phần
tử của mảng N; phần thứ hai đưa vào n số A[i]; các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤100; -200≤ A[i] ≤200.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
3
5
6 -3 -10 0 2
6
2 3 4 5 -1 0
10
8 -2 -2 0 8 0 -6 -8 -6 -1

Output:
180
120
288
*/

#include <iostream>
#include <limits>
#include <vector>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, i, j;
		std::cin >> ele;

		std::vector<i64> vec(ele);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		i64 max_so_far = std::numeric_limits<i64>::min();

		for (i = 0; i < ele; ++i) {

			i64 product = 1;

			for (j = i; j < ele; ++j) {

				product *= vec[j];

				max_so_far = std::max(max_so_far, product);
			}
		}

		std::cout << max_so_far << std::endl;
	}

	return 0;
}
