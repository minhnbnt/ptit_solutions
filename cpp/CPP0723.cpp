#include <bits/stdc++.h>

using namespace std;

const char *get_nums(int digit) {
	
	static const char *nums[] = { "1", "1", "2", "3", "322",
	                              "5", "53", "7", "7222", "7332" };
	                           
	return nums[digit];
}

int main(void) {
	
	unsigned cases;
	cin >> cases;
	
	while (cases-- > 0) {
		
		size_t len;
		string num;
		cin >> len >> num;
		
		string result;
		for (const char c : num) {
			
			const int digit = c - '0';
			const char * const nums = get_nums(digit);
			
			result.append(nums);
		}
		
		sort(result.rbegin(), result.rend());
		
		while (result.back() == '1') {
			result.pop_back();
		}
		
		std::cout << result << endl;
	}
	
	return 0;
}
