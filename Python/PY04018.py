class GiangVien:
    Type_Sub, Status = '', ''
    Total_Score = 0.0
    def __init__(self, id, name, code_Exam, sc_1, sc_2):
        self.id = "GV" + "{:02d}".format(id)
        self.name = name
        self.code_Exam = code_Exam
        if self.code_Exam[0] == 'A':
            self.Type_Sub = 'TOAN'
        elif self.code_Exam[0] == 'B':
            self.Type_Sub = 'LY'
        else:
            self.Type_Sub = 'HOA'
        self.Total_Score = sc_1 * 2 + sc_2
        if self.code_Exam[1] == '1':
            self.Total_Score += 2.0
        elif self.code_Exam[1] == '2':
            self.Total_Score += 1.5
        elif self.code_Exam[1] == '3':
            self.Total_Score += 1.0
        else:
            self.Total_Score += 0.0
        if self.Total_Score < 18:
            self.Status = 'LOAI'
        else:
            self.Status = 'TRUNG TUYEN'
    def __str__(self):
        return f'{self.id} {self.name} {self.Type_Sub} {"{:.1f}".format(self.Total_Score)} {self.Status}'

dsGV = []
for i in range(int(input())):
    dsGV.append(GiangVien(i + 1, input(), input(), float(input()), float(input())))
dsGV.sort(key=lambda x: -x.Total_Score)

for x in dsGV:
    print(x)
