
str = input('Enter your input:')
state = 0
temp =""
for c in str:
    if (c.isdigit()):
        state = 1
        temp += c
    if (c =='+' or c == "-"):
        print( c)
        print(temp)
        temp = ""
        state = 0
    if (state == 1 and c == " "):
        print(temp)
        temp = ""
        state = 0
    #if(c.isdigit() == False and c != "+" or c != "-" or c!= " "):
    if(c.isdigit() == False and (c not in "+- ")):
        print("error character not accepted")
        break
print(temp)
