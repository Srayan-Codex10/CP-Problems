## a one-liner for list operations 
nums = list(map(int, input().strip().split()))
print(any([num % 7 == 0 for num in nums]))  ## modify modulus operation to check any other functionality