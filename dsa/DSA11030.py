from collections import defaultdict, deque


def BFS_Find(graph, start, end) -> int:
    queue = deque()
    visited = dict()

    queue.append(start)
    visited[start] = 0

    while end not in visited:
        current = queue[0]
        distance = visited[current]

        queue.popleft()

        for to in graph[current]:
            if to in visited:
                continue

            queue.append(to)
            visited[to] = distance + 1

    return visited[end]


cases = int(input())
for _ in range(cases):
    graph = defaultdict(lambda: set())

    numberOfEdge = int(input())
    for _ in range(numberOfEdge - 1):
        a, b = map(int, input().split())

        graph[a].add(b)
        graph[b].add(a)

    attempt = int(input())
    for _ in range(attempt):
        start, end = map(int, input().split())
        print(BFS_Find(graph, start, end))
