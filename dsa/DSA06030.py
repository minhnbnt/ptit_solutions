from itertools import count

cases = int(input())

for _ in range(cases):
    size = int(input())
    array = list(map(int, input().split()))

    outputs = list()

    for step in count(1):
        isSorted = True

        for i in range(size - 1):
            if not array[i] > array[i + 1]:
                continue

            isSorted = False
            array[i], array[i + 1] = array[i + 1], array[i]

        if isSorted:
            break

        output = f"Buoc {step}: " + " ".join(map(str, array))
        outputs.append(output)

    for outputLine in reversed(outputs):
        print(outputLine)
