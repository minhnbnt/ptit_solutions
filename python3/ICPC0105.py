import re
from typing import Iterator

isNumber = re.compile(r"\d+")


def extract_number(string: str) -> Iterator[int]:
    for subStr in isNumber.findall(string):
        yield int(subStr)


cases = int(input())
for _ in range(cases):
    inputString = input()

    numbersExtracted = extract_number(inputString)
    print(max(numbersExtracted))
