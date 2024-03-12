VALID_PAIRS = {"(": ")", "[": "]", "{": "}"}


def isValidPairString(string: str) -> bool:
    stack = []

    for char in string:
        if char in ["(", "[", "{"]:
            stack.append(char)
            continue

        if len(stack) == 0:
            return False

        if char != VALID_PAIRS.get(stack[-1]):
            return False

        stack.pop()

    return len(stack) == 0


cases = int(input())
for _ in range(cases):
    line = input()
    print("YES" if isValidPairString(line) else "NO")
