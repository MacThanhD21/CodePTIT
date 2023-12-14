
class Genre:
    def __init__(self, id, name_Gen):
        self.id = "TL" + format(id, "03d")
        self.name_Gen = name_Gen

class Movie:
    def __init__(self, id_M, id_T, date, name_Phim, So_Tap, dsGenre):
        self.id_M = "P" + format(id_M, "03d")
        self.id_T = id_T
        self.date = date
        self.name_Phim = name_Phim
        self.So_Tap = int(So_Tap)
        for x in dsGenre:
            if x.id == self.id_T:
                self.name_Gen = x.name_Gen
                break
    def __str__(self):
        return f'{self.id_M} {self.name_Gen} {self.date} {self.name_Phim} {self.So_Tap}'
                
n, m = [int(x) for x in input().split()]
dsGenre = []
for i in range(n):
    dsGenre.append(Genre(i + 1, input()))

dsMovie = []
for i in range(m):
    dsMovie.append(Movie(i + 1, input(), input(), input(), input(), dsGenre))

dsMovie.sort(key=lambda x : (x.date[6:], x.date[3:5], x.date[0:2], x.name_Phim, -x.So_Tap))

for x in dsMovie:
    print(x)
    