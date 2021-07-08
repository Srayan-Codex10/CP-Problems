def roman_to_dec(s: str) -> int:
    roman_conv = {
        "I": 1,
        "V": 5,
        "X": 10,
        "L": 50,
        "C": 100,
        "D": 500,
        "M": 1000
    }
    decimal_val = 0
    curnt = 0
    if not s:
        return 0

    while(curnt < len(s)):
        if(curnt == len(s)-1):
            decimal_val += roman_conv[s[curnt]]
            return decimal_val
        if(roman_conv[s[curnt]] >= roman_conv[s[curnt+1]]):
            decimal_val += roman_conv[s[curnt]]
        elif(roman_conv[s[curnt]] < roman_conv[s[curnt+1]]):
            decimal_val -= roman_conv[s[curnt]]
        curnt += 1


if __name__ == '__main__':
    roman = str(input())
    print(roman_to_dec(roman))


## Left to Right 
## If current_roman >= current_roman+1 then add to total 
## else subtract from total