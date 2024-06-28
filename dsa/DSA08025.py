from collections import deque
from typing import Tuple

DX = [-2, -2, -1, -1, 2, 2, 1, 1]
DY = [-1, 1, -2, 2, -1, 1, -2, 2]

Position = Tuple[int, int]


def isValid(pos: Position):
    if not 0 <= pos[0] < 8:
        return False

    if not 0 <= pos[1] < 8:
        return False

    return True


def minimumMove(start: Position, finish: Position) -> int:
    queue = deque()
    visited = dict()

    queue.append(start)
    visited[start] = 0

    while finish not in visited:
        current = queue.popleft()
        x, y = current

        numberOfMoves = visited[current] + 1
        for dx, dy in zip(DX, DY):
            pos = (x + dx, y + dy)

            if pos in visited:
                continue

            if not isValid(pos):
                continue

            visited[pos] = numberOfMoves
            queue.append(pos)

    return visited[finish]


def posParser(pos: str) -> Position:
    row = int(pos[1]) - 1
    column = ord(pos[0]) - ord("a")

    return (row, column)


cases = int(input())
for _ in range(cases):
    start, finish = map(posParser, input().split())
    print(minimumMove(start, finish))
