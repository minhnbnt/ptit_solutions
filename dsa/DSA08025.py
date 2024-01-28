from collections import deque


DX = [-2, -2, -1, -1, 2, 2, 1, 1]
DY = [-1, 1, -2, 2, -1, 1, -2, 2]


def isValid(pos):
    if not 0 <= pos[0] < 8:
        return False

    if not 0 <= pos[1] < 8:
        return False

    return True


def minimumMove(start, finish):
    if start == finish:
        return 0

    queue = deque()
    visited = dict()

    queue.append(start)
    visited[start] = 0

    while finish not in visited:
        current = queue[0]
        queue.popleft()

        numberOfMoves = visited[current] + 1
        for dx, dy in zip(DX, DY):
            pos = (current[0] + dy, current[1] + dx)

            if pos in visited:
                continue

            if not isValid(pos):
                continue

            visited[pos] = numberOfMoves
            queue.append(pos)

    return visited[finish]


def posParser(pos):
    row = int(pos[1]) - 1
    column = ord(pos[0]) - ord("a")

    return (row, column)


cases = int(input())
for _ in range(cases):
    start, finish = map(posParser, input().split())
    print(minimumMove(start, finish))
