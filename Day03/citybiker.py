n=int(input())
lst = [int(i) for i in input().split()][:n]
maxheight=0
height=0
for i in lst:
    height=height+i
    if height>maxheight:
        maxheight=height

print(maxheight)