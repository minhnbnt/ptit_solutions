/*
Một số được coi là đẹp nếu đó là số thuận nghịch và chỉ toàn các chữ số chẵn.
Viết chương trình đọc vào các số nguyên dương có không quá 500 chữ số và kiếm
tra xem số đó có đẹp hay không.

Input:
Dòng đầu tiên ghi số bộ test.
Mỗi bộ test viết trên một dòng số nguyên dương n không quá 500 chữ số.

Output:
Mỗi bộ test viết ra trên một dòng chữ YES nếu đó là số đẹp, chữ NO nếu ngược lại

Ví dụ

Input
4
123456787654321
86442824468
8006000444422220000222244440006008
235365789787654324567856578654356786556

Output
NO
YES
YES
NO
*/

#include <cstring>
#include <iostream>
#include <string>

bool beauty_of(const std::string &num) {

	for (const char &c : num)
		if (strchr("02468", c) == NULL) {
			return false;
		}

	return true;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string num;
		std::getline(std::cin >> std::ws, num);

		std::cout << (beauty_of(num) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
