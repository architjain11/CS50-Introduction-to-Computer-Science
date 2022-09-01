from cs50 import get_int

num=get_int("Number: ")
a=num
nod=0

while(a>0):
    nod+=1
    a=a//10

flag=0
total=0
a=num

for i in range(nod):
    if flag==0:
        total+=a%10
        a//=10
        flag=1
    else:
        x=2*(a%10)
        if x//10==0:
            total+=x
        else:
            total+=x%10
            x//=10
            total+=x
        a//=10
        flag=0

a=num

if total%10==0:
    for i in range(nod-2):
        a//=10
    if nod==15 and (a==34 or a==37):
        print("AMEX")
    elif nod==16 and (a>=51 and a<=55):
        print("MASTERCARD")
    elif (nod==16 or nod==13) and a//10==4:
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")