#include <iostream>
#include <vector>
#include <limits>

int main(void) {
	
	unsigned cases;
	std::cin >> cases;
	
	while (cases--) {
		
		using i64 = long long;
		
		i64 target, sum;
		size_t ele, i, j;
		std::cin >> ele >> target;
		
		std::vector<i64> vec(ele);
		for (i64 &x : vec) {
			std::cin >> x;
		}
		
		sum = i = j = 0;
		size_t result = std::numeric_limits<size_t>::max();
		
		while (true) {
			
			if (sum > target && i < ele) {
				
				result = std::min(result, j - i);
				
				sum -= vec[i];
				++i;
				
				continue;
			}
			
			if (j < ele) {
				
				sum += vec[j];
				++j;
				
				continue;
			}
			
			break;
		}
		
		if (result == std::numeric_limits<size_t>::max()) {
			std::cout << -1 << std::endl;
			continue;
		}
		
		std::cout << result << std::endl;
	}
	
	return 0;
}
