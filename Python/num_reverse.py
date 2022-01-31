def reverse(num: int):
    '''
    Take a number and reverse it. No String conversion
    '''
    if num in (0, 1):
        print("Reversed Number {}".format(num))
        return
    num_rev = 0
    num_q = num

    while num_q > 0:
        rem = num_q % 10
        num_q = num_q//10
        num_rev = num_rev * 10 + rem
    print("Reversed Number {}".format(num_rev))


if __name__ == "__main__":
    number = int(input('Enter number: '))
    reverse(number)
