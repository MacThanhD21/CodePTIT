
import math
class Student:
    def __init__(self, id, name, d1, d2, d3):
        self.id = "SV" + format(id, "02d")
        self.name = name
        self.name = self.standardize(name)
        self.d1 = d1
        self.d2 = d2
        self.d3 = d3
    def getId(self):
        return self.id
    def standardize(self, name):
        return " ".join(self.name.title().split())
    def getAvgScore(self):
        return format(math.ceil((self.d1 * 3 + self.d2 * 3 + self.d3 * 2) / 8 * 100) / 100, ".2f")
    def __str__(self):
        return f'{self.id} {(self.name)} {self.getAvgScore()}'
    
n = int(input())
dsStudent = []

rank = {}
for i in range(n):
    x = Student(i + 1, input().strip().title(), float(input()), float(input()), float(input()))
    dsStudent.append(x)

dsStudent.sort(key= lambda x : -float(x.getAvgScore()))

# rank for sv01 = 1, after compare current sv with previous sv, if equal, rank is the same, else rank is the previous rank + 1

rank[dsStudent[0].getId()] = 1 

for i in range(1, len(dsStudent)):
    if dsStudent[i].getAvgScore() == dsStudent[i - 1].getAvgScore():
        rank[dsStudent[i].getId()] = i
    else:
        rank[dsStudent[i].getId()] = i + 1
        
for x in dsStudent :
    print(x, rank[x.getId()])