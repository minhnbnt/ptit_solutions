from typing import Iterator


def allABStrings(length: int) -> Iterator[str]:
    chars = []

    def generator():
        if len(chars) == length:
            yield "".join(chars)
            return

        for bit in ["A", "B"]:
            chars.append(bit)
            yield from generator()

            chars.pop()

    yield from generator()


cases = int(input())
for _ in range(cases):
    size = int(input())

    for string in allABStrings(size):
        print(string, end=" ")

    print()
