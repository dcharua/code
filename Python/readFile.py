# 

"""
"x" - Create - will create a file, returns an error if the file exist just create the file

"a" - Append - will create a file if the specified file does not exist appends

"w" - Write - will create a file if the specified file does not exist overwrites

"""

def readAll():
    file = open('test.txt', 'r')
    print(file.read())
    file.close()

def readLinebyLine():
    #read line by line in file

    #one line code to pass to a list
    #lines = [line.rstrip('\n') for line in open(filename)]
    
    file = open('test.txt', 'r')
    try:
        for line in file:
            print(line.rstrip())
            pass # process line, includes newline
    finally:
        file.close()

def write():
    f = open("new.txt", "w")
    f.write("Woops! I have deleted the content!")
    f.close()