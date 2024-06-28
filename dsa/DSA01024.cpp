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

Ví dụ
Input:
6 2
DONG TAY NAM BAC TAY BAC

Output:
BAC DONG
BAC NAM
BAC TAY
DONG NAM
DONG TAY
NAM TAY
*/

#include <iostream>
#include <set>
#include <vector>

template <typename Iter>
void all_names(Iter begin, Iter end, size_t size) {

	static std::vector<Iter> vec;
	if (vec.size() == size) {

		for (Iter &it : vec) {
			std::cout << *it << ' ';
		}

		std::cout.put('\n');
		return;
	}

	while (begin != end) {

		vec.push_back(begin);

		all_names(++begin, end, size);

		vec.pop_back();
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	size_t size, length_of_name;
	std::cin >> size >> length_of_name;

	std::set<std::string> set;
	for (size_t i = 0; i < size; ++i) {

		std::string token;
		std::cin >> token;

		set.insert(token);
	}

	all_names(set.begin(), set.end(), length_of_name);

	return 0;
}
