def removeElem(num: list, val: int) -> int:
    i = 0
    n = len(num)
    while(i < n):
        if(num[i] == val):
            num[i] = num[n-1]
            n -=1
        else:
            i+=1
    return n
    

key = int(input())
nums = list(map(int,str(input()).strip().split()))
print(removeElem(nums, key))