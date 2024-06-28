/*
Hãy viết chương trình nhận vào một chuỗi (có thể khá dài)
các ký tự số và đưa ra màn hình hoán vị kế tiếp của các ký tự số đó
(với ý nghĩa là hoán vị có giá trị lớn hơn tiếp theo nếu ta coi chuỗi đó là một
giá trị số nguyên).
Chú ý: Các ký tự số trong dãy có thể trùng nhau.

Ví dụ:   123 -> 132
         279134399742 -> 279134423799

Cũng có trường hợp sẽ không thể có hoán vị kế tiếp. Ví dụ như khi đầu vào là
chuỗi 987.

Dữ liệu vào: Dòng đầu tiên ghi số nguyên t là số bộ test (1 ≤ t ≤ 1000).
Mỗi bộ test có một dòng, đầu tiên là số thứ tự bộ test, một dấu cách, sau đó là
chuỗi các ký tự số, tối đa 80 phần tử.

Kết quả:
Với mỗi bộ test hãy đưa ra một dòng gồm thứ tự bộ test, một dấu cách, tiếp theo
đó là hoán vị kế tiếp hoặc chuỗi “BIGGEST” nếu không có hoán vị kế tiếp.

Ví dụ:
INPUT
3
1 123
2 279134399742
3 987

OUTPUT
1 132
2 279134423799
3 BIGGEST
*/

#include <algorithm>
#include <iostream>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		int id;
		std::cin >> id;
		std::cout << id << ' ';

		std::string digits;
		std::cin >> std::ws >> digits;

		bool is_biggest = !std::next_permutation(digits.begin(), digits.end());
		std::cout << (is_biggest ? "BIGGEST" : digits) << std::endl;
	}

	return 0;
}
