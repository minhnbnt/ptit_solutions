/*
Khi viết tên người Việt Nam sang dạng chuẩn Tiếng Anh không dấu, người ta có thể
lựa chọn 1 trong 2 cách viết:

Cách 1: tên có 1 từ.
Ví dụ: Nguyen Manh Son được viết thành Son Nguyen Manh

Cách 2: họ có 1 từ.
Ví dụ: Nguyen Manh Son được viết thành Manh Son Nguyen
Hãy viết chương trình chuẩn hóa xâu ký tự họ tên theo một trong hai dạng trên.

Input
Dòng đầu ghi số bộ test.
Mỗi bộ test gồm 2 dòng. Dòng đầu ghi số 1 hoặc số 2 cho biết cách chuẩn hóa được
chọn. Dòng thứ 2 ghi xâu họ tên có độ dài không quá 60 ký tự.

Output
Ghi ra danh sách các xâu họ tên đã chuẩn hóa.
Chú ý: có thể phải loại bỏ khoảng trống, chuyển đổi chữ hoa chữ thường cho đúng
với cách viết họ tên chuẩn trước khi áp dụng một trong hai cách viết nói trên.

Ví dụ:
Input:
2
1
NguyeN    vAn    Nam
2
hoAng  le Nhat THONG chi

Output:
Nam Nguyen Van
Le Nhat Thong Chi Hoang
*/

#include <deque>
#include <iostream>
#include <sstream>

std::string &proper(std::string &word) {

	for (char &c : word) {
		c = tolower(c);
	}

	word[0] = toupper(word[0]);

	return word;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		int method;
		std::cin >> method;

		if (method != 1 && method != 2) {
			std::cerr << "Invalid method." << std::endl;
			continue;
		}

		std::string buf, word;
		std::getline(std::cin >> std::ws, buf);
		std::istringstream iss(buf);

		std::deque<std::string> deq;
		while (iss >> word) {
			deq.push_back(proper(word));
		}

		if (method == 1) {
			word = deq.back(), deq.pop_back();
			deq.push_front(word);
		} else {
			word = deq.front(), deq.pop_front();
			deq.push_back(word);
		}

		for (const std::string &name : deq) {
			std::cout << name << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
