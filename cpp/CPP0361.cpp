/*
(Giới hạn thời gian chạy: 10 giây)

Hệ thống quản lý đào tạo của PTIT đang gặp một vấn đề về bảo mật. Do sự cố này, các account bị đổi
thành tên viết liền của các sinh viên. Và chỉ cần đánh một chuỗi kí tự có chứa mật khẩu là có thể
đăng nhập vào hệ thống. Chẳng hạn sinh viên A có mật khẩu là “abcd”, nếu ai đó đăng nhập với tài
khoản là tên của A, mật khẩu “abcdef” hay “aaaabcd” đều được chấp nhận.

Nhân cơ hội này, rất nhiều bạn sinh viên đã cố gắng hack vào tài khoản của những người khác. Cho
biết danh sách mật khẩu của tất cả các user, bài toán đặt ra là hãy xác định xem có nhiều nhất bao
nhiêu trường hợp user này có thể login vào user khác?

Input:
Dòng đầu tiên là số nguyên N (1 ≤  N ≤  100 000).
N dòng tiếp theo, mỗi dòng chứa mật khẩu của một user, có độ dài không quá 10 kí tự và chỉ gồm các
kí tự thường.

Output:
In ra một số nguyên là đáp án đáp án tìm được.

Ví dụ:
Input:
3
aaa
aa
abb

Output:
1

---------

Input:
3
x
x
xy

Output:
4
*/

#include <iostream>
#include <string>
#include <vector>

int main(void) {

	size_t users, i, j;
	std::cin >> users;

	std::vector<std::string> pass(users);
	for (std::string &s : pass) {
		std::cin >> std::ws >> s;
	}

	unsigned long long counter = 0;
	for (i = 0; i < users; ++i) {
		for (j = 0; j < users; ++j) {
			if (i == j) continue;
			if (pass[i].find(pass[j]) != std::string::npos) {
				++counter;
			}
		}
	}

	std::cout << counter << std::endl;

	return 0;
}
