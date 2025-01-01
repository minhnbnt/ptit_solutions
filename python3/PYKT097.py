import sys

END_OF_SENTENCES = frozenset({".", "!", "?"})

for line in sys.stdin:
    tokens = line.lower().split()
    tokens[0] = tokens[0].title()

    if tokens[-1] in END_OF_SENTENCES:
        tokens[-2] += tokens[-1]
        del tokens[-1]

    elif tokens[-1][-1] not in END_OF_SENTENCES:
        tokens[-1] += "."

    print(" ".join(tokens))
