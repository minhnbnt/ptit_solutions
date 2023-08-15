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
