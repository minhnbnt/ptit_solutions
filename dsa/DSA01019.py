from typing import Iterator


def allValidLaugh(length: int) -> Iterator[str]:

    def isValidLaugh(laugh) -> bool:

        for i in range(len(laugh) - 1):
            if laugh[i] == laugh[i + 1] == "H":
                return False

        return laugh[0] == "H" and laugh[-1] == "A"

    current = []

    def generate() -> Iterator[str]:

        if len(current) == length:
            laugh = "".join(current)

            if isValidLaugh(laugh):
                yield laugh

            return

        for char in ["A", "H"]:

            current.append(char)

            yield from generate()

            current.pop()

    yield from generate()


cases = int(input())
for _ in range(cases):
    length = int(input())

    for laugh in allValidLaugh(length):
        print(laugh)
