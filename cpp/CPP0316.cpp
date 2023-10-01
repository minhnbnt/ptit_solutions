/*
Một số nguyên không âm n được gọi là số may mắn nếu tổng các chữ của n bằng 9
hoặc tổng các chữ số của n là số may mắn. Ví dụ các số 9, 108, 279 là các số may
mắn, còn các số 19, 289 không phải là số may mắn.

Yêu cầu: Cho số nguyên không âm n, hãy kiểm tra xem n có phải là số may mắn hay
không?

Input:
Dữ liệu vào gồm nhiều bộ dữ liệu tương ứng với nhiều test. Dòng đầu tiên chứa
một số nguyên dương không vượt quá 100 là số lượng các bộ dữ liệu. Các dòng tiếp
theo chứa các bộ dữ liệu.

Mỗi bộ dữ liệu gồm một dòng duy nhất chứa một số nguyên không âm n (n ≤ 10^100).

Output:
Với mỗi bộ dữ liệu, ghi ra trên một dòng câu trả lời, ghi số 1 nếu n là số may
mắn, ghi số 0 trong trường hợp ngược lại.

Example:
Input:
3
888
666
289

Output:
0
1
0
*/

#include <iostream>
#include <string>

using u64 = unsigned long long;

u64 sum_of_digits(const std::string &s) {

	u64 result = 0;
	for (const char &c : s) {
		result += c - '0';
	}
	return result;
}

bool is_lucky_number(std::string num) {

	if (num == "9") return true;
	if (num.length() == 1) return false;

	const u64 sum = sum_of_digits(num);
	return is_lucky_number(std::to_string(sum));
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string num;
		std::cin >> std::ws >> num;

		std::cout << is_lucky_number(num) << std::endl;
	}

	return 0;
}
