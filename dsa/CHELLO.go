/*
Viết chương trình in ra màn hình dòng chữ:

Hello PTIT.

Input
Không có dữ liệu vào

Output
Hello PTIT.
*/

package main

import (
	"syscall"
	"unsafe"
)

func main() {

	message := []byte("Hello PTIT.\n")

	syscall.Syscall(syscall.SYS_WRITE,
		uintptr(syscall.Stdout),
		uintptr(unsafe.Pointer(&message[0])),
		uintptr(len(message)))
}
