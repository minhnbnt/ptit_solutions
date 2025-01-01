from collections import deque
from typing import Iterator

DIGITS = ["0", "1", "2"]


def generator() -> Iterator[str]:
    queue = deque(DIGITS[1:])

    while True:
        current = queue.popleft()
        yield current

        queue.extend(current + digit for digit in DIGITS)


cases = int(input())

for _ in range(cases):
    counter = int(input())

    for number in generator():
        if number.count("2") <= len(number) / 2:
            continue

        print(number, end=" ")

        counter -= 1
        if counter == 0:
            break

    print()
