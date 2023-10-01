/*
Tí năm nay đã lên lớp 1 rồi, Tết đến Tí rất vui vì nhận được rất nhiều lời chúc.

Vì mới tập viết nên Tí đã ghi lại tất cả các lời chúc đó. Cũng vì rất trân trọng
các lời chúc nên Tí đã ghi tất cả các lời chúc bằng chữ IN HOA, tuy nhiên do mới
tập viết nên Tí ghi không có dấu. Giờ ngồi lật lại cuốn nhật ký ghi các lời
chúc, Tí thấy mình đã ghi được n lời chúc.

Tí muốn biết có bao nhiêu lời chúc khác nhau (hai lời chúc được gọi là khác nhau
nếu chúng có độ dài khác nhau hoặc tồn tại ít nhất một vị trí mà ký tự ở vị trí
đó của hai lời chúc là khác nhau, hay nói cách khác, đó là hai xâu ký tự khác
nhau). Bạn hãy lập chương trình giúp Tí đếm xem có bao nhiêu lời chúc khác nhau
nhé.

Input:
Dòng đầu chứa số nguyên dương n là số lời chúc Tí ghi được;
n dòng tiếp theo, mỗi dòng chứa một xâu ký tự S là một lời chúc.

n, S thỏa mãn ràng buộc: 1 ≤ n ≤ 10^4; Các lời chúc S có độ dài không quá 30 ký
tự gồm các chữ cái la tinh IN HOA ‘A’…’Z’ và dấu cách.

Output:
Một số nguyên dương duy nhất là số lời chúc khác nhau.

Ví dụ:
Input:
4
CHUC MUNG NAM MOI
HAPPY NEW YEAR
CHUC MUNG TUOI MOI
CHUC MUNG NAM MOI

Output:
3
*/

#include <iostream>
#include <unordered_set>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::unordered_set<std::string> se;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string s;
		std::getline(std::cin >> std::ws, s);

		se.insert(s);
	}

	std::cout << se.size() << std::endl;

	return 0;
}
