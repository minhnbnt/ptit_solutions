/*
ho mảng A[] gồm n số nguyên không âm. Ta gọi phần tử A[i] là hợp lệ nếu A[i]≠0 ngược lại là không
hợp lệ. Nhiệm vụ của bạn là hãy sắp đặt lại các phần tử của mảng theo nguyên tắc nếu số A[i+1]
(i=0,..,n-2) là số hợp lệ và A[i] = A[i+1] thì nhân đôi A[i] và thiết lập A[i+1] = 0. Sau khi thay
đổi, hãy di chuyển các số không hợp lệ vào cuối mảng. Các số hợp lệ phải bảo toàn quan hệ trước sau.
Ví dụ với mảng A[] = {2, 2, 0, 4, 0, 8 }thực hiện theo nguyên tắc trên ta được kết quả A[] = { 4, 4,
8, 0, 0, 0}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần
tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng; các số được viết cách nhau một vài khoảng
trống.

T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤105; 1≤ A[i] ≤105;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
6
2 2 0 4 0 8
10
0 2 2 2 0 6 6 0 0 8

Output:
4 4 8 0 0 0
4 2 12 8 0 0 0 0 0 0
*/

#include <iostream>
#include <vector>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele, i;
		std::cin >> ele;

		std::vector<i64> vec(ele);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		for (i = 1; i < ele; ++i) {

			if (vec[i] == 0) {
				continue;
			}

			if (vec[i] == vec[i - 1]) {
				vec[i - 1] *= 2;
				vec[i] = 0;
			}
		}

		size_t zero_count = 0;

		for (const i64 &x : vec) {

			if (x == 0) {
				++zero_count;
				continue;
			}

			std::cout << x << ' ';
		}

		while (zero_count--) {
			std::cout << "0 ";
		}

		std::cout << std::endl;
	}

	return 0;
}
