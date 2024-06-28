/*
Hôm nay là ngày 22/02/2022. Một ngày đặc biệt.
Chỉ có hai chữ số là 0 và 2.
Đồng thời viết xuôi viết ngược tám chữ số ta đều được cùng một kết quả.

Nhiệm vụ của bạn trong ngày đặc biệt này là hãy liệt kê hết tất cả các ngày hợp
lệ chỉ có 2 chữ số 0 và 2.

Một số chú ý:
Luôn có đủ 8 chữ số của ngảy tháng năm và hai dấu gạch chéo.
Ngày và tháng có thể có chữ số 0 ở đầu nhưng với năm thì không được phép.
Tức là ta chỉ tính các ngày bắt đầu từ năm 2000 trở về sau.

Bài toán không có dữ liệu vào. Bạn chỉ cần liệt kê kết quả gồm tất cả các ngày
tháng hợp lệ.

Coi dãy ký tự ngày tháng là một xâu ký tự. Hãy liệt kê theo đúng thứ tự từ điển
tăng dần.
*/

package main

import "fmt"

var (
	VALID_DAYS   = []int{2, 20, 22}
	VALID_MONTHS = []int{2}

	VALID_YEARS = []int{
		2000, 2002, 2020, 2022,
		2200, 2202, 2220, 2222,
	}
)

func main() {
	for _, day := range VALID_DAYS {
		for _, month := range VALID_MONTHS {
			for _, year := range VALID_YEARS {
				fmt.Printf("%02d/%02d/%d\n", day, month, year)
			}
		}
	}
}
