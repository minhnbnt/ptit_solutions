package main

import (
	"fmt"
	"sort"
)

type Task struct {
	id       int
	deadLine int
	profit   int
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var size int
		fmt.Scan(&size)

		tasks := make([]Task, size)

		for i := range tasks {
			fmt.Scan(&tasks[i].id)
			fmt.Scan(&tasks[i].deadLine)
			fmt.Scan(&tasks[i].profit)
		}

		sort.Slice(tasks, func(i, j int) bool {

			if tasks[i].profit != tasks[j].profit {
				return tasks[i].profit > tasks[j].profit
			}

			return tasks[i].deadLine > tasks[j].deadLine
		})

		tasksTaked, totalProfit := 0, 0
		isWorking := make(map[int]bool, size)

		for _, task := range tasks {
			for i := task.deadLine; i > 0; i-- {

				if isWorking[i] {
					continue
				}

				totalProfit += task.profit
				tasksTaked += 1

				isWorking[i] = true

				break
			}
		}

		fmt.Println(tasksTaked, totalProfit)
	}
}
