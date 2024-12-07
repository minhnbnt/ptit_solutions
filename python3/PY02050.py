cases = int(input())

for _ in range(cases):
    size = int(input())

    array = [int(token) for token in input().split()]

    stack = []
    for i, elem in enumerate(array):
        index = i

        while stack:
            j, elem2 = stack[-1]

            if elem2 <= elem:
                stack.pop()
                index = j

            else:
                break

        stack.append((index, elem))
        print(i - index + 1, end=" ")

    print()
