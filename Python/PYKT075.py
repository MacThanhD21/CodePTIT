# Đọc dữ liệu từ tập tin SOTAY.txt
with open('SOTAY.txt', 'r') as f:
    lines = f.readlines()

contacts = {}  # Tạo một từ điển để lưu thông tin liên lạc

current_date = None  # Biến để lưu trữ ngày hiện tại
current_contact = None  # Biến để lưu trữ thông tin liên lạc hiện tại

for line in lines:
    line = line.strip()
    if line.startswith("Ngay "):
        # Nếu dòng bắt đầu bằng "Ngay ", đây là ngày mới
        current_date = line
    elif current_date and line:
        # Nếu đã có ngày và dòng không trống
        if current_contact is None:
            # Nếu chưa có thông tin liên lạc hiện tại, đây là họ tên
            current_contact = line
        else:
            # Nếu đã có thông tin liên lạc hiện tại, đây là số điện thoại
            contacts[current_contact] = (line, current_date) # line is telephone_number, cur_date is ngay hien tai
            current_contact = None

# Ghi dữ liệu vào tập tin DIENTHOAI.txt
with open('DIENTHOAI.txt', 'w') as f:
    for contact, (phone, date) in sorted(contacts.items(), key=lambda x: x[0]):
        f.write(f"{contact}: {phone} {date}\n")
