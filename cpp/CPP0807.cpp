/*
Trong lý thuyết tập hợp, một tập hợp chỉ được phép chứa các giá trị phân biệt và
luôn luôn lưu các giá trị theo thứ tự tăng dần.

Khai báo lớp IntSet và viết các phương thức để thực hiện các thao tác trên tập
hợp số nguyên. Sử dụng lớp IntSet để in ra tập hợp các số nguyên là giao của hai
tập số trong 2 dãy ban đầu.

Input - file văn bản DATA.in
Dòng đầu ghi 2 số n và m (1 < n,m <100).
Dòng thứ 2 ghi n số của a[].
Dòng thứ 3 ghi m số của b[].
Các số đều dương và nhỏ hơn 1000.

Output
Ghi tập giao của A và B trên một dòng theo thứ tự từ nhỏ đến lớn.

Ví dụ

DATA.in:
5 6
1 2 3 4 5
3 4 5 6 7 8

Output:
3 4 5
*/

#include <fstream>
#include <iostream>
#include <set>
#include <unordered_set>

namespace solution {

std::ifstream ifs("DATA.in");

class IntSet {

	std::unordered_set<int> set;

public:

	std::set<int> elements(void) {
		std::set<int> ordered(set.begin(), set.end());
		return ordered;
	}

	IntSet(unsigned ele) {
		while (ele--) {
			int x;
			ifs >> x;

			set.insert(x);
		}
	}

	IntSet sub_set_with(IntSet se) {
		IntSet subset(0);

		for (const int &x : se.set)
			if (set.find(x) != set.end()) {
				subset.set.insert(x);
			}

		return subset;
	}
};

} // namespace solution

int main(void) {

	using solution::IntSet;

	unsigned n, m;
	solution::ifs >> n >> m;

	IntSet a(n), b(m);

	for (int x : a.sub_set_with(b).elements()) {
		std::cout << x << ' ';
	}

	std::cout << std::endl;

	return 0;
}
