/*
Cho một danh sách tên người và ngày tháng năm sinh.

Hãy tìm ra người trẻ nhất và người già nhất.

Input
Dòng 1 ghi số N là số người (không quá 100).
N dòng tiếp theo, mỗi dòng ghi tên (xâu ký tự không có khoảng trống và không quá 15 ký tự, sau đó là
dãy ký tự mô tả ngày tháng năm sinh theo chuẩn dd/mm/yyyy.

Output
Dòng đầu ghi ra tên người trẻ nhất.
Dòng thứ 2 ghi ra tên người già nhất.
Dữ liệu đảm bảo không có 2 người nào trùng ngày sinh.

Ví dụ
Input
5
Nam 01/10/1991
An 30/12/1990
Binh 15/08/1993
Tam 18/09/1990
Truong 20/09/1990

Output
Binh
Tam
*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>

struct person {
	std::string first_name;
	int date, month, year;
};

int cmp(const person &a, const person &b) {
	if (a.year != b.year) return a.year < b.year;
	if (a.month != b.month) return a.month < b.month;
	return a.date < b.date;
}

int main(void) {

	unsigned ele;
	std::cin >> ele;

	std::deque<person> deq(ele);
	for (person &p : deq) {

		std::string buf;
		std::getline(std::cin >> std::ws, buf);
		std::istringstream iss(buf);

		iss >> std::ws >> p.first_name;
		int *arr[] = { &p.date, &p.month, &p.year };

		for (int *p : arr) {
			std::string tmp;
			std::getline(iss >> std::ws, tmp, '/');
			*p = std::stoi(tmp);
		}
	}

	std::sort(deq.begin(), deq.end(), cmp);

	std::cout << deq.back().first_name << '\n';
	std::cout << deq.front().first_name << std::endl;

	return 0;
}
