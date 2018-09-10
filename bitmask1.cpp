def setbit(b,i):
    return b | (1<<i)
def unsetbit(b,i):
    return b & ~(1<<i)
def checkbit(b,i):
    return (b & (1<<i))!=0
def checkSum(num,thr):
    si=len(num)
    if si==0:
        return 0
    cnt=0
    for i in range (2**si):
        setsum=0
        for k in range (si):
            setsum+=num[k] if checkbit(i,k) else 0
        cnt+=1 if setsum>=thr else 0
    return cnt
print checkSum([1,2,3],4)
