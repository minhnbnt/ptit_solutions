#include <iostream>

int main(void) {
	
	std::string input;
	std::cin >> input;
	
	input.push_back('A');
	
	unsigned long long result = 0;
	unsigned long long swap_from_first = 0, swap_once = 0;
	for (size_t i = 0; i < input.size(); ++i) {
		
		const char c = input[i];
		
		if (c == 'B') {
			++swap_once;
			continue;
		}
	}
	
	if (input[0] == 'B') {
		result -= 1;
	}
	
	std::cout << result << std::endl;
	
	return 0;
}
