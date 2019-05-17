
def solution(A):
    counter = 0
    maxsum = -99999999999999999999999999999
    maxlevel = 0
    start = 0
    for i in range(0, len(A), 2**counter):
        suma = 0
        i =2**counter
        for j in range(0, 2**i):
            index = (j+2**i) -1
            if index < len(A):
                suma =+ A[index]
        if suma > maxsum:
            maxsum = suma
            level = i + 1
        counter+=1

    return 



