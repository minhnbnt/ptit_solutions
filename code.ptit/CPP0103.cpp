/*
Viết chương trình tính tổng  S = 1 + 1/2 + 1/3 + … + 1/N

Input:
Dữ liệu vào chỉ có 1 dòng ghi số N không quá 6 chữ số.

Output:
Kết quả ghi chính xác với 4 số phần thập phân.

Ví dụ:
Input:
2

Output:
1.5000
*/

#include <iomanip>
#include <iostream>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned long n;
	std::cin >> n;

	float sum = 0;

	while (n > 0) {
		sum += 1.0 / n;
		--n;
	}

	std::cout.precision(4);
	std::cout << std::fixed << sum << std::endl;

	return 0;
}
