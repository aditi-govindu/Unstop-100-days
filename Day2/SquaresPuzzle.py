'''
Description: On a 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4 directionally adjacent number and swapping it.
Given the puzzle board, print the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, print -1.
'''
def slidingPuzzle(board):
        moves, used, cnt = {0: {1, 3}, 1:{0, 2, 4}, 2:{1, 5}, 3:{0, 4}, 4:{1, 3, 5}, 5:{2, 4}}, set(), 0
        # Store current board state in string s
        s = "".join(str(c) for row in board for c in row)
        q = [(s, s.index("0"))]

        # If 0 is not at location 0, find moves
        while q:
            new = []
            for s, i in q:
                # Add string to set of paths
                used.add(s)
                if s == "123450":
                    return cnt
                arr = [c for c in s]
                for move in moves[i]:
                    new_arr = arr[:]
                    # Swap positions of letters 1 by 1
                    new_arr[i], new_arr[move] = new_arr[move], new_arr[i]
                    new_s = "".join(new_arr)
                    # Add path to set of visited paths
                    if new_s not in used:
                        new.append((new_s, move))
            # Increment count of paths chosen
            cnt += 1
            q = new
        return -1

# Driver code
board = []
for i in range(2):
    data = [int(x) for x in input().split()]
    board.append(data)
print(slidingPuzzle(board))