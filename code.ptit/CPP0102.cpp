/*
Cho một chữ cái bất kỳ. Hãy kiểm tra xem đó là chữ hoa hay chữ thường. Nếu là
chữ thường thì in ra chữ hoa, nếu là chữ hoa thì in ra chữ thường tương ứng.

Input
Dòng đầu ghi số bộ test. Mỗi bộ test có duy nhất một chữ cái.

Output
Với mỗi bộ test, ghi ra kết quả trên một dòng.

Ví dụ:

Input:
2
B
q

Output:
b
Q
*/

#include <cctype>
#include <iostream>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		char c;
		std::cin >> std::ws >> c;

		if (isupper(c)) std::cout << (char)tolower(c) << std::endl;
		else std::cout << (char)toupper(c) << std::endl;
	}

	return 0;
}
