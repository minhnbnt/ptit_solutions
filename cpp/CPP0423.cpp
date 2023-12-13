#include <iostream>
#include <vector>

int main(void) {
	
	unsigned cases;
	std::cin >> cases;
	
	while (cases--) {
		
		size_t ele, i;
		int target;
		std::cin >> ele >> target;
		
		size_t window_size = 0;
		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
			if (x <= target) {
				++window_size;
			}
		}
		
		size_t result, counter = 0;
		for (i = 0; i < window_size; ++i) {
			if (vec[i] <= target) ++counter;
		}
		result = window_size - counter;
		for (i = window_size; i < ele; ++i) {
			
			if (vec[i] <= target) {
				++counter;
			}
			
			if (vec[i - window_size] <= target) {
				--counter;
			}
			
			result = std::min(result, window_size - counter);
		}
		
		std::cout << result << std::endl;
	}
	
	return 0;
}
