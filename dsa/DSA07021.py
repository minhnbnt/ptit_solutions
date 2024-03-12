def longestPairString(string: str) -> int:
    stack = [-1]
    result = 0

    for i, char in enumerate(string):
        if char == "(":
            stack.append(i)
            continue

        stack.pop()

        if len(stack) == 0:
            stack.append(i)
            continue

        result = max(result, i - stack[-1])

    return result


cases = int(input())
for _ in range(cases):
    line = input()
    print(longestPairString(line))
