from ctypes import CDLL

libc = CDLL("libc.so.6")

libc.puts(b"Welcome to python.")
libc.fflush(None)
