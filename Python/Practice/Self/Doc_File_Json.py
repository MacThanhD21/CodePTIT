import json


f = open('data.json', 'r')
# print data
data = f.read()
print(data)

# In thông tin cụ thể
data = json.loads(data)
print(f"Name: {data['name']}")
print(f"Age: {data['age']}")
print(f"City: {data['city']}")
print(f"Grades: {data['grades']}")
print(f"Is Student: {data['is_student']}")