
class Subject:
    def __init__(self, id, name, Type_Exam):
        self.id = id
        self.name = name
        self.Type_Exam = Type_Exam

class Shift_Exam:
    def __init__(self, id, date_Exam, hour_Exam, room_Exam):
        self.id = 'C' + format(id, '02d')
        self.date_Exam = date_Exam
        self.hour_Exam = hour_Exam
        self.room_Exam = room_Exam

class Schedule_Exam:
    def __init__(self, id_Shift_Exam, id_Subject, id_Group, quantity, dsSubject, dsShift_Exam):
        self.id_Shift_Exam = id_Shift_Exam
        self.id_Subject = id_Subject
