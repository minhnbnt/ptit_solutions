/*
Cho hai xâu ký tự S1 và S2. Hãy viết chương trình tìm các từ chỉ xuất hiện trong
S1 mà không xuất hiện trong S2. Chú ý: mỗi từ chỉ liệt kê 1 lần.

Dữ liệu vào: Dòng 1 ghi số bộ test. Mỗi bộ test gồm 2 dòng, mỗi dòng ghi một xâu
ký tự độ dài không quá 200, chỉ bao gồm các ký tự viết thường và các khoảng
trống.

Kết quả: Với mỗi bộ test ghi ra các từ có trong S1 mà không có trong S2. Các từ
được ghi theo thứ tự từ điển.

Ví dụ:
Input:
2
abc ab ab ab abcd
ab abc
aaa xyz ab zzz abc dd dd abc
xyz dd ttt sas cdc

Output:
abcd
aaa ab abc zzz
*/

#include <iostream>
#include <set>
#include <sstream>
#include <string>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string buf1, buf2, str;
		std::getline(std::cin >> std::ws, buf1);
		std::getline(std::cin >> std::ws, buf2);
		std::istringstream iss1(buf1), iss2(buf2);

		std::set<std::string> set;
		while (iss1 >> str) set.insert(str);

		while (iss2 >> str)
			if (set.find(str) != set.end()) {
				set.erase(str);
			}

		for (const std::string &s : set) {
			std::cout << s << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
