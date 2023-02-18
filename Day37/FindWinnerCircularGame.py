'''
Description: Marco is at the birthday party of his best friend. The friends are sitting in a circle and are numbered from 1 to n in clockwise order  and playing a game with a pillow. The rules of the games are as follows :

Start at the 1st
Count the next k friends in the clockwise direction including the friend you started at. The counting wraps around the circle and may count some friends more than once.
The last friend you counted will hold the pillow and will leave the circle and lose the game.
If there is still more than one friend in the circle, go back to step 2 starting from the friend immediately clockwise of the friend who just lost and repeat.
Else, the last friend in the circle wins the game.
Marco is curious that at what position he should sit in the circle so that he wins the game.
'''

n = int(input())
k = int(input())

players = [i for i in range(1, n+1)]
nxt = 0
current = 0

while len(players) > 1:
    current = (current + k - 1) % len(players)
    # If end of circle reached, go back to start
    if current == len(players) - 1:
        nxt = 0 
    else:
        nxt = current
    # Remove player from circle
    del players[current]
    # Start cycle from player after removed one
    current = nxt
print(players[0])
