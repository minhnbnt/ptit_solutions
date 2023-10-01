/*
Một số được gọi là “cân bằng chẵn lẻ” nếu số chữ số chẵn và số chữ số lẻ là bằng
nhau. Tất nhiên khi đó số chữ số của nó phải là chẵn. Cho số N là một số chẵn
(1<N<7). Hãy liệt kê các số cân bằng chẵn lẻ có N chữ số. Mỗi dòng ghi ra 10 số
thỏa mãn.

Input:
Chỉ có duy nhất số N (chẵn)

Output:
Ghi ra các số cân bằng chẵn lẻ có N chữ số theo thứ tự từ nhỏ đến lớn. Mỗi dòng
ghi 10 số. Ví dụ

Input:
2

Output:
10 12 14 16 18 21 23 25 27 29
30 32 34 36 38 41 43 45 47 49
50 52 54 56 58 61 63 65 67 69
70 72 74 76 78 81 83 85 87 89
90 92 94 96 98
*/

#include <complex>
#include <iostream>

bool balance_of_oddeven(unsigned long num) {

	unsigned odd = 0, even = 0;

	while (num > 0) {
		if (num % 2) ++odd;
		else ++even;
		num /= 10;
	}

	return odd == even;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned int n;
	std::cin >> n;

	const unsigned long start = pow(10, n - 1), end = start * 10;

	int count = 0;

	for (unsigned long i = start; i < end; i++) {

		if (balance_of_oddeven(i)) {
			std::cout << i << ' ';
			++count;
		}

		if (count == 10) {
			count = 0;
			std::cout << std::endl;
		}
	}

	if (count != 0) std::cout << std::endl;

	return 0;
}
