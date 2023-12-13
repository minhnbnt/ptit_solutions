#include <fstream>
#include <iostream>
#include <vector>
#include <set>

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
