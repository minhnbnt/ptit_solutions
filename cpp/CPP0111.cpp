/*
Viết chương trình kiểm tra số nguyên dương N có thỏa mãn tính chất: tất cả các
chữ số cạnh nhau chỉ sai khác nhau đúng một đơn vị hay không. Ví dụ: số 123212
là số thỏa mãn, số 34578 không thỏa mãn.

Input
Dòng đầu ghi số số test (không quá 20). Mỗi test là 1 số nguyên dương N có ít
nhất 2 chữ số, nhưng không quá 18 chữ số.

Output
Ghi ra YES hoặc NO

Ví dụ:
Input:
3
123212
5654345676
10233211123

Output:
YES
YES
NO
*/

#include <iostream>

using u64 = unsigned long long;

namespace solution {

bool check(u64 num) {

	unsigned short prev = num % 10;

	while (num >= 10) {

		num /= 10;

		unsigned short curr = num % 10;
		if (abs(curr - prev) != 1) {
			return false;
		}
		prev = curr;
	}

	return true;
}

}; // namespace solution

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 num;
		std::cin >> num;

		std::cout << (solution::check(num) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
