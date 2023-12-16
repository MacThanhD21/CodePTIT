class Staff:
    def __init__(self, id, name, lt_Score, th_Score):
        self.id = id
        self.name = name
        self.Avg_Score = (lt_Score + th_Score) / 2
        if self.Avg_Score >= 9.5:
            self.Status = 'XUAT SAC'
        elif self.Avg_Score >= 8:
            self.Status = 'DAT'
        elif self.Avg_Score >= 5:
            self.Status = "CAN NHAC"
        else:
            self.Status = 'TRUOT'
    def __str__(self):
        return f'{self.id} {self.name} {format(self.Avg_Score, ".2f")} {self.Status}'

dsStaff = []
for i in range(int(input())):
    id = "TS0" + str(i + 1)
    name = input()
    lt_Score = float(input())
    th_Score = float(input())
    if lt_Score > 10: lt_Score /= 10
    if th_Score > 10: th_Score /= 10
    dsStaff.append(Staff(id, name, lt_Score, th_Score))
    
dsStaff.sort(key=lambda x: (-x.Avg_Score))
for x in dsStaff:
    print(x)