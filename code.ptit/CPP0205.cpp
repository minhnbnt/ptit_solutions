/*
Cho mảng A[] gồm n số được thiết lập theo nguyên tắc nửa đầu tăng dần nửa sau
giảm dần. Hãy tìm số lớn nhất của mảng. Ví dụ với mảng A[] = {1, 2, 3, 4, 5, 2,
1}, ta có kết quả 5.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào n là số phần tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng;
các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤107; 0≤ A[i] ≤107;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
5
1 2 7 4 3

Output:
7
*/

#include <iostream>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		int arr[ele];
		int *p = new int(-__INT16_MAX__);
		for (int &x : arr) {

			std::cin >> x;

			if (x > *p) {
				p = &x;
			}
		}

		std::cout << *p << std::endl;
	}

	return 0;
}
