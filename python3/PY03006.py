from collections import Counter
from typing import Tuple
import re


def comparator(entry: Tuple[str, int]):
    word, count = entry
    return (-count, word)


wordCounter = Counter()

lines = int(input())
for _ in range(lines):
    line = input().lower()
    wordCounter.update(m.group(0) for m in re.finditer(r"[a-z]+", line))

entries = wordCounter.items()
for word, count in sorted(entries, key=comparator):
    print(f"{word} {count}")
