/*
Cho ma trận A[] có N hàng và 3 cột, trong đó các vị trí là các giá trị nhị phân
(0 hoặc 1). Hãy đếm xem có bao nhiêu hàng mà số lượng số 1 nhiều hơn số lượng số
0.

Input
Dòng đầu ghi số nguyên dương N (không quá 1000).
N dòng tiếp theo, mỗi dòng ghi 3 giá trị nhị phân.

Output
Ghi ra số dòng mà số lượng số 1 nhiều hơn số lượng số 0.

Ví dụ:
Input:
3
1 1 0
1 1 1
1 0 0

Output:
2
-----------
Input:
2
1 0 0
0 1 1

Output:
1
*/

#include <iostream>
#include <sstream>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases, result = 0;
	std::cin >> cases;

	while (cases--) {

		std::string buf;
		std::getline(std::cin >> std::ws, buf);
		std::istringstream iss(buf);

		unsigned one = 0, zero = 0;

		while (!iss.eof()) {
			int x;
			iss >> x;
			if (x == 0) ++zero;
			else if (x == 1) ++one;
		}

		if (one > zero) ++result;
	}

	std::cout << result << std::endl;

	return 0;
}
