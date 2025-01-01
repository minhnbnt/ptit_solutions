from dataclasses import dataclass
from datetime import datetime
from typing import Iterable


@dataclass
class Student:
    name: str
    birth: datetime
    scores: Iterable[float]

    def __str__(self) -> str:
        return f"{self.name} {self.birth:%d/%m/%Y} {sum(self.scores):.1f}"


student = Student(
    name=input(),
    birth=datetime.strptime(input(), "%d/%m/%Y"),
    scores=(float(input()) for _ in range(3)),
)

print(student)

