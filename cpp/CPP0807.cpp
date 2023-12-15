/*
Trong lý thuyết tập hợp, một tập hợp chỉ được phép chứa các giá trị phân biệt và luôn luôn lưu các
giá trị theo thứ tự tăng dần.

Khai báo lớp IntSet và viết các phương thức để thực hiện các thao tác trên tập hợp số nguyên. Sử
dụng lớp IntSet để in ra tập hợp các số nguyên là giao của hai tập số trong 2 dãy ban đầu.

Input - file văn bản DATA.in
Dòng đầu ghi 2 số n và m (1 < n,m <100).
Dòng thứ 2 ghi n số của a[].
Dòng thứ 3 ghi m số của b[].
Các số đều dương và nhỏ hơn 1000.

Output
Ghi tập giao của A và B trên một dòng theo thứ tự từ nhỏ đến lớn.

Ví dụ
DATA.in
5 6
1 2 3 4 5
3 4 5 6 7 8

Output
3 4 5
*/

#include <fstream>
#include <iostream>
#include <set>
#include <vector>

struct IntSet : public std::set<int> {

	template <class Container>
	static IntSet from(const Container &container) {

		IntSet result;
		for (const int x : container) {
			result.insert(x);
		}

		return result;
	}

	template <class Container>
	IntSet union_with(const Container &other) const {

		IntSet result;
		for (const int x : other) {

			if (find(x) == end()) {
				continue;
			}

			result.insert(x);
		}

		return result;
	}
};

int main(void) {

	std::ifstream ifs("DATA.in");

	size_t size_a, size_b;
	ifs >> size_a >> size_b;

	std::vector<int> vecA(size_a);
	for (int &x : vecA) {
		ifs >> x;
	}

	std::vector<int> vecB(size_b);
	for (int &x : vecB) {
		ifs >> x;
	}

	const IntSet setA = IntSet::from(vecA);

	for (const int x : setA.union_with(vecB)) {
		std::cout << x << ' ';
	}
	std::cout << std::endl;

	return 0;
}
