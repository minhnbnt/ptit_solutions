/*
Axe chơi một trò chơi với Lina.
Họ định nghĩa hàm F(x) với số x nguyên dương là tích giai thừa các chữ số của x.

Ví dụ F(135)  = 1! * 3! * 5! = 720.

Đầu tiên, họ chọn một số a có n chữ số và có ít nhất một chữ số lớn hơn 1, có thể có chữ số không ở
đầu. Sau đó họ tìm một số nguyên dương x lớn nhất thỏa mãn:

X không chứa chữ số 0 hoặc 1
F(x) = F(a)

Hãy giúp Axe và Lina tìm ra được số đó.

Input
Dòng đầu tiên chứa số bộ test T (T < 100).
Mỗi test gồm một dòng chứa số n và số a (1 <= n <= 15).

Output
In ra kết quả mỗi test trên một dòng là số lớn nhất tìm được.

Example:
Input:
1
4 1234

Output:
33222
*/

#include <bits/stdc++.h>

using namespace std;

const char *get_nums(int digit) {

	static const char *nums[] = { "1", "1", "2", "3", "322", "5", "53", "7", "7222", "7332" };

	return nums[digit];
}

int main(void) {

	unsigned cases;
	cin >> cases;

	while (cases-- > 0) {

		size_t len;
		string num;
		cin >> len >> num;

		string result;
		for (const char c : num) {

			const int digit = c - '0';
			const char *const nums = get_nums(digit);

			result.append(nums);
		}

		sort(result.rbegin(), result.rend());

		while (result.back() == '1') {
			result.pop_back();
		}

		std::cout << result << endl;
	}

	return 0;
}
