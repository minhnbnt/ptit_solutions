/*
Một thời không quá xa, điện thoại di động với chỉ các tính năng nghe, gọi, nhắn tin vẫn còn chiếm
đại đa số thiết bị cầm tay tại Việt Nam. Khi nhắn tin, người nhắn sẽ bấm các phím số một đến bốn lần
liên tiếp tương ứng với ký tự đi kèm ghi trên đó.

Cụ thể: các số và chữ cái tương ứng gồm:

2: ABC, 3: DEF, 4: GHI, 5: JKL
6: MNO, 7: PQRS, 8: TUV, 9: WXYZ

Cho trước dãy ký tự mô tả tin nhắn (không tính các ký tự khác ngoài danh sách nêu trên). Hãy kiểm
tra xem dãy số được nhấn ứng với dãy ký tự đó có phải số thuận nghịch hay không (chỉ xét tương ứng
giữa số và ký tự, không tính số đó được nhấn bao nhiêu lần, ví dụ tất cả A,B,C,a,b,c đều chỉ là một
chữ số 2).

Input
Dòng đầu tiên là số bộ test, không quá 1000.
Mỗi test là dãy ký tự mô tả tin nhắn.

Output
Ghi ra kết quả kiểm tra, YES nếu dãy số là thuận nghịch, NO nếu ngược lại.

Ví dụ
Input
2
BOHIMA
IamACoder

Output
YES
NO
*/

#include <cctype>
#include <cstring>
#include <iostream>
#include <vector>

unsigned get_key(const char c) {

	static const char *map[] = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };

	for (unsigned i = 2; i <= 9; ++i)
		if (strchr(map[i - 2], toupper(c)) != NULL) {
			return i;
		}

	return 0;
}

bool is_reversible(const std::vector<unsigned> &vec) {

	const size_t &size = vec.size();

	for (size_t i = 0; i < size; ++i)
		if (vec.at(i) != vec.at(size - i - 1)) {
			return false;
		}

	return true;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::getline(std::cin >> std::ws, input);

		std::vector<unsigned> keys;
		for (const char &c : input) {

			unsigned key_pressed = get_key(c);

			keys.push_back(key_pressed);
		}

		std::cout << (is_reversible(keys) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
