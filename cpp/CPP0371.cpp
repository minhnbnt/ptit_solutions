/*
Cho một xâu ký tự S chỉ bao gồm các ký tự chữ cái và không có khoảng trống. Hãy
loại bỏ các nguyên âm trong S.

Kết quả được viết ra dưới dạng chữ cái viết thường của các phụ âm có mặt trong
S, trước mỗi phụ âm ghi một ký tự dấu chấm ‘.’

Các nguyên âm bao gồm: ‘A’, ‘E’, ‘I’, ‘O’, ‘U’, ‘Y’ (cả viết hoa và viết
thường).

Input
Chỉ có xâu S, độ dài không quá 100.

Output
Ghi ra xâu kết quả

Ví dụ
Input:
HocVienCNBCVT

Output:
.h.c.v.n.c.n.b.c.v.t
*/

#include <cctype>
#include <iostream>
#include <unordered_set>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	const std::unordered_set<char> aeiou{ 'a', 'e', 'i', 'o', 'u', 'y' };

	std::string buf;
	std::getline(std::cin, buf);

	for (const char &c : buf) {

		const char x = tolower(c);

		if (aeiou.find(x) != aeiou.end()) {
			continue;
		}

		std::cout << '.' << x;
	}
	std::cout << std::endl;

	return 0;
}
