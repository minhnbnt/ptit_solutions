from collections import deque


cases = int(input())
for _ in range(cases):
    size, shiftTimes = map(int, input().split())
    array = deque(map(int, input().split()))

    for _ in range(shiftTimes):
        temp = array.popleft()
        array.append(temp)

    print(*array)
