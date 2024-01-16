size = int(input())

array = [int(token) for token in input().split()]

for targetIndex in range(size - 1):
    minIndex = targetIndex

    for j in range(targetIndex, size):
        if array[j] < array[targetIndex]:
            targetIndex = j

    array[minIndex], array[targetIndex] = array[targetIndex], array[minIndex]

    print(f"Buoc {targetIndex + 1}:", *array)
