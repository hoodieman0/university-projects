maxRows = 5
maxColumns = 5

#[row (y)][column (x)]
gameBoard = [['-']*maxColumns for i in range(maxRows)]

gameBoard[0][0] = 'b'

gameBoard[0][4] = 'd'
gameBoard[1][2] = 'd'
gameBoard[1][4] = 'd'
gameBoard[2][2] = 'd'
gameBoard[2][3] = 'd'
gameBoard[3][2] = 'd'
gameBoard[4][4] = 'd'

"""

Game Board: 
b - - - d
- - d - d
- - d d -
- - d - -
- - - - d

"""

def FindBot(gameBoard):
    columnPosition = 0
    rowPosition = 0
    for row in gameBoard:
        for column in gameBoard[rowPosition]:
            if column == 'b':
                return columnPosition, rowPosition
            columnPosition += 1
        rowPosition += 1
    raise Exception("bot_not_found")

print("\n", list)


#TODO: Make Cost function


class Node:
    def __init__(self, positionx, positiony, state, cost): #self, int, int, char, float
        self.positionx = positionx
        self.positiony = positiony
        self.child = []
        self.state = state
        self.cost = cost

    def GetCost(self):
        return self.cost

    def GetChildList(self):
        return self.child

#increments step for agent, inputs initial position and game board state
def next_move(posx, posy, gameBoard):
    goalBool = False
    while goalBool != True:
        print("\nCurrent Position = (", posx + 1, ", ", posy + 1, ") [Column, Row] \n")
        try:
            tempNode = BreadthFirstSearch(gameBoard, posx, posy)
        except:
            print("Nothing Returned From BreadthFirstSearch(): Exiting...")
            goalBool = True
            continue
        print("\nDirt Found At: ", tempNode.positionx, tempNode.positiony)
        posx, posy = MoveToLocation(gameBoard, posx, posy, tempNode.positionx, tempNode.positiony)

    print(("\n~End Of Program~\n"))

#CostFunction, inputs readable list current position and the location of the dirt
#Returns new position
def MoveToLocation(gameBoard, currentX, currentY, newX, newY):

    while currentX > newX:
        gameBoard[currentY][currentX] = '-'
        print("\nLeft")
        currentX -= 1
        gameBoard[currentY][currentX] = 'b'
        print(gameBoard)
    while currentX < newX:
        gameBoard[currentY][currentX] = '-'
        print("\nRight")
        currentX += 1
        gameBoard[currentY][currentX] = 'b'
        print(gameBoard)
    while currentY > newY:
        gameBoard[currentY][currentX] = '-'
        print("\nUp")
        currentY -= 1
        gameBoard[currentY][currentX] = 'b'
        print(gameBoard)
    while currentY < newY:
        gameBoard[currentY][currentX] = '-'
        print("\nDown")
        currentY += 1
        gameBoard[currentY][currentX] = 'b'
        print(gameBoard)
    print("Clean")
    return currentX, currentY

#Frontier is Queue FIFO, returns the position of the located dirt else throws 0, 0
def BreadthFirstSearch(gameBoard, startPositionX, startPositionY):
    tempNode = Node(startPositionX, startPositionY, gameBoard[startPositionY][startPositionX], 1)
    frontierQueue = [tempNode]
    exploredList = [tempNode]

    while len(frontierQueue) != 0:
        tempNode = frontierQueue.pop(0)     #takes first item in frontier
        if tempNode.state == 'd':           #if goal return node
            return tempNode
                                            #if neither get its children and add them to frontier, add parent to explored
        AssignChild(gameBoard, tempNode)
        for node in tempNode.child:
            if node not in exploredList:
                exploredList.append(tempNode)
                frontierQueue.append(node)
    raise Exception("goal_state_not_found")

#gets the children of the node, meant for 2D space with no diagonals, inputs game board state and parent node
def AssignChild(gameBoard, node):
    if node.positionx == 0: #if node is in the left boundary
        tempNode = Node(1, node.positiony, gameBoard[node.positiony][1], 1) #node to the right of boundary
        node.child.append(tempNode)
        if node.positiony > 0 and node.positiony < len(gameBoard)-1: #if node is on the left boundary AND not in the corner
            tempNode = Node(node.positionx, node.positiony - 1, gameBoard[node.positiony - 1][node.positionx], 1)  # node above
            node.child.append(tempNode)
            tempNode = Node(node.positionx, node.positiony + 1, gameBoard[node.positiony + 1][node.positionx], 1)  # node below
            node.child.append(tempNode)

    elif node.positionx == len(gameBoard[0])-1: #if node is in the right boundary
        tempNode = Node(len(gameBoard[0])-1, node.positiony, gameBoard[node.positiony][len(gameBoard[0])-1], 1) #node to the left of boundary
        node.child.append(tempNode)
        if node.positiony > 0 and node.positiony < len(gameBoard)-1: #if node is on the right boundary AND not in the corner
            tempNode = Node(node.positionx, node.positiony - 1, gameBoard[node.positiony - 1][node.positionx], 1)  # node above
            node.child.append(tempNode)
            tempNode = Node(node.positionx, node.positiony + 1, gameBoard[node.positiony + 1][node.positionx], 1)  # node below
            node.child.append(tempNode)

    if node.positiony == 0: #if node is on the top of boundary
        tempNode = Node(node.positionx, 1, gameBoard[1][node.positionx], 1)
        node.child.append(tempNode)
        if node.positionx > 0 and node.positionx < len(gameBoard[0]) - 1: #if node is on the top of boundary AND not in the corner
            tempNode = Node(node.positionx - 1, node.positiony, gameBoard[node.positiony][node.positionx - 1], 1)  # node to the left
            node.child.append(tempNode)
            tempNode = Node(node.positionx + 1, node.positiony, gameBoard[node.positiony][node.positionx + 1], 1)  # node to the right
            node.child.append(tempNode)

    elif node.positiony == len(gameBoard)-1: #if node is on the bottom of boundary
        tempNode = Node(node.positionx, len(gameBoard)-2, gameBoard[len(gameBoard)-2][node.positionx], 1)
        node.child.append(tempNode)
        if node.positionx > 0 and node.positionx < len(gameBoard[0]) - 1: #if node is on the bottom of boundary AND not in the corner
            tempNode = Node(node.positionx - 1, node.positiony, gameBoard[node.positiony][node.positionx - 1], 1)  # node to the left
            node.child.append(tempNode)
            tempNode = Node(node.positionx + 1, node.positiony, gameBoard[node.positiony][node.positionx + 1], 1)  # node to the right
            node.child.append(tempNode)

    if node.positionx > 0 and node.positionx < len(gameBoard[0]) - 1 and node.positiony > 0 and node.positiony < len(gameBoard)-1:
        tempNode = Node(node.positionx - 1, node.positiony, gameBoard[node.positiony][node.positionx - 1], 1) #node to the left
        node.child.append(tempNode)
        tempNode = Node(node.positionx + 1, node.positiony, gameBoard[node.positiony][node.positionx + 1], 1) #node to the right
        node.child.append(tempNode)
        tempNode = Node(node.positionx, node.positiony - 1, gameBoard[node.positiony - 1][node.positionx], 1) #node above
        node.child.append(tempNode)
        tempNode = Node(node.positionx, node.positiony + 1, gameBoard[node.positiony + 1][node.positionx], 1) #node below
        node.child.append(tempNode)


try:
    x,y = FindBot(gameBoard)
except:
    print("Bot Not Found")
next_move(x, y, gameBoard)