from functools import cmp_to_key

class Genre:
    def __init__(self, id, name):
        self.id = "TL" + str(id).zfill(3)
        self.name = name
    def getId(self):
        return self.id
    def getName(self):
        return self.name
    
    def __str__(self) -> str:
        return f"{self.id} {self.name}"

class Movie:
    name_Movie = ""
    Date, Month, Year = "", "", ""
    def __init__(self, id, Genre, releaseDate, type_Movie, episode_Count, dsGenre):
        self.id = "P" + str(id).zfill(3)
        self.Genre = Genre
        self.releaseDate = releaseDate
        self.Date = self.releaseDate[0:2]
        self.Month = self.releaseDate[3:5]
        self.Year = self.releaseDate[6:10]
        self.type_Movie = type_Movie
        self.episode_Count = episode_Count
        for Genre in dsGenre:
            if Genre.getId() == self.Genre:
                self.name_Movie = Genre.getName()
    def __str__(self) -> str:
        return f"{self.id} {self.name_Movie} {self.releaseDate} {self.type_Movie} {self.episode_Count}"


if __name__ == "__main__" :
    n, m = [int(x) for x in input().split()]

    dsGenre = []
    for i in range(n):
        dsGenre.append(Genre(i + 1, input()))
    dsMovie = []
    for i in range(m):
        dsMovie.append(Movie(i + 1, input(), input(), input(), int(input()), dsGenre))

    dsMovie.sort(key=lambda x : (x.Year, x.Month, x.Date, x.type_Movie, -x.episode_Count))

    for x in dsMovie:
        print(x)

