class Student:
    def __init__(self, code, name, team_code):
        self.code = "C" + format(code, "%03d")
        self.name = name
        self.team_code = team_code


class Team:
    def __init__(self, team_code, team_name, school_name):
        self.team_code = "Team" + format(team_code, "%02d")
        self.team_name = team_name
        self.school_name = school_name
        self.students = []

    def add_student(self, student):
        self.students.append(student)

def sort_by_name(student):
    return student.name

def main():
    num_teams = int(input())
    teams = []

    for i in range(num_teams):
        team_name = input()
        school_name = input()
        team = Team(i + 1, team_name, school_name)
        teams.append(team)

    num_students = int(input())

    for i in range(num_students):
        student_name = input()
        student_team_code = input()
        student = Student(i + 1, student_name, student_team_code)

        for team in teams:
            if team.team_code == student_team_code:
                team.add_student(student)
                break

    all_students = []
    for team in teams:
        all_students.extend(team.students)

    all_students.sort(key=sort_by_name, reverse=True)

    for student in all_students:
        for team in teams:
            if team.team_code == student.team_code:
                print(f'{student.code} {student.name} {team.team_name} {team.school_name}')


if __name__ == '__main__':
    main()
