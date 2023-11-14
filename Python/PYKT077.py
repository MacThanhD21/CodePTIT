
class Subject:
    def __init__ (self, id_Sub, name_Sub):
        self.id_Sub = id_Sub
        self.name_Sub = name_Sub
    def getId (self):
        return self.id_Sub
    def getName (self):
        return self.name_Sub

class Exam_Schedule:
    Subject = None
    day, month, year = None, None, None
    h_Ex, m_Ex = None, None
    
    def __init__(self, id_Ex, id_Sub, date_Ex, hour_Ex, id_Gr, dsSub):
        self.id_Ex = "T" + format(id_Ex, "03d")
        self.id_Sub = id_Sub
        self.date_Ex = date_Ex
        self.day = int(date_Ex[0:2])
        self.month = int(date_Ex[3:5])
        self.year = int(date_Ex[6])
        self.hour_Ex = hour_Ex
        self.h_Ex = int(hour_Ex[0:2])
        self.m_Ex = int(hour_Ex[3:5])
        self.id_Gr = id_Gr
        
        for x in dsSub:
            if x.id_Sub == id_Sub:
                self.Subject = x
                break
    def __str__(self):
        return f'{self.id_Ex} {self.id_Sub} {self.Subject.getName()} {self.date_Ex} {self.hour_Ex} {self.id_Gr}'
    
n, m = [int(x) for x in input().split()]
dsSub = []
for i in range(n):
    dsSub.append(Subject(input(), input()))

dsExam = []
for i in range(m):
    s = input().split(" ")
    dsExam.append(Exam_Schedule(i + 1, s[0], s[1], s[2], s[3], dsSub))

dsExam.sort(key = lambda x: (x.year, x.month, x.day, x.h_Ex, x.m_Ex, x.Subject.getId()))

for x in dsExam:
    print(x)
