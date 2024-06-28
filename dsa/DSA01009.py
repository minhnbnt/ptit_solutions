from typing import Iterator


def allABStrings(length: int) -> Iterator[str]:
    chars = list()

    def generator():
        if len(chars) == length:
            yield "".join(chars)
            return

        for char in ("A", "B"):
            chars.append(char)
            yield from generator()

            chars.pop()

    return generator()


def isValid(s: str, aLength: int) -> bool:
    if "A" * (aLength + 1) in s:
        return False

    return "A" * aLength in s


length, aLength = map(int, input().split())

result = [
    string  #
    for string in allABStrings(length)
    if isValid(string, aLength)
]

print(len(result), *result, sep="\n", end="\n")
