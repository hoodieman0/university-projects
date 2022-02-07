import random

#takes the inputted character and finds it in the grid
def FindBot(char, grid):
    for row in range(len(grid)):
        for column in range(len(grid[row])):
            if grid[row][column] == char:
                print("Bot Found At: (", column + 1, ", ", row + 1, ") [x] [y]") #uses matrix format
                return column, row
    raise Exception("bot_not_found")

#In a 2D board, takes the current position of the bot and moves it to (newX, newY)
#Inputs positions (int) and a grid (list)
def MoveToPosition(currentX, currentY, newX, newY, grid):
    cost = 0
    while currentX > newX:
        grid[currentY][currentX] = '-'
        print("Left\n")
        currentX -= 1
        grid[currentY][currentX] = 'm'
        PrintBoard(grid)
        cost += 1
    while currentX < newX:
        grid[currentY][currentX] = '-'
        print("Right\n")
        currentX += 1
        grid[currentY][currentX] = 'm'
        PrintBoard(grid)
        cost += 1
    while currentY > newY:
        grid[currentY][currentX] = '-'
        print("Up\n")
        currentY -= 1
        grid[currentY][currentX] = 'm'
        PrintBoard(grid)
        cost += 1
    while currentY < newY:
        grid[currentY][currentX] = '-'
        print("Down\n")
        currentY += 1
        grid[currentY][currentX] = 'm'
        PrintBoard(grid)
        cost += 1
    return cost

# shows the game board in a human readable format
# inputs grid (list)
def PrintBoard(board):
    for x in board:
        print(*x, sep='')

#finds where the pricess is calls MoveToPosition to get there, displays total cost
#inputs are the size of the grid (int) and the list that is the grid (list)
def DisplayPathToPrincess1(n, grid):
    #mario is always in the middle of an odd grid, so he must be at the floor of n/2
    currentX, currentY = int(n/2)
    #check each grid corner to determine state
    if grid[0][0] == 'p':
        newX = 0
        newY = 0
    elif grid[n - 1][0] == 'p':
        newX = 0
        newY = n - 1
    elif grid[0][n - 1] == 'p':
        newX = n - 1
        newY = 0
    else:
        newX = n - 1
        newY = n - 1

    print("Princess Found At: (", newX + 1, ", ", newY + 1, ") [x][y] Matrix Format")
    cost = MoveToPosition(currentX, currentY, newX, newY, grid)
    print("Total Cost: ", cost)

def DisplayPathToPrincess2(n, r, c, grid):


#makes a num*num grid and puts the princess in one of the four corners with mario in the center
#num (int) must be odd to work, as per the specification
def CreateBoard1(num):
    if num % 2 == 0:
        raise Exception("odd_integers_only")
    board = [['-']*num for i in range(num)]
    random.seed()
    princessPosition = random.randint(1, 4)
    if princessPosition == 1:
        board[0][0] = 'p'
    elif princessPosition == 2:
        board[0][num-1] = 'p'
    elif princessPosition == 3:
        board[num-1][0] = 'p'
    elif princessPosition == 4:
        board[num-1][num-1] = 'p'
    board[int(num/2)][int(num/2)] = 'm'

#makes a num*num grid and puts the princess and mario in any position
#inputs num (int)
def CreateBoard2(num):
    board = [['-'] * num for i in range(num)]
    random.seed()
    for row in range(len(board)):
        for column in range(len(board[row])):
            if (random.randint(0, 100) % 20 == 0):
                board[row][column] = 'p'
                break
                
    board[random.randint(0, num-1)][random.randint(0, num-1)] = 'm'

    return board

def main():

    gridSize = 3
    try:
        grid = CreateBoard1(gridSize)
    except:
        print("\nGrid Size Must Be Odd. Making 3x3 Grid\n")
        gridSize = 3
        grid = CreateBoard1(gridSize)
    PrintBoard(grid)
    DisplayPathToPrincess1(gridSize, grid)
    print("\n~End Of Program~\n")



main()