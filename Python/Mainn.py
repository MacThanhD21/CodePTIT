
# class Employee:
#     def __init__(self, id, name, salary, hour_worked, department):
#         self.id = id
#         self.name = name
#         self.salary = salary
#         self.hour_worked = hour_worked
#         self.department = department

#     def setDepartment(self, department):
#         self.department = department

#     def getSalary(self):
#         if self.hour_worked < 50:
#             return self.salary
#         else:
#             overTime = self.hour_worked - 50
#             OvertimeAmount = (overTime * (self.salary) / 50)
#             return self.salary + OvertimeAmount

#     def __str__(self) -> str:
#         return f"{self.id} {self.name} {self.getSalary()} {self.department}"
# if __name__ == "__main__":
#     x = Employee("001", "ADAMS", 50000, 20, "ACCOUNTING")
#     x.setDepartment("Ke Toan")
#     y = Employee("002", "Eva", 30000, 100, "IT")
#     z = Employee("003", "John",11415, 60, "Marketing")
#     print(x)
#     print(y)
#     print(z)


class BankAccount:
    def __init__(self, account_number, balance, date_of_opening, customer_name):
        self.account_number = account_number
        self.balance = balance
        self.date_of_opening = date_of_opening
        self.customer_name = customer_name

    def deposit(self, amount):
        self.balance += amount

    def withdraw(self, amount):
        if amount <= self.balance:
            self.balance -= amount
        else:
            print("Tai khoan khong du de tru")

    def check_balance(self):
        return self.balance
