size = int(input())

array = list()
for token in input().split():
    array.append(int(token))

stepNumber = 0
steps = list()

for targetIndex in range(size - 1):
    minIndex = targetIndex

    for j in range(targetIndex, size):
        if array[j] < array[minIndex]:
            minIndex = j

    array[targetIndex], array[minIndex] = array[minIndex], array[targetIndex]

    stepNumber += 1

    outputLine = f"Buoc {stepNumber}: " + " ".join(map(str, array))
    steps.append(outputLine)

for outputLine in reversed(steps):
    print(outputLine)
