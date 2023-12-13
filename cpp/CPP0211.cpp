#include <iostream>
#include <memory>

int main(void) {
	
	unsigned cases;
	std::cin >> cases;
	
	while (cases-- > 0) {
		
		using i64 = long long;
		
		size_t ele, i, j;
		std::cin >> ele;
		
		auto ptr = std::make_unique<i64[]>(ele);
		for (i = 0; i < ele; ++i) {
			std::cin >> ptr[i];
		}
		
		size_t max_distance = 0;
		for (i = 0; i < ele; ++i) {
			
			for (j = ele - 1; j > i; --j) {
				if (ptr[i] <= ptr[j]) {
					break;
				}
			}
			
			const size_t distance = j - i;
			max_distance = std::max(max_distance, distance);
		}
		
		std::cout << max_distance << std::endl;
	}
	
	return 0;
}
