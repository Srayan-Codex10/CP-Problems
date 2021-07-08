def count(arr=list) -> int:
    arr.sort()
    result = 0
    start = 0
    ahead = 1
    dup_count = 0
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

    print(inp)
    print(nums_list)
    print(count(nums_list))



