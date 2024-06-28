from typing import Iterator


def allLaugh(length: int) -> Iterator[str]:
    current = []

    def generate() -> Iterator[str]:
        if len(current) == length:
            yield "".join(current)
            return

        for char in ["A", "H"]:
            current.append(char)

            yield from generate()

            current.pop()

    yield from generate()


def isValidLaugh(laugh: str) -> bool:
    for i in range(len(laugh) - 1):
        if laugh[i] == laugh[i + 1] == "H":
            return False

    return laugh[0] == "H" and laugh[-1] == "A"


cases = int(input())

for _ in range(cases):
    length = int(input())

    validLaughs = (
        laugh  #
        for laugh in allLaugh(length)
        if isValidLaugh(laugh)
    )

    print(*validLaughs)
