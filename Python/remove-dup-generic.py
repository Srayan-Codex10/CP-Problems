## Note This implementation will work for both sorted and non-sorted arrays. It doesn't matter if the nums 
##array is in non-decreasing or non-increasing order
nums = list(map(int, input().strip().split()))
current = 0
ahead = 1
dup = 0
n = len(nums)
while(ahead < n):
    if(nums[current] == nums[ahead]): ##check if duplicate and keep track of duplicates.
        dup += 1
        ahead += 1
    elif(nums[current] != nums[ahead]):  ##for next non-duplicate 
        if(dup != 0):
            nums[current + 1] = nums[ahead]
        current += 1
        ahead += 1
print(current + 1)