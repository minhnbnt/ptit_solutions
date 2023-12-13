#include <iostream>
#include <vector>

using u64 = unsigned long long;

const u64 mod = 1e9 + 7;

u64 __combination(int n, int k) {
	
	if (k == 0 || n == k) return 1;
	
	return __combination(n - 1, k) 
	     + __combination(n - 1, k - 1);
}

u64 combination(unsigned n, unsigned k) {
	
	if (n < k) {
		throw std::runtime_error("k can't be greater than n");
	}
	
	if (k == 0 || n == k) {
		return 1;
	}
	
	static std::vector<std::vector<u64>> dp;
	
	if (dp.size() <= n) {
		dp.resize(n + 1);
	}
	
	if (dp[n].size() <= k) {
		dp[n].resize(k + 1, 0);
	}
	
	if (dp[n][k] == 0) {
		
		dp[n][k] = combination(n - 1, k);
		dp[n][k] += combination(n - 1, k - 1);
		
		dp[n][k] %= mod;
	}
	
	return dp[n][k];
}

int main(void) {
	
	unsigned cases;
	std::cin >> cases;
	
	while (cases--) {
		
		int n, k;
		std::cin >> n >> k;
		
		std::cout << combination(n, k) << std::endl;
	}
	
	return 0;
}
