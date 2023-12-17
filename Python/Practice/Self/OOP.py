class Subject:
    def __init__(self, id, name, stc, hthuc_LT, hthuc_TH) -> None:
        self.id = id
        self.name = name
        self.stc = stc
        self.hthuc_LT = hthuc_LT
        self.hthuc_TH = hthuc_TH
    def __str__(self) -> str:
        return f'{self.id} {self.name} {self.stc} {self.hthuc_LT} {self.hthuc_TH}'

file = open('MONHOC.in', 'r')

dsSub = []

for _ in range(int(file.readline())):
    dsSub.append(Subject(file.readline().strip(), file.readline().strip(), file.readline().strip(), file.readline().strip(), file.readline().strip()))

dsSub.sort(key=lambda x: x.id)
for x in dsSub:
    if x.hthuc_TH == 'Truc tuyen' or x.hthuc_TH.endswith('.ptit.edu.vn'):
        print(x)