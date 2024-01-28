from collections import deque


def numberOfOperator(number, target):
    queue = deque()
    generated = dict()

    queue.append(number)
    generated[number] = 0

    while target not in generated:
        current = queue[0]
        queue.popleft()

        operatorUsed = generated[current] + 1
        num1, num2 = current * 2, current - 1

        if num1 not in generated and current < target:
            generated[num1] = operatorUsed
            queue.append(num1)

        if num2 not in generated and current > 1:
            generated[num2] = operatorUsed
            queue.append(num2)

    return generated[target]


cases = int(input())
for _ in range(cases):
    number, target = map(int, input().split())
    print(numberOfOperator(number, target))
