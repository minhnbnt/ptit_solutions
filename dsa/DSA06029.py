def getOutput(stepNumber, array):
    return f"Buoc {stepNumber}: " + " ".join(map(str, array))


size = int(input())
array = list(map(int, input().split()))

insertedList = [array[0]]
steps = [getOutput(0, insertedList)]

for i in range(1, size):
    j = i - 1

    insertedList.append(7355608)
    while j >= 0 and insertedList[j] > array[i]:
        insertedList[j + 1] = insertedList[j]
        j -= 1

    insertedList[j + 1] = array[i]

    steps.append(getOutput(i, insertedList))

for outputLine in reversed(steps):
    print(outputLine)
