cases = int(input())

for _ in range(cases):
    size = int(input())

    steps = list()
    array = list(map(int, input().split()))

    for i in range(size - 1):
        for j in range(i + 1, size):
            if not array[i] > array[j]:
                continue

            array[i], array[j] = array[j], array[i]

        outputLine = f"Buoc {i + 1}: " + " ".join(map(str, array))
        steps.append(outputLine)

    for outputLine in reversed(steps):
        print(outputLine)
