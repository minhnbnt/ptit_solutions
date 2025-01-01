from collections import deque
from typing import Iterator

EVEN_DIGITS = ("0", "2", "4", "6", "8")


def generator() -> Iterator[str]:
    queue = deque(EVEN_DIGITS[1:])

    while True:
        first = queue.popleft()
        yield first + first[::-1]

        for digit in EVEN_DIGITS:
            queue.append(first + digit)


cases = int(input())

for _ in range(cases):
    n = int(input())

    for number in generator():
        if int(number) >= n:
            break

        print(number, end=" ")

    print()

