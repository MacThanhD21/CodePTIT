
class Subject:
    def __init__(self, id, name, Type_Exam):
        self.id = id
        self.name = name
        self.Type_Exam = Type_Exam

class Shift_Exam:
    def __init__(self, id, date_Exam, hour_Exam, room_Exam):
        self.id = 'C' + format(id, '03d')
        self.date_Exam = date_Exam
        self.hour_Exam = hour_Exam
        self.room_Exam = room_Exam

class Schedule_Exam:
    Subject = None
    Shift_Exam = None
    def __init__(self, id_Shift_Exam, id_Subject, id_Group, quantity, dsSubject, dsShift_Exam):
        self.id_Shift_Exam = id_Shift_Exam
        self.id_Subject = id_Subject
        self.id_Group = id_Group
        self.quantity = quantity
        for x in dsSubject:
            if x.id == id_Subject:
                self.Subject = x
                break
        for x in dsShift_Exam:
            if x.id == id_Shift_Exam:
                self.Shift_Exam = x
                break
    def __str__(self):
        return f'{self.Shift_Exam.date_Exam} {self.Shift_Exam.hour_Exam} {self.Shift_Exam.room_Exam} ' \
               f'{self.Subject.name} {self.id_Group} {self.quantity}'

f = open('MONTHI.in', 'r')

dsSubject = []
dsShift_Exam = []
dsSchedule_Exam = []

n = int(f.readline().strip())
for i in range(n):
    id = f.readline().strip()
    name = f.readline().strip()
    Type_Exam = f.readline().strip()
    dsSubject.append(Subject(id, name, Type_Exam))

f = open('CATHI.in', 'r')
m = f.readline().strip()
for i in range(int(m)):
    date_Exam = f.readline().strip()
    hour_Exam = f.readline().strip()
    room_Exam = f.readline().strip()
    dsShift_Exam.append(Shift_Exam(i + 1, date_Exam, hour_Exam, room_Exam))

f = open('LICHTHI.in', 'r')
p = f.readline().strip()
for i in range(int(p)):
    s = f.readline().split()
    id_Shift_Exam = s[0].strip()
    id_Subject = s[1].strip()
    id_Group = s[2].strip()
    quantity = s[3].strip()
    dsSchedule_Exam.append(Schedule_Exam(id_Shift_Exam, id_Subject, id_Group, quantity, dsSubject, dsShift_Exam))

dsSchedule_Exam.sort(key=lambda x : (x.Shift_Exam.date_Exam, x.Shift_Exam.hour_Exam, x.Shift_Exam.id))

for x in dsSchedule_Exam:
    print(x)