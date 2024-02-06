from collections import deque


def minimumValidNumber(target: int) -> str:
    queue = deque()
    queue.appendleft(("9", 9 % target))

    while True:
        currentNum, mod = queue[0]
        queue.popleft()

        if mod == 0:
            return currentNum

        queue.append((currentNum + "0", mod * 10 % target))
        queue.append((currentNum + "9", (mod * 10 + 9) % target))


cases = int(input())
for _ in range(cases):
    target = int(input())

    print(minimumValidNumber(target))
