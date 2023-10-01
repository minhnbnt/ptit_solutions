/*
Trong mã hàng hóa  người ta thường ghi kèm theo mã số quốc gia sản xuất. Nếu sản
xuất tại Việt Nam thì mã tương ứng là 084. Bài toán đặt ra là cho một dãy mã
dạng số nguyên không quá 18 chữ số. Hãy loại bỏ đoạn mã 084 ra khỏi mã ban đầu.

Dữ liệu đảm bảo dãy mã luôn có duy nhất một lần cụm 084.

Input
Dòng đầu ghi số bộ test. Mỗi test là một số nguyên có ít nhất 4 chữ số nhưng
không quá 18 chữ số.

Output
Ghi ra kết quả sau khi loại bỏ 084

Ví dụ

Input:
3
123084567
3300478808445
1084

Output:
123567
3300478845
1
*/

#include <iostream>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string str;
		std::cin >> std::ws >> str;

		size_t pos = str.find("084");

		if (pos != std::string::npos) {
			str.replace(pos, 3, "");
		}

		std::cout << str << std::endl;
	}

	return 0;
}
