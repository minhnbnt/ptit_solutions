package main

import "fmt"

var VALID_DAYS = []int{2, 20, 22}
var VALID_MONTHS = []int{2}

var VALID_YEARS = []int{
	2000, 2002, 2020, 2022,
	2200, 2202, 2220, 2222,
}

func main() {
	for _, day := range VALID_DAYS {
		for _, month := range VALID_MONTHS {
			for _, year := range VALID_YEARS {
				fmt.Printf("%02d/%02d/%d\n", day, month, year)
			}
		}
	}
}
