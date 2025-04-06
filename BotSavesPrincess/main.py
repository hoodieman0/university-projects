import random #used in CreateGrid1() and CreateGrid2()

#takes the inputted character(char) and finds it in the grid(list)
#returns the (x,y) position of bot
def FindBot(char, grid):
    for row in range(len(grid)):
        for column in range(len(grid[row])):    #slow O(n^2) time
            if grid[row][column] == char:
                print("Bot Found At: (", column + 1, ", ", row + 1, ") [x][y] Matrix Format\n") #uses matrix format
                return column, row
    raise Exception("bot_not_found")

#in a 2D grid, takes the current position of the bot and moves it to (newX, newY)
#inputs positions (int) and a grid (list)
#returns the number of steps taken
def MoveToPosition(currentX, currentY, newX, newY, grid):
    cost = 0
    while currentX > newX:
        grid[currentY][currentX] = '-'
        print("Left")
        currentX -= 1
        grid[currentY][currentX] = 'm'
        PrintGrid(grid)
        cost += 1
    while currentX < newX:
        grid[currentY][currentX] = '-'
        print("Right")
        currentX += 1
        grid[currentY][currentX] = 'm'
        PrintGrid(grid)
        cost += 1
    while currentY > newY:
        grid[currentY][currentX] = '-'
        print("Up")
        currentY -= 1
        grid[currentY][currentX] = 'm'
        PrintGrid(grid)
        cost += 1
    while currentY < newY:
        grid[currentY][currentX] = '-'
        print("Down")
        currentY += 1
        grid[currentY][currentX] = 'm'
        PrintGrid(grid)
        cost += 1
    return cost

#shows the game grid in a human readable format
#inputs grid (list)
def PrintGrid(grid):
    for x in grid:
        print(*x, sep='')
    print()

#finds which corner the princess is in, calls MoveToPosition to get there, displays total cost
#inputs are the size of the grid (int) and the list that is the grid (list), use CreateGrid1 for the grid
def DisplayPathToPrincess1(n, grid):
    #mario is always in the middle of an odd grid, so he must be at floor(n/2)
    currentX = int(n/2)
    currentY = int(n/2)

    #check each grid corner to determine if the princess is there
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

    print("Princess Found At: (", newX + 1, ", ", newY + 1, ") [x][y] Matrix Format\n")
    cost = MoveToPosition(currentX, currentY, newX, newY, grid)
    print("Total Cost: ", cost, "\n")

#finds where the pricess is using BreadthFirstSearch, calls MoveToPosition to get there, displays total cost
#inputs grid size (int), the row and column mario is in (int) and the grid (list), use CreateGrid2 for the grid
def DisplayPathToPrincess2(n, r, c, grid):
    newX, newY = BreadthFirstSearch('p', c, r, grid)
    cost = MoveToPosition(c, r, newX, newY, grid)
    print("Total Cost: ", cost)

#Scans adjacent nodes for the goal state, list implementation
#inputs the goal to find (char), the x and y position of the start (int), and the grid (list)
def BreadthFirstSearch(goalState, currentX, currentY, grid): #I wanted to do this with nodes and as a graph but I kept running into bugs
    iVector = [-1, 0, 1, 0]     #parallel vector lists, helps traverse the 2D list
    jVector = [0, 1, 0, -1]

    frontierQueue = [] #can be better implemented with deque: "from collections import deque". Has O(1) pop and append operations
    exploredList = [[False] * len(grid[0]) for i in range(len(grid))] #True False grid that mirrors the actual grid
    frontierQueue.append((currentX, currentY))

    while frontierQueue:
        node = frontierQueue.pop(0)
        x = node[0]
        y = node[1]

        for i in range(0, 4):
            newX = x + iVector[i]
            newY = y + jVector[i]
            if newY >= len(grid) or newY < 0 or newX >= len(grid[0]) or newX < 0:
                continue
            if not exploredList[newY][newX]:
                if grid[newY][newX] == goalState:
                    print("Princess Found At: (", newX + 1, ", ", newY + 1, ") [x][y] Matrix Format\n")
                    return newX, newY
                frontierQueue.append((newX, newY))
                exploredList[newY][newX] = True



#makes a num*num grid and puts the princess in one of the four corners with mario in the center
#num (int) must be odd to work, as per the specification
def CreateGrid1(num):
    if num % 2 == 0:
        raise Exception("odd_integers_only")
    grid = [['-']*num for i in range(num)]
    random.seed()
    princessPosition = random.randint(1, 4)
    if princessPosition == 1:
        grid[0][0] = 'p'
    elif princessPosition == 2:
        grid[0][num-1] = 'p'
    elif princessPosition == 3:
        grid[num-1][0] = 'p'
    elif princessPosition == 4:
        grid[num-1][num-1] = 'p'
    grid[int(num/2)][int(num/2)] = 'm'
    return grid

#makes a num*num grid and puts the princess and mario in any position
#inputs num (int)
def CreateGrid2(num):
    grid = [['-'] * num for i in range(num)]
    random.seed()
    grid[random.randint(0, num - 1)][random.randint(0, num - 1)] = 'p'
    grid[random.randint(0, num-1)][random.randint(0, num-1)] = 'm'

    return grid

def main():
    print("~~~Bot Saves Princess Test~~~")
    gridSize = 7
    try:
        grid = CreateGrid1(gridSize)
    except:
        print("\nGrid Size Must Be Odd. Making 3x3 Grid\n")
        gridSize = 3
        grid = CreateGrid1(gridSize)
    PrintGrid(grid)
    DisplayPathToPrincess1(gridSize, grid)



    print("~~~Bot Saves Princess 2 Tests~~~")
    gridSize = 5
    grid = CreateGrid2(gridSize)
    PrintGrid(grid)
    x, y = FindBot('m', grid)
    DisplayPathToPrincess2(gridSize, y, x, grid)

    print("\n~End Of Program~\n")



main()