def isPalindromePermut(x: str) -> bool:
    if(x == x[::-1]):  ##check with simple string reverse if string is already a palindrome
        print(True)
    else:               ##try to build a palindrome permutation if possible by comparing with reverse of string
        arr = list(x)
        for i in range(len(x)-1,-1,-1):
            rev = list(arr[::-1])
            if(arr[i] != rev[i]):
                arr[i-1],arr[i] = arr[i], arr[i-1]
        if(arr == arr[::-1]):
            return True
        else:
            return False


if __name__ == '__main__':
    input_str = str(input().strip())
    #call function
    if(isPalindromePermut(input_str)):
        print("Palindrome permutation possible")
    else:
        print("Palindrome permutation not possible")