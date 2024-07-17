package main

import (
	"bufio"
	"container/list"
	"os"
)

func main() {

	stdio := bufio.NewReadWriter(
		bufio.NewReader(os.Stdin),
		bufio.NewWriter(os.Stdout),
	)

	defer stdio.Flush()

	buffer := list.New()
	buffer.PushBack('\n')

	cursor := buffer.Front()

	for {

		keyPressed, _, _ := stdio.ReadRune()

		if keyPressed == '\n' {
			break
		}

		switch keyPressed {
		case '<':
			if cursor != buffer.Front() {
				cursor = cursor.Prev()
			}

			continue

		case '>':
			if cursor != buffer.Back() {
				cursor = cursor.Next()
			}

			continue

		case '-':
			if cursor != buffer.Front() {
				buffer.Remove(cursor.Prev())
			}

			continue
		}

		buffer.InsertBefore(keyPressed, cursor)
	}

	for ptr := buffer.Front(); ptr != nil; ptr = ptr.Next() {
		stdio.WriteRune(ptr.Value.(rune))
	}
}
