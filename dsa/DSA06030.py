cases = int(input())

for _ in range(cases):
    size = int(input())
    array = list(map(int, input().split()))

    stepNumber, steps = 0, list()

    while True:
        isSorted = True

        for i in range(size - 1):
            if not array[i] > array[i + 1]:
                continue

            isSorted = False
            array[i], array[i + 1] = array[i + 1], array[i]

        if isSorted:
            break

        stepNumber += 1
        output = f"Buoc {stepNumber}: " + " ".join(map(str, array))
        steps.append(output)

    for outputLine in reversed(steps):
        print(outputLine)
