from typing import Iterator


def allValidBitsStr(length: int, numberOfTrues: int) -> Iterator[str]:
    current = []

    def generate() -> Iterator[str]:

        if len(current) == length:
            bitsStr = "".join(current)

            if bitsStr.count("1") == numberOfTrues:
                yield bitsStr

            return

        for char in ["0", "1"]:
            current.append(char)

            yield from generate()

            current.pop()

    yield from generate()


cases = int(input())
for _ in range(cases):
    length, numberOfTrues = map(int, input().split())

    for bitStr in allValidBitsStr(length, numberOfTrues):
        print(bitStr)
