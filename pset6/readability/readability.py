from cs50 import get_string

a=get_string("Text: ")
l=0
s=0
w=0
flag=0

for element in a:
    if element==' ':
        flag=0
    if element.isalpha():
        if flag==0:
            w+=1
            flag=1
        l+=1
    if element=='.' or element=='!' or element=='?':
        s+=1
        
l=(l/w)*100
s=(s/w)*100

index=0.0588*l-0.296*s-15.8
index=round(index)

if index>16:
    print("Grade 16+")
elif index<1:
    print("Grade 1")
else:
    print(f"Grade {index}")