from itertools import chain
import re, sys


def is_sentence(s: str) -> bool:
    return bool(re.match(r".*\w.*", s))


def correct_string(s: str) -> str:
    tokens = [token.lower() for token in s.split()]
    tokens[0] = tokens[0].title()
    return " ".join(tokens)


results = iter(())
for line in sys.stdin:
    newElement = (
        correct_string(token)  #
        for token in re.split("[.?!]", line)
        if is_sentence(token)
    )

    results = chain(results, newElement)

for sentence in results:
    print(sentence)
