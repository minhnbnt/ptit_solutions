package main

import "fmt"

var (
	DX = []int{-1, -1, -1, 0, 0, 1, 1, 1}
	DY = []int{-1, 0, 1, -1, 1, -1, 0, 1}
)

type PlayGround [][]byte

func (self PlayGround) FillLake(x, y int) {

	if x < 0 || y < 0 {
		return
	}

	if x >= len(self) || y >= len(self[x]) {
		return
	}

	if self[x][y] != 'W' {
		return
	}

	self[x][y] = '.'

	for i := range DX {

		newX := x + DX[i]
		newY := y + DY[i]

		self.FillLake(newX, newY)
	}
}

func main() {

	var row, col int
	fmt.Scan(&row, &col)

	playGround := make(PlayGround, row)

	for i := range playGround {

		var line string
		fmt.Scan(&line)

		playGround[i] = []byte(line)
	}

	counter := 0
	for i := range playGround {
		for j := range playGround[i] {

			if playGround[i][j] != 'W' {
				continue
			}

			playGround.FillLake(i, j)
			counter++
		}
	}

	fmt.Println(counter)
}
