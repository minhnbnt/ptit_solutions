package main

import (
	"bufio"
	"container/list"
	"os"
)

func main() {

	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)

	defer stdout.Flush()

	buffer := list.New()
	buffer.PushBack(byte('\n'))

	cursor := buffer.Front()

	for {

		keyPressed, _ := stdin.ReadByte()

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
		stdout.WriteByte(ptr.Value.(byte))
	}
}
