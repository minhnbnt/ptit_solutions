#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;

u64 number_of_operator(unsigned *begin, unsigned *end) {
	
	u64 counter = 0;
	
	while (begin < end) {
		
		const unsigned left = *begin;
		const unsigned right = *(end - 1);
		
		if (left < right) {
			
			++begin;
			*begin += left;
			
			++counter;
			continue;
		}
		
		if (left > right) {
			
			--end;
			*(end - 1) += right;
			
			++counter;
			continue;
		}
		
		++begin, --end;
	}
	
	return counter;
}

int main(void) {
	
	unsigned cases;
	scanf("%u", &cases);
	
	while (cases-- > 0) {
		
		size_t ele, i;
		scanf("%zu", &ele);
		
		unsigned *ptr = (unsigned *)malloc(sizeof(int) * ele);
		for (i = 0; i < ele; ++i) {
			scanf("%u", &ptr[i]);
		}
		
		printf("%llu\n", number_of_operator(ptr, ptr + ele));
		fflush(stdout);
		
		free(ptr);
	}
	
	return 0;
}
