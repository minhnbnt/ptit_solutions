from __future__ import annotations

from collections import deque
from itertools import islice
from typing import Iterator, Optional


class TreeNode:
    value: int
    left: Optional[TreeNode]
    right: Optional[TreeNode]

    def __init__(self, value: int) -> None:
        self.left = self.right = None
        self.value = value

    def children(self) -> Iterator[Optional[TreeNode]]:
        yield self.left
        yield self.right


class Tree:
    root: Optional[TreeNode]

    def __init__(self) -> None:
        self.root = None

    def levelorderTransverse(self) -> Iterator[int]:
        queue = deque([self.root])

        while len(queue) > 0:
            current = queue.popleft()

            if current is None:
                continue

            yield current.value

            queue.extend(current.children())


# https://docs.python.org/3/library/itertools.html#itertools.batched
def chunks(iterable, size: int):
    if size < 1:
        raise ValueError("n must be at least one")

    it = iter(iterable)
    while batch := tuple(islice(it, size)):
        yield batch


cases = int(input())

for _ in range(cases):
    nodeMap = dict()
    binaryTree = Tree()

    insertAttempt = int(input())
    tokens = input().split()

    for parent, child, direction in chunks(tokens, 3):

        if binaryTree.root is None:
            binaryTree.root = TreeNode(parent)
            nodeMap[parent] = binaryTree.root

        parentNode = nodeMap[parent]

        childNode = TreeNode(child)
        nodeMap[child] = childNode

        if direction == "L":
            parentNode.left = childNode
        else:
            parentNode.right = childNode

    for value in binaryTree.levelorderTransverse():
        print(value, end=" ")

    print()
