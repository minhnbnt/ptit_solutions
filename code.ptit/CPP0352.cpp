/*
Địa chỉ email của các cán bộ, giảng viên PTIT được tạo ra bằng cách viết đầy đủ
tên và ghép với các chữ cái đầu của họ và tên đệm. Nếu có nhiều người cùng email
thì từ người thứ 2 sẽ thêm số thứ tự vào email đó.

Cho trước các xâu họ tên (có thể không chuẩn). Hãy tạo ra các địa email tương
ứng.

Input:
Dòng 1 ghi số N là xâu họ tên trong danh sách
N dòng tiếp theo ghi lần lượt các xâu họ tên (không quá 50 ký tự)

Output: Ghi ra các email được tạo ra.

Ví dụ:
Input:
4
    nGUYEn    quaNG   vInH
   tRan   thi THU    huOnG
   nGO   quoC  VINH
 lE            tuAn    aNH

Output:
vinhnq@ptit.edu.vn
huongttt@ptit.edu.vn
vinhnq2@ptit.edu.vn
anhlt@ptit.edu.vn
*/

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	std::unordered_map<std::string, size_t> map;

	while (cases--) {

		std::string buf, head;
		std::getline(std::cin >> std::ws, buf);

		std::istringstream iss(buf);

		while (iss >> buf) {

			for (char &c : buf) {
				c = tolower(c);
			}

			if (iss.eof()) {
				head = buf + head;
				break;
			}

			head.push_back(buf[0]);
		}

		if (map.find(head) != map.end()) {

			++map[head];
			head += std::to_string(map[head]);

		} else map.emplace(head, 1);

		std::cout << head << "@ptit.edu.vn" << std::endl;
	}

	return 0;
}
