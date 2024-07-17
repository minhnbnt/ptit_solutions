/*
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một.

Hãy sắp xếp dãy theo thứ tự giảm dần, sau đó liệt kê tất cả các dãy con (đúng
thứ tự trước sau) của A[] có tổng các phần tử là số lẻ.

Các dãy con được liệt kê theo thứ tự từ điển tăng dần.

Input
Dòng đầu ghi số bộ test, mỗi test có 2 dòng:

Dòng đầu ghi số N (2 < N <15)
Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác
nhau từng đôi một.

Output
Với mỗi test, liệt kê tất cả các dãy con có tổng các phần tử là số lẻ theo thứ
tự từ điển tăng dần, mỗi dãy con trên một dòng.

Ví dụ

Input
1
4
2 3 4 5

Output:
3
3 2
4 3
4 3 2
5
5 2
5 4
5 4 2
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
class Generator {

	std::vector<T> current;
	std::vector<std::vector<T>> records;

	static bool comparator(const std::vector<T> &a, const std::vector<T> &b) {

		const size_t size_a = a.size(), size_b = b.size();
		const size_t min_size = std::min(a.size(), b.size());

		for (size_t i = 0; i < min_size; i++) {
			if (a[i] != b[i]) {
				return a[i] < b[i];
			}
		}

		return a.size() < b.size();
	}

public:

	template <typename Collection>
	Generator(const Collection &c) {
		generate(std::begin(c), std::end(c));
		std::sort(std::begin(records), std::end(records), comparator);
	}

	template <typename Iter>
	void generate(Iter begin, Iter end) {

		if (std::accumulate(current.begin(), current.end(), 0) % 2 != 0) {
			records.push_back(current);
		}

		while (begin != end) {

			current.push_back(*begin);
			begin++;

			generate(begin, end);

			current.pop_back();
		}

		if (current.empty()) {
			current.shrink_to_fit();
		}
	};

	const std::vector<std::vector<T>> &get_records(void) const {
		return records;
	}
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t size;
		std::cin >> size;

		std::vector<int> vec(size);
		for (int &x : vec) {
			std::cin >> x;
		}

		std::sort(std::begin(vec), std::end(vec), std::greater<int>());

		const Generator<int> gen(vec);

		for (auto &record : gen.get_records()) {

			for (const int element : record) {
				std::cout << element << ' ';
			}

			std::cout.put(10);
		}

		std::cout.flush();
	}

	return 0;
}
