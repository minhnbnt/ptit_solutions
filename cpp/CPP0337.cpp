#include <iostream>
#include <unordered_set>
#include <limits>

int main(void) {
	
	unsigned cases;
	std::cin >> cases;
	
	while (cases--) {
		
		std::string str;
		std::getline(std::cin >> std::ws, str);
		
		size_t i, j, min_length = std::numeric_limits<size_t>::max();
		size_t num_chars = std::unordered_set<char>(str.begin(), str.end()).size();
		for (i = 0; i < str.size(); ++i) {
			
			std::unordered_set<char> char_set;
			
			for (j = i; j < str.size(); ++j) {
								
				if (char_set.size() == num_chars) {
					break;
				}
				
				char_set.insert(str[j]);

			}
			
			if (char_set.size() != num_chars) {
				break;
			}
			
			min_length = std::min(min_length, j - i);
		}
		
		std::cout << min_length << std::endl;
	}
	
	return 0;
}
