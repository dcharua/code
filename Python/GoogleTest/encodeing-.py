def solution(S, K):
    # write your code in Python 3.6
    S = S.upper()
    S = S.replace('-', '')
    mod = len(S) % K
    if mod == 0:
        for i in range(1, len(S)-1, K):
            s = S[:i*K] + '-' + S[i*K:]
            S = s
            i = i* K
    else:
        temp1 = S[:mod] + '-'
        temp2 = S[mod:]
        for i in range(0, len(temp2)-1, K):
            if i == 0:
                s = temp2[:K] + '-' + temp2[K:]
            else:
                s = temp2[:i] + '-' + temp2[i:]
            S = s
            print(s)
            print(i)
        S = temp1 + S 
    if  S[-1] == '-':
        S = S[:-1] 
    print(S)
    return S

solution('2-4A0r7-4k', 2)