'''
Note This implementation will work for both sorted and non-sorted arrays.
It doesn't matter if the nums
array is in non-decreasing or non-increasing order
'''
nums = list(map(int, input().strip().split()))
CURRENT = 0
AHEAD = 1
DUP = 0
n = len(nums)
while AHEAD < n:
    if nums[CURRENT] == nums[AHEAD]: ##check if duplicate and keep track of DUPlicates.
        DUP += 1
        AHEAD += 1
    elif nums[CURRENT] != nums[AHEAD]: ##for next non-duplicate
        if DUP != 0:
            nums[CURRENT + 1] = nums[AHEAD]
        CURRENT += 1
        AHEAD += 1
print(CURRENT + 1)
