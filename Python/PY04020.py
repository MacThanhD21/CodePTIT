class Good:
    Total_Pr = 0
    def __init__(self, id, name, quantity, single_Pr, Discount):
        self.id = id
        self.name = name
        self.quantity = quantity
        self.single_Pr = single_Pr
        self.Discount = Discount
        self.Total_Pr = self.quantity * self.single_Pr
        self.Total_Pr -= self.Discount
    def __str__(self):
        return f'{self.id} {self.name} {self.quantity} {self.single_Pr} {self.Discount} {(self.Total_Pr)}'
dsGood = []
n = int(input())
for i in range(n):
    dsGood.append(Good(input(), input(), int(input()), int(input()), int(input())))
dsGood.sort(key=lambda x: (-x.Total_Pr))
for x in dsGood:
    print(x)