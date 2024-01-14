package main

import "fmt"

func longest_common_substr(s1 string, s2 string) uint {

	type Key [2]int
	cache := make(map[Key]uint)

	var cache_helper func(int, int) uint
	cache_helper = func(i int, j int) uint {

		cache_key := Key{i, j}

		if value, has := cache[cache_key]; has {
			return value
		}

		if i == len(s1) || j == len(s2) {
			return 0
		}

		var result uint
		if s1[i] != s2[j] {
			result = max(cache_helper(i+1, j), cache_helper(i, j+1))
		} else {
			result = 1 + cache_helper(i+1, j+1)
		}

		cache[cache_key] = result
		return result
	}

	return cache_helper(0, 0)
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var s1, s2 string
		fmt.Scanln(&s1)
		fmt.Scanln(&s2)

		fmt.Println(longest_common_substr(s1, s2))
	}

	return
}
