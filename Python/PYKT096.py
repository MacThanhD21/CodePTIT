class Team:
    def __init__(self, id, name_Team, name_School):
        self.id = "Team" + format(id, "02d")
        self.name_Team = name_Team
        self.name_School = name_School


class Student:
    Team = None
    def __init__(self, id, name_Stu, team_id, dsTeam):
        self.id = "C" + format(id, "03d")
        self.name_Stu = name_Stu
        self.team_id = team_id
        for x in dsTeam : 
            if x.id == team_id:
                self.Team = x
                break
    def __str__(self):
        return f'{self.id} {self.name_Stu} {self.Team.name_Team} {self.Team.name_School}'
    
    
n = int(input())

dsTeam = []
for i in range(n):
    dsTeam.append(Team(i + 1, input(), input()))

m = int(input())
dsStudent = []
for i in range(m):
    dsStudent.append(Student(i + 1, input(), input(), dsTeam))

dsStudent.sort(key = lambda x : x.name_Stu)

for x in dsStudent:
    print(x)