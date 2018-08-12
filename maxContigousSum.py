def getMaximumSum(numbers):
    sumHere,sumSoFar=0,0
    for number in numbers:
        sumHere=max(0,sumHere+number)
        sumSoFar=max(sumHere,sumSoFar)
    return sumSoFar
def getEndMaximaPoints(numbers):
    sumHere,sumSoFar,count=0,0,0
    start,end=0,0
    for number in numbers:
        sumHere=sumHere+number
        if sumHere<0:
            sumHere,elements=0,0
            start+=1
        if sumSoFar<sumHere:
            (sumSoFar,end)=(sumHere,count)
        count+=1    
    return (start,end)    
numbers=[-2,-3,4,-1,-2,1,5,-3,4]
print(getMaximumSum(numbers))
print(getEndMaximaPoints(numbers))
