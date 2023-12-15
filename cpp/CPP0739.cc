/*
Cho mảng A[] chỉ bao gồm các ký tự I hoặc D. Ký tự I được hiểu là tăng (Increasing) ký tự D được
hiểu là giảm (Degreeasin). Sử dụng các số từ 1 đến 9, hãy đưa ra số nhỏ nhất được đoán nhận từ mảng
A[]. Chú ý, các số không được phép lặp lại. Dưới đây là một số ví dụ mẫu:

A[] = “I”        : số tăng nhỏ nhất là 12.
A[] = “D”        : số giảm nhỏ nhất là 21
A[] = ”DD”       : số giảm nhỏ nhất là 321
A[] = “DDIDDIID” : số thỏa mãn 321654798
Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ID
T, Length(A) thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ Length(A) ≤ 9; .

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
4
I
D
DD
DDIDDIID

Output:
12
21
321
321654798
*/

#include <iostream>
#include <stack>
#include <string>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::cin >> std::ws >> input;

		int target = 1;

		std::stack<int> stk;
		stk.push(target);

		for (const char &c : input) {

			++target;

			if (c == 'I') {
				while (!stk.empty()) {
					std::cout << stk.top();
					stk.pop();
				}
			}

			stk.push(target);
		}

		while (!stk.empty()) {
			std::cout << stk.top();
			stk.pop();
		}

		std::cout << std::endl;
	}
}
