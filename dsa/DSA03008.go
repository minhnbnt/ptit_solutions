package main

import (
	"fmt"
	"sort"
)

type Task struct {
	start  int
	finish int
}

func main() {

	var cases uint
	fmt.Scan(&cases)

	for ; cases > 0; cases-- {

		var numberOfTasks int
		fmt.Scan(&numberOfTasks)

		var tasks = make([]Task, numberOfTasks)
		for i := range tasks {
			fmt.Scan(&tasks[i].start)
		}
		for i := range tasks {
			fmt.Scan(&tasks[i].finish)
		}

		sort.Slice(tasks, func(i, j int) bool {

			if tasks[i].finish != tasks[j].finish {
				return tasks[i].finish < tasks[j].finish
			}

			return tasks[j].start > tasks[j].start
		})

		var result, prevFinish = 0, 0

		for _, task := range tasks {

			if task.start < prevFinish {
				continue
			}

			prevFinish = task.finish
			result++
		}

		fmt.Println(result)
	}
}
