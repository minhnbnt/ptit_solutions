/*
Cho file dữ liệu dạng văn bản DATA.in có thể chứa cả số và ký tự.

Hãy lọc ra các số nguyên int trong file và tính tổng các số đó.

Chú ý: file dữ liệu có rất nhiều dòng với rất nhiều số và ký tự xen kẽ nhau. Chỉ
tính tổng các số thỏa mãn điều kiện là số kiểu int.

Input
File văn bản DATA.in có không quá 1000 dòng.

Output
Ghi ra giá trị tổng các số tính được.

Ví dụ:
DATA.in:
12 3 4 5 6 7
Aaa 1 1 Bbb XXX yyy 5 5
999999999999999999999999

Output:
9
58
*/

#include <fstream>
#include <iostream>
#include <string>

int main(void) {

	long long sum = 0;
	std::string buf;
	std::ifstream ifs("DATA.in");

	while (ifs >> buf) {

		int x;

		try {
			x = std::stoi(buf);
		} catch (const std::invalid_argument &err) {
			continue;
		} catch (const std::out_of_range &err) {
			continue;
		}

		sum += x;
	}

	std::cout << sum << std::endl;

	return 0;
}
