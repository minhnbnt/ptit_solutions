/*
Một số nguyên dương được gọi là số thuận nghịch nếu viết theo chiều ngược lại
vẫn có cùng giá trị với số ban đầu. Ví dụ số 121 là số thuận nghịch, số 123
không phải số thuận nghịch.

Viết chương trình kiểm tra số thuận nghịch

Input
Dòng đầu ghi số bộ test, mỗi bộ test ghi một số nguyên dương không quá 18 chữ số

Output
Với mỗi bộ test, nếu đúng ghi ra YES, nếu sai ghi ra NO.

Ví dụ:
Input:
2
123456789012345
12345678987654321

Output:
NO
YES
*/

#include <iostream>
#include <string>

bool revertable(std::string num) {

	for (unsigned i = 0; i < num.length() / 2; i++)
		if (num[i] != num[num.length() - i - 1]) {
			return false;
		}

	return true;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string num;
		std::cin >> std::ws >> num;

		std::cout << (revertable(num) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
