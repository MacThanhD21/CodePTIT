
def ngat_Cau(c):
	return c == '.' or c == '?' or c == '!'

nextL = True

while True:
    try:
        s = input().lower()

        if not s:
            continue
        s = s.replace("?", "? ")
        s = s.replace(".", ". ")
        s = s.replace("!", "! ")

        tmp = s.split()

        for i in range(len(tmp)):
            s = tmp[i]
            if nextL:
                nextL = False
                s = s[0].upper() + s[1:]
            print(s, end = "")

            if ngat_Cau(s[len(s) - 1]):
                print()
                nextL = True
            elif i == len(tmp) - 1:
                print(".")
                nextL = True
            elif tmp[i + 1] != '.' and tmp[i + 1] != '!' and tmp[i + 1] != '?':
                print(" ", end = "")
            
    except EOFError:
        break
