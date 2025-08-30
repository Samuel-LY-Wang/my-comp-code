import math

a=[]
for i in range(210):
    if math.gcd(210,i) == 1:
        a.append(i)
print(a)