#include <iostream>
#include <vector>
#include <string>

int main(void) {	
	
	size_t users, i, j;
	std::cin >> users;
		
	std::vector<std::string> pass(users);
	for (std::string &s : pass) {
		std::cin >> std::ws >> s;
	}
	
	unsigned long long counter = 0;
	for (i = 0; i < users; ++i) {
		for (j = 0; j < users; ++j) {
			if (i == j) continue;
			if (pass[i].find(pass[j]) != std::string::npos) {
				++counter;
			}
		}
	}
	
	std::cout << counter << std::endl;
	
	return 0;
}
