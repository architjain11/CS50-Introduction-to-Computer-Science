from cs50 import get_float

change=get_float("Change owed: ")

while change<0:
    change=get_float("Change owed: ")

change*=100
coins=0

while change>=25:
    change-=25
    coins+=1
while change>=10:
    change-=10
    coins+=1
while change>=5:
    change-=5
    coins+=1
while change>=1:
    change-=1
    coins+=1

print(coins)

