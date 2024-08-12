from dataclasses import dataclass
from datetime import datetime
from typing import List
from itertools import chain

DISTANCE = 120
START_TIME = datetime.strptime("6:00", "%H:%M")


@dataclass
class Rider:
    fullName: str
    club: str
    speed: float

    def get_id(self) -> str:
        clubChars = (token[0] for token in self.club.split())
        nameChars = (token[0] for token in self.fullName.split())

        return "".join(chain(clubChars, nameChars))


def calculate_speed(start: datetime, finish: datetime, distance: int) -> float:
    timeElapsed = finish - start
    hoursElapsed = timeElapsed.total_seconds() / 3600

    return distance / hoursElapsed


riders: List[Rider] = []

size = int(input())
for _ in range(size):
    fullName, club = input(), input()

    finishTime = datetime.strptime(input(), "%H:%M")
    speed = calculate_speed(START_TIME, finishTime, DISTANCE)

    riders.append(Rider(fullName, club, speed))

for rider in sorted(riders, key=lambda r: r.speed, reverse=True):
    speedDisplay = f"{round(rider.speed)} Km/h"
    print(rider.get_id(), rider.fullName, rider.club, speedDisplay)
