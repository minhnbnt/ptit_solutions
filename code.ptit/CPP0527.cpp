/*
Giá trị độ đo thời gian được biểu diễn bởi ba thành phần: giờ, phút, giây.

Cho N giá trị thời gian, hãy sắp xếp danh sách theo thứ tự tăng dần.

Input:
Dòng đầu ghi số nguyên dương N (không quá 5000) là số lượng giá trị thời gian
cần sắp xếp.
Mỗi giá trị thời gian biểu diễn trên một dòng bằng ba số nguyên
dương, lần lượt là số giờ, số phút, số giây. Trong đó số giờ đảm bảo nhỏ hơn
100, số phút và số giây đảm bảo đúng quy tắc (tức là không quá 59).

Output:
In ra danh sách đã sắp xếp theo thứ tự tăng dần.

Ví dụ:
Input:
3
11 20 20
14 20 14
11 15 12

Output:
11 15 12
11 20 20
14 20 14
*/

#include <algorithm>
#include <iostream>
#include <vector>

struct time {
	unsigned hour, minute, second;
};

int comparator(const struct time &a, const struct time &b) {
	if (a.hour != b.hour) return a.hour < b.hour;
	if (a.minute != b.minute) return a.minute < b.minute;
	return a.second < b.second;
}

int main(void) {

	unsigned ele;
	std::cin >> ele;

	std::vector<struct time> times(ele);
	for (struct time &t : times) {
		std::cin >> t.hour >> t.minute >> t.second;
	}

	std::sort(times.begin(), times.end(), comparator);
	for (struct time t : times)
		std::cout << t.hour << ' ' << t.minute << ' ' << t.second << '\n';
	std::cout << std::flush;

	return 0;
}
