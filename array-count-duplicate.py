def count(arr=list) -> int:
    arr.sort()
    result = 0
    start = 0       ## use two pointers and perform comparison and duplicate-counting in-place
    ahead = 1
    dup_count = 0    ##keep track of duplicates
    while(ahead < len(arr)):
        if(arr[ahead] - arr[start] == 0):
            dup_count += 1
        elif(arr[ahead] - arr[start] == 1):
            if(dup_count != 0):
                dup_count += 1
                result += dup_count
            else :
                result+=1
            start = ahead
            dup_count = 0
        
        ahead += 1
    return result


if __name__ == '__main__':
    inp = input().strip().split()
    nums_list = [int(i) for i in inp]

    # print(inp)                        ##for debugging
    # print(nums_list)
    try:
        print(count(nums_list))  ## prints the count
    except Exception as e:
        print("Error Execution Failed")
        raise


# 1 1 2 3 0
# 4

# 1 1 
# 0
