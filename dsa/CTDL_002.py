def allValidSubarray(array, targetSum):
    validArray = []
    arrayLength = len(array)

    def solve(index=0, sum=0):
        if sum == targetSum:
            yield validArray

        if index == arrayLength:
            return

        for i in range(index, arrayLength):
            validArray.append(array[i])
            sum += array[i]

            yield from solve(i + 1, sum)

            validArray.pop()
            sum -= array[i]

    yield from solve()


_size, targetSum = (int(token) for token in input().split())
array = [int(token) for token in input().split()]

outputs = []
for validArray in allValidSubarray(array, targetSum):
    line = " ".join(str(element) for element in validArray)
    outputs.append(line)

for outputLine in reversed(outputs):
    print(outputLine)

print(len(outputs))
