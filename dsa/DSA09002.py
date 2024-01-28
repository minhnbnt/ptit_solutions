edges = set()
points = int(input())
for point in range(1, points + 1):
    adjs = map(int, input().split())

    for adj in adjs:
        if (adj, point) in edges:
            continue

        edges.add((point, adj))

for edge in sorted(edges):
    print(*edge)
