from __future__ import annotations

from typing import Iterator, Optional


class TreeNode:
    value: int
    left: Optional[TreeNode]
    right: Optional[TreeNode]

    def __init__(self, value: int):
        self.left = self.right = None
        self.value = value

    def insertNode(self, value: int, key=lambda x: x):
        if key(value) < key(self.value):
            if self.left is None:
                self.left = TreeNode(value)
            else:
                self.left.insertNode(value, key)

        else:
            if self.right is None:
                self.right = TreeNode(value)
            else:
                self.right.insertNode(value, key)

    def postOrderTransverse(self) -> Iterator[int]:
        if self.left is not None:
            yield from self.left.postOrderTransverse()

        if self.right is not None:
            yield from self.right.postOrderTransverse()

        yield self.value


cases = int(input())
for _ in range(cases):
    size = int(input())

    inorder = list(map(int, input().split()))
    levelOrder = [int(token) for token in input().split()]

    indexMap = {value: i for i, value in enumerate(inorder)}

    root = TreeNode(levelOrder[0])

    for value in levelOrder[1::]:
        root.insertNode(value, key=lambda x: indexMap[x])

    print(*root.postOrderTransverse())
