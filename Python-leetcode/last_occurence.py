size,key = list(map(int,input().split()))
nums = list(map(int,input().split()))
target = 0
for i in range(0,len(nums)):
    if(nums[i] == key):
        target = i

print(target+1)