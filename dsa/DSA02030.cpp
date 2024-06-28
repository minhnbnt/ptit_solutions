/*
Cho chữ cái c in hoa (‘A’ < c < ’K’) và số nguyên K (0 < K < (c – ‘A’)).

Hãy tìm cách  liệt kê tất cả các xâu ký tự khác nhau được tạo ra bởi các chữ cái
tính từ ‘A’ đến ký tự c.
Các ký tự được phép lặp lại nhưng không tính các xâu là hoán vị của xâu nào đó
đã liệt kê trước đó.

Xem ví dụ để hiểu thêm yêu cầu đề bài.

Input
Chỉ có một dòng ghi chữ cái c và số nguyên K thỏa mãn ràng buộc đề bài.

Output
Ghi ra lần lượt các xâu ký tự kết quả theo thứ tự từ điển, mỗi xâu trên một
dòng.

Ví dụ
Input:
D 2

Output:
AA
AB
AC
AD
BB
BC
BD
CC
CD
DD
*/

#include <iostream>

void gen_string(char begin, char end, size_t size) {

	static std::string current;

	if (current.length() == size) {
		std::cout << current << '\n';
		return;
	}

	for (char c = begin; c <= end; c++) {

		current.push_back(c);
		gen_string(c, end, size);

		current.pop_back();
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	char end;
	size_t size;
	std::cin >> end >> size;

	gen_string('A', end, size);
	std::cout.flush();

	return 0;
}
