/*
Kỳ thi ICPC có K đội của PTIT tham gia và đội tuyển đang rất đau đầu không biết
chọn các cái tên như thế nào cho các đội.
Yêu cầu phải đảm bảo tên không có khoảng trống và không được trùng nhau.
Sau khi thảo luận, có N cái tên được đề xuất (có thể bị trùng nhau).
Với K<15 và 4 < N < 30.

Hãy liệt kê tất cả danh sách các tổ hợp K cái tên khác nhau có thể được tạo ra
theo thứ tự từ điển.

Input
Dòng đầu ghi 2 số N và K.

Tiếp theo là 1 dòng ghi N cái tên, mỗi cái tên có độ dài không quá 15 và cách
nhau một khoảng trống. Tất cả đều là ký tự in hoa.

Output
Ghi ra tất cả các tổ hợp tên có thể được lựa chọn theo thứ tự từ điển.

Tức là các tên trong mỗi tổ hợp liệt kê theo thứ tự từ điển và các tổ hợp cũng
được liệt kê theo thứ tự từ điển.

Ví dụ:
Input
6 2
DONG TAY NAM BAC TAY BAC

Output
BAC DONG
BAC NAM
BAC TAY
DONG NAM
DONG TAY
NAM TAY
*/

#include <iostream>
#include <set>
#include <string>
#include <vector>

template <typename Iter>
void print_all_name(Iter begin, Iter end, size_t size) {

	static std::vector<Iter> result;
	if (result.size() == size) {

		for (Iter it : result) {
			std::cout << *it << ' ';
		}

		std::cout.put('\n');
		return;
	}

	while (begin != end) {

		result.push_back(begin);
		begin++;

		print_all_name(begin, end, size);

		result.pop_back();
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	size_t size, name_length, i;
	std::cin >> size >> name_length;

	std::set<std::string> names;
	for (i = 0; i < size; i++) {

		std::string name;
		std::cin >> name;

		names.insert(name);
	}

	print_all_name(names.begin(), names.end(), name_length);
	std::cout.flush();

	return 0;
}
