from dataclasses import dataclass


@dataclass
class Team(object):
    name: str
    school_name: str

    def __str__(self) -> str:
        return f"{self.name} {self.school_name}"


@dataclass
class Student:
    id: str
    name: str
    team: Team

    def __str__(self) -> str:
        return f"{self.id} {self.name} {self.team}"


size = int(input())

teams = {
    f"Team{i + 1:02}": Team(
        name=input(),
        school_name=input(),
    )
    for i in range(size)
}

size = int(input())

students = (
    Student(
        id=f"C{i + 1:03}",
        name=input(),
        team=teams[input()],
    )
    for i in range(size)
)

for student in sorted(students, key=lambda s: s.name):
    print(student)

