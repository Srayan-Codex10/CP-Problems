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
    if not s:
        return 0
    if len(s)==1:
        return roman_conv[s[0]]
    index = len(s)
    max_val = roman_conv[s[index-1]]
    for i in range(index-1, -1, -1):
        current = roman_conv[s[i]]
        if current >= max_val:
            decimal_val += current
            max_val = current
        else:
            decimal_val -= current
    return decimal_val

if __name__=='__main__':
    roman = str(input())
    print(roman_to_dec(roman))

##Roman to Numeral Conversion 
## Right to Left
## Keep track of last maximum value. 
# If current > max update total and max else subtract from total