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
