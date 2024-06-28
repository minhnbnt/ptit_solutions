/*
Cho dãy số a[] có n phần tử là các số nguyên dương khác nhau từng đôi một.
Hãy liệt kê tất cả các dãy con có từ 2 phần tử trở lên của dãy a[] thỏa mãn tính
chất tăng dần.

Dãy con tạo được bằng cách lấy ra các phần tử trong dãy a[] nhưng vẫn giữ nguyên
thứ tự ban đầu.
Coi mỗi dãy con như một xâu ký tự với các phần tử cách nhau một khoảng trống,
hãy liệt kê theo thứ tự từ điển.

Input
Dòng đầu ghi số n (không quá 20)

Dòng thứ 2 ghi n số của dãy a[]. Các số khác nhau từng đôi một và có giá trị
không quá 100.

Output
Ghi ra lần lượt các dãy con tăng dần theo thứ tự từ điển.

Ví dụ

Input:
4
6 3 7 11

Output:
3 11
3 7
3 7 11
6 11
6 7
6 7 11
7 11
*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

template <typename T>
struct Vec : public std::vector<T> {

	Vec<T>(void) = default;
	Vec<T>(size_t size) : std::vector<T>(size) {}

	friend void operator<<(std::ostream &os, const Vec<T> &v) {

		for (const T &element : v) {
			os << element << ' ';
		}

		os << '\n';
	}

	bool operator<(const Vec<T> &other) const {

		std::ostringstream oss_this, oss_other;
		oss_this << *this, oss_other << other;

		return oss_this.str() < oss_other.str();
	}
};

template <typename Iter>
void get_result(Iter begin, Iter end, Vec<Vec<int>> &results) {

	static Vec<int> current;

	if (current.size() > 1) {
		results.push_back(current);
	}

	while (begin != end) {

		if (!current.empty() && current.back() > *begin) {
			++begin;
			continue;
		}

		current.push_back(*begin);

		get_result(++begin, end, results);

		current.pop_back();
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	size_t size;
	std::cin >> size;

	Vec<int> vec(size);
	for (int &x : vec) {
		std::cin >> x;
	}

	Vec<Vec<int>> results;
	get_result(vec.begin(), vec.end(), results);

	std::sort(results.begin(), results.end());
	for (const Vec<int> &v : results) {
		std::cout << v;
	}

	return 0;
}
