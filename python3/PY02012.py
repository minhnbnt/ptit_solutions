from ctypes import byref, CDLL, c_int


def next_int() -> int:
    number = c_int()
    libc.scanf(b"%i", byref(number))
    return number.value


libc = CDLL("libc.so.6")

size = next_int()
array = [next_int() for _ in range(size)]

odds, evens = [], []

for element in array:
    if element % 2 == 0:
        evens.append(element)
    else:
        odds.append(element)

odds.sort()
evens.sort(reverse=True)

for element in array:
    if element % 2 == 0:
        print(evens.pop(), end=" ")
    else:
        print(odds.pop(), end=" ")
