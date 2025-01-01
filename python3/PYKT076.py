from dataclasses import dataclass
from datetime import datetime


@dataclass
class Movie:
    id: str
    tag: str
    name: str
    on_air: datetime
    episodes: int

    def __str__(self) -> str:
        return (
            f"{self.id} {self.tag} "
            f"{self.on_air:%d/%m/%Y} "
            f"{self.name} {self.episodes}"
        )


tag_size, movie_size = (int(token) for token in input().split())

tags = {f"TL{i + 1:03}": input() for i in range(tag_size)}

movies = (
    Movie(
        id=f"P{i + 1:03}",
        tag=tags[input()],
        on_air=datetime.strptime(input(), "%d/%m/%Y"),
        name=input(),
        episodes=int(input()),
    )
    for i in range(movie_size)
)

for movie in sorted(movies, key=lambda m: (m.on_air, m.name, -m.episodes)):
    print(movie)
