

class Exam_Shift:

	def __init__(self, id, Exam_date, Exam_hour, Room):
		self.__id = "C" + str(id).zfill(3)
		self.__Exam_date = Exam_date
		self.__Exam_hour = Exam_hour
		self.__Room = Room

	def getId(self):
		return self.__id

	def getExamDate(self):
		return self.__Exam_date

	def getExamHour(self):
		return self.__Exam_hour

	def __str__(self):
		return f'{self.__id} {self.__Exam_date} {self.__Exam_hour} {self.__Room}'


with open("CATHI.txt", 'r') as obj:
    n = int(obj.readline().strip())
    arr = []
    for i in range(n):
        X = Exam_Shift(i + 1, obj.readline().strip(), obj.readline().strip(),
        obj.readline().strip())
        
        arr.append(X)
    arr.sort(key = lambda x : (x.getExamDate(), x.getExamHour(), x.getId()))

    for x in arr:
        print(x)    