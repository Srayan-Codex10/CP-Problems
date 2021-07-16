def removeElement(nums: list, val: int) -> int:
        index = 0
        for i in range(0,len(nums)):
            if(nums[i] != val):
                nums[index] = nums[i]
                index+=1
        return index

val = int(input())
nums = list(map(int,input().strip().split()))
removeElement(nums,val)