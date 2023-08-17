/*
Cho tệp dữ liệu đầu vào có tên: PTIT.in đặt cùng thư mục với tệp mã nguồn.

Nhiệm vụ của bạn là sao chép nội trong tệp PTIT.in tới tệp PTIT.out

Ví dụ:
PTIT.in:
Ngon ngu lap trinh C++

PTIT.out:
Ngon ngu lap trinh C++
*/

#include <fstream>

int main(void) {

	std::ifstream ifs("PTIT.in");
	std::ofstream ofs("PTIT.out");

	std::string buf;

	while (std::getline(ifs, buf)) {
		ofs << buf << std::endl;
	}

	return 0;
}
