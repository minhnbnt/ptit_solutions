from itertools import islice
from typing import Iterable, Iterator, Tuple


def batched(iterable: Iterable, n: int) -> Iterator[Tuple]:
    iterator = iter(iterable)

    while batch := tuple(islice(iterator, n)):
        yield batch


def distinct(iter: Iterable) -> Iterable:
    visited = set()
    for element in iter:
        if element in visited:
            continue

        visited.add(element)
        yield element


string = input()
if len(string) % 2 != 0:
    string = string[:-1]

slices = (slice for slice in batched(string, n=2))
numbers = distinct(int("".join(slice)) for slice in slices)

print(*numbers)
