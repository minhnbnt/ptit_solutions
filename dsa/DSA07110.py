VALID_PAIRS = {"(": ")", "[": "]", "{": "}"}


def isValidPairString(string: str) -> bool:
    stack = []

    for char in string:
        if char in VALID_PAIRS:
            stack.append(char)
            continue

        if len(stack) == 0:
            return False

        head = stack.pop()
        if char != VALID_PAIRS.get(head):
            return False

    return len(stack) == 0


cases = int(input())
for _ in range(cases):
    line = input()
    print("YES" if isValidPairString(line) else "NO")
