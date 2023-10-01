/*
Viết chương trình cho phép nhập vào hai số nguyên dương và tìm tất cả các số
nguyên tố nằm trong khoảng đó.

Input
Chỉ có 2 số nguyên dương a và b (không quá 106)

Output
Ghi ra lần lượt các số nguyên tố trong khoảng. Cách nhau một khoảng trống.

Ví dụ:
Input:
10 50

Output:
11 13 17 19 23 29 31 37 41 43 47
*/

#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

int main(void) {

	using u64 = unsigned long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	u64 start, end, i, j;
	std::cin >> start >> end;

	if (start > end) std::swap(start, end);

	std::vector<bool> isPrime(end + 1, true);
	isPrime[0] = isPrime[1] = false;

	for (i = 2; i <= sqrt(end); ++i) {

		if (!isPrime[i]) continue;

		for (j = i * i; j <= end; j += i) {
			isPrime[j] = false;
		}
	}

	for (i = start; i <= end; ++i) {
		if (!isPrime[i]) continue;
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}
