class Bill:
    def __init__(self, id, name, old_Id, new_Id):
        self.id = id
        self.name = name
        self.dif = new_Id - old_Id
        self.total = 0
        if self.dif < 50:
            self.total = ((self.dif) * 100) * 1.02
        elif self.dif < 100:
            self.total = ((self.dif - 50) * 150 + 50 * 100) * 1.03
        else:
            self.total = ((self.dif - 100) * 200 + 50 * (100 + 150)) * 1.05
    def __str__(self) -> str:
        return f'{self.id} {self.name} {"{:.0f}".format(self.total)}'

dsBill = []
for i in range(int(input())):
    dsBill.append(Bill("KH" + format(i + 1, "02d"), input(), int(input()), int(input())))

dsBill.sort(key=lambda x : (-x.total))

for x in dsBill:
    print(x)
    