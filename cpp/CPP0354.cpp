/*
Cho một xâu ký tự độ dài không quá 100 chỉ bao gồm các chữ cái in hoa. Người ta
thực hiện mã hóa bằng cách đếm các ký tự cạnh nhau giống nhau và viết số lượng
phía sau các chữ cái đó.

Ví dụ xâu AAECCCCGGGD thì được mã hóa thành A2E1C4G3D1

Với giả thiết không có ký tự nào xuất hiện nhiều hơn 9 lần liên tiếp. Hãy viết
chương trình mã hóa xâu ký tự theo cách như trên.

Input
Dòng đầu ghi số bộ test. Mỗi bộ test ghi xâu chữ cái in hoa không quá 100 ký tự.
Không có ký tự nào xuất hiện nhiều hơn 9 lần liên tiếp.

Output
Với mỗi test ghi ra kết quả mã hóa.

Ví dụ
Input:
2
AAAAAAAA
AAECCCCGGGD

Output:
A8
A2E1C4G3D1
*/

#include <iostream>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string buf;
		std::getline(std::cin >> std::ws, buf);

		const char *p = buf.c_str();
		unsigned count = 1;
		char c = *p;
		++p;
		while (true) {
			if (*p != c) {
				std::cout << c << count;

				if (*p == '\0') break;
				c = *p, count = 1,

				++p;
				continue;
			}

			++count, ++p;
		}

		std::cout << std::endl;
	}

	return 0;
}
