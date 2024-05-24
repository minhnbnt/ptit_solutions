from __future__ import annotations

from collections import deque
from dataclasses import dataclass
from typing import Deque, List


@dataclass
class TreeNode:
    value: int
    connected: List[TreeNode]

    def connect(self, other: TreeNode) -> None:
        self.connected.append(other)
        other.connected.append(self)

    def distanceTo(self, target: int) -> int:
        queue: Deque[TreeNode] = deque([self])
        visited = {self.value: 0}

        while target not in visited:
            current = queue.popleft()
            distance = visited[current.value]

            for node in current.connected:
                if node.value in visited:
                    continue

                queue.append(node)
                visited[node.value] = distance + 1

        return visited[target]


cases = int(input())
for _ in range(cases):
    nodeDict = dict()
    numberOfNode = int(input())

    while len(nodeDict) < numberOfNode:
        a, b = map(int, input().split())

        if a not in nodeDict:
            nodeDict[a] = TreeNode(a, [])

        if b not in nodeDict:
            nodeDict[b] = TreeNode(b, [])

        nodeDict[a].connect(nodeDict[b])

    queries = int(input())
    for _ in range(queries):
        a, b = map(int, input().split())
        print(nodeDict[a].distanceTo(b))
