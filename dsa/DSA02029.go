/*
Bài toán Tháp Hà Nội đã rất nổi tiểng.
Bắt đầu có các đĩa xếp chồng lên cột A theo thứ tự kích thước giảm dần, nhỏ nhất
ở trên cùng.

Cột B và cột C ban đầu không có đĩa nào cả.

Mục tiêu của bạn là di chuyển toàn bộ các đĩa theo đúng thứ tự về cột C, tuân
theo các quy tắc sau:

Mỗi lần chỉ có thể di chuyển một đĩa.
Mỗi lần di chuyển sẽ lấy đĩa trên từ một trong các cột và đặt nó lên trên một
cột khác. Không được đặt đĩa lên trên đĩa nhỏ hơn..

Input:
Số tự nhiên  0 < N < 10

Output:
In ra lần lượt từng bước theo mẫu trong ví dụ.
Chú ý giữa các chữ cái và dấu -> có khoảng trống.

Ví dụ:
Input
3

Ouput
A -> C
A -> B
C -> B
A -> C
B -> A
B -> C
A -> C
*/

package main

import "fmt"

func TowerOfHanoi(plates uint, fromRod, toRod, otherRod byte) {

	if plates == 0 {
		return
	}

	TowerOfHanoi(plates-1, fromRod, otherRod, toRod)

	fmt.Printf("%c -> %c\n", fromRod, toRod)

	TowerOfHanoi(plates-1, otherRod, toRod, fromRod)
}

func main() {

	var numberOfPlates uint
	fmt.Scan(&numberOfPlates)

	TowerOfHanoi(numberOfPlates, 'A', 'C', 'B')
}
