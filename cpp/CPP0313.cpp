/*
Viết chương trình cho phép nhập vào một chuỗi và từ cần loại bỏ khỏi chuỗi. Thực hiện loại bỏ từ và
in ra kết quả

Trong đó:

INPUT
- Hàng thứ nhất là chuỗi ban đầu
- Hàng tiếp theo là từ cần loại bỏ

OUTPUT
- Chuỗi kết quả

Input
Toi Yeu PTIT
Toi

Output
Yeu PTIT
*/

#include <iostream>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::string input;
	std::getline(std::cin >> std::ws, input);

	std::string del;
	std::cin >> std::ws >> del;

	size_t pos = input.find(del);
	if (pos != std::string::npos) {
		input.erase(pos, del.size() + 1);
	}

	std::cout << input << std::endl;

	return 0;
}
