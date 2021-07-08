x = int(input())
rev_str = ''
y=x
while(y!=0 and y!=-1):
    rem = y%10
    y = y//10
    rev_str = rev_str + str(rem)
rev_str = int(rev_str)
print(x==rev_str)