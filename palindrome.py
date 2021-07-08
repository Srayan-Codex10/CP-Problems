import sys,traceback
def isPalindrome(x:int) -> bool: 
    ##alternate approach 
    # return str(x) == str(x)[::-1]
    rev_str = ''
    num = x
    while(num != 0 and num != -1): ##loops until quotient becomes zero. At every iteration , concatenates remainder to get reverse numebr
        rem = num % 10
        num = num//10
        rev_str = rev_str + str(rem)
    if(x == 0):
        return(True)
    elif(x == -1):
        return(False)
    else:
        return(x == int(rev_str))


if __name__=='__main__':
    num = int(input("Enter an Integer: "))
    try:
        print(isPalindrome(num))
    except Exception as ex:
        traceback.print_exception(*sys.exc_info())
        print("Execution Failed")


# Enter an Integer: 897
# False

# Enter an Integer: -121
# False

# Enter an Integer: -1
# False

# Enter an Integer: 0
# True