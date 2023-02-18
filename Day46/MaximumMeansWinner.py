# Enter your code here. Read input from STDIN. Print output to STDOUT

'''
Description: There are N suns in a galaxy, each sun has M planets,each of the M planets have some number of moons, denoted by galaxy(i)(j), where galaxy(i)(j) denotes the number of moons of the jth planet having i th sun.

Output the maximum number of moons for a planet.
'''

suns, planets = map(int, input().split())
galaxy = []
maxi = float('-inf')

for i in range(suns):
    temp = [int(x) for x in input().split()]
    # Array for every sun represents the moons per planet
    galaxy.append(temp)

for i in range(suns):
    # Find total moons for a sun in a galaxy
    temp = sum(galaxy[i])
    # Store maximum sun
    if maxi < temp:
        maxi = temp
print(maxi)