#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

#define MODULO 10007

using u64 = unsigned long long;

int recusive_pow(int base, unsigned exp) {
	
	static std::unordered_map<int, std::vector<int>> result_map;
	
	auto it = result_map.find(base);
	
	if (it == result_map.end()) {
		result_map[base] = { 1 };
		it = result_map.find(base);
	}
	
	std::vector<int> &current = it->second;
	
	if (current.size() <= exp) {
		current.resize(exp + 1, 0);
	}
	
	if (current[exp] == 0) {
		
		u64 result = base;
		result *= recusive_pow(base, exp - 1);
		
		current[exp] = result % MODULO;
	}
	
	return current[exp];
}

using Exp_map = std::unordered_map<int, unsigned>;

Exp_map merge_map(const Exp_map &map1, const Exp_map &map2) {
	
	Exp_map result = map1;
	
	for (const auto &[base, exp] : map2) {
		
		auto it = result.find(base);
		
		if (it == result.end()) {
			result[base] = exp;
			continue;
		}
		
		it->second = std::max(exp, it->second);
	}
	
	return result;
}

void get_map_from(int x, Exp_map &mp) {
	
	for (int i = 2; i <= sqrt(x); ++i) {
		
		unsigned counter = 0;
		while (x % i == 0) {
			x /= i;
			++counter;
		}
		
		if (counter == 0) {
			continue;
		}
		
		mp.emplace(i, counter);
	}
	
	if (x > 1) {
		mp.emplace(x, 1);
	}
}

int lcm_from_map(const Exp_map &map) {
	
	u64 result = 1;
	
	for (const auto &[base, exp] : map) {
		result *= recusive_pow(base, exp);
		result %= MODULO;
	}
	
	return result;
}

u64 result;

template <typename Iter>
void gen_result(const Exp_map &parent_map, Iter begin, Iter end) {
	
	while (begin != end) {

		const Exp_map current_map = merge_map(parent_map, *begin);
		
		gen_result(current_map, ++begin, end);
		
		result += lcm_from_map(current_map);
		result %= MODULO;
	}
}

int main(void) {
	
	unsigned cases, i;
	std::cin >> cases;
	
	for (i = 1; i <= cases; ++i) {
		
		result = 0;
		
		unsigned ele;
		std::cin >> ele;
		
		std::vector<Exp_map> vec(ele);
		for (Exp_map &mp : vec) {
			
			int x;
			std::cin >> x;
			
			get_map_from(x, mp);
		}
		
		const Exp_map empty;
		
		gen_result(empty, vec.cbegin(), vec.cend());
		
		std::cout << "Case " << i << ": " << result << std::endl;
	}
	
	return 0;
}

