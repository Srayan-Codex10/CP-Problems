x = int(input())
rev_str = ''
num=x
while(num!=0 and num!=-1):
    rem = num%10
    num = num//10
    rev_str = rev_str + str(rem)
if(x==0):
    print(True)
elif(x==-1):
    print(False)
else:
    print(x==int(rev_str))