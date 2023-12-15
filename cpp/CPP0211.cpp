/*
Cho mảng A[] gồm n số nguyên dương. Hãy tìm hiệu lớn nhất của i-j thỏa mãn ràng buộc A[i]<=A[j]. Ví
dụ với mảng A[] = {34, 8, 10, 3, 2, 80, 30, 33, 1} ta nhận được kết quả là 6  vì A[1]<A[7] và 7-1 =
6 là lớn nhất.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần
tử của mảng A[]; dòng kế tiếp đưa vào n số A[i] của mảng; các số được viết cách nhau một vài khoảng
trống.

T, n, A[i] thỏa mãn ràng buộc: 1 ≤ T ≤ 100; 1≤ n ≤ 10^7; 1≤ A[i] ≤10^8;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
1
9
34 8 10 3 2 80 30 33 1

Output:
6
*/

#include <iostream>
#include <memory>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		using i64 = long long;

		size_t ele, i, j;
		std::cin >> ele;

		auto ptr = std::make_unique<i64[]>(ele);
		for (i = 0; i < ele; ++i) {
			std::cin >> ptr[i];
		}

		size_t max_distance = 0;
		for (i = 0; i < ele; ++i) {
			for (j = ele - 1; j > i; --j)
				if (ptr[i] <= ptr[j]) {
					break;
				}

			const size_t distance = j - i;
			max_distance = std::max(max_distance, distance);
		}

		std::cout << max_distance << std::endl;
	}

	return 0;
}
