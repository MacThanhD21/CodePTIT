class Student:
    
    def __init__(self, id, name, Score, Nation, Area):
        self.id = "TS" + format(id, "02d")
        self.name = name
        self.Score = Score
        self.Nation = Nation
        self.Area = Area
    
    def getScore(self):
        if self.Nation == 'Kinh':
            if self.Area == '1':
                return self.Score + 1.5
            elif self.Area == '2':
                return self.Score + 1.0
            else:
                return self.Score + 0.0
        else:
            if self.Area == '1':
                return self.Score + 3.0
            elif self.Area == '2':
                return self.Score + 2.5
            else:
                return self.Score + 1.5
    def getStatus(self):
        if self.getScore() >= 20.5:
            return 'Do'
        else:
            return 'Truot'
    def __str__(self) -> str:
        return f'{self.id} {self.name} {format(self.getScore(), ".1f")} {self.getStatus()}'
n = int(input())

dsStudents = []

for i in range(n):
    dsStudents.append(Student(i + 1, " ".join(input().title().split()) , float(input()), input(), input()))
    
dsStudents.sort(key = lambda x : (-x.getScore(), x.id))
for x in dsStudents:
    print(x)