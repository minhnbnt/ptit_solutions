from typing import Iterator


def allBitsStr(length: int) -> Iterator[str]:
    current = []

    def generate() -> Iterator[str]:
        if len(current) == length:
            yield "".join(current)
            return

        for char in ["0", "1"]:
            current.append(char)
            yield from generate()

            current.pop()

    yield from generate()


cases = int(input())
for _ in range(cases):
    length, numberOfTrues = map(int, input().split())

    validBitStrings = (
        string  #
        for string in allBitsStr(length)
        if string.count("1") == numberOfTrues
    )

    print(*validBitStrings)
