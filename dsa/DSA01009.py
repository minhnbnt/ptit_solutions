from typing import Callable, Iterator


def allValidABStrings(length: int, validFunc: Callable[[str], bool]) -> Iterator[str]:
    chars = list()

    def generator():
        if len(chars) == length:
            result = "".join(chars)

            if validFunc(result):
                yield result

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


size, aLength = map(int, input().split())
result = list(allValidABStrings(size, lambda s: isValid(s, aLength)))

print(len(result), *result, sep="\n", end="\n")
