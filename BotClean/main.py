row = 5
column = 5

#[row][column]
list = [['-']*column for i in range(row)]

list[0][0] = 'b'

list[0][4] = 'd'
list[1][2] = 'd'
list[1][4] = 'd'
list[2][2] = 'd'
list[2][3] = 'd'
list[3][2] = 'd'
list[4][4] = 'd'
"""

Game Board: 
b - - - d
- - d - d
- - d d -
- - d - -
- - - - d

"""


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
def next_move(posx, posy, lovelyList):
    goalBool = False
    while goalBool != True:
        print("\nCurrent Position = (", posx + 1, ", ", posy + 1, ") [Column, Row] \n")
        try:
            tempNode = BreadthFirstSearch(lovelyList, posx, posy)
        except:
            print("Nothing Returned From BreadthFirstSearch(): Exiting...")
            goalBool = True
            continue
        print("\nDirt Found At: ", tempNode.positionx, tempNode.positiony)
        posx, posy = MoveToLocation(lovelyList, posx, posy, tempNode.positionx, tempNode.positiony)

    print(("\n~End Of Program~\n"))

#CostFunction, inputs readable list current position and the location of the dirt
#Returns new position
def MoveToLocation(lovelyList, currentX, currentY, newX, newY):

    while currentX > newX:
        lovelyList[currentY][currentX] = '-'
        print("\nLeft")
        currentX -= 1
        lovelyList[currentY][currentX] = 'b'
        print(lovelyList)
    while currentX < newX:
        lovelyList[currentY][currentX] = '-'
        print("\nRight")
        currentX += 1
        lovelyList[currentY][currentX] = 'b'
        print(lovelyList)
    while currentY > newY:
        lovelyList[currentY][currentX] = '-'
        print("\nUp")
        currentY -= 1
        lovelyList[currentY][currentX] = 'b'
        print(lovelyList)
    while currentY < newY:
        lovelyList[currentY][currentX] = '-'
        print("\nDown")
        currentY += 1
        lovelyList[currentY][currentX] = 'b'
        print(lovelyList)
    print("Clean")
    return currentX, currentY

#Frontier is Queue FIFO, returns the position of the located dirt else throws 0, 0
def BreadthFirstSearch(lovelylist, startPositionX, startPositionY):
    tempNode = Node(startPositionX, startPositionY, lovelylist[startPositionY][startPositionX], 1)
    frontierQueue = [tempNode]
    exploredList = [tempNode]

    while len(frontierQueue) != 0:
        tempNode = frontierQueue.pop(0)     #takes first item in frontier
        if tempNode.state == 'd':           #if goal return node
            return tempNode
                                            #if neither get its children and add them to frontier, add parent to explored
        AssignChild(lovelylist, tempNode)
        for node in tempNode.child:
            if node not in exploredList:
                exploredList.append(tempNode)
                frontierQueue.append(node)
    raise Exception("goal_state_not_found")

#gets the children of the node, meant for 2D space with no diagonals, inputs game board state and parent node
def AssignChild(lovelylist, node):
    if node.positionx == 0: #if node is in the left boundary
        tempNode = Node(1, node.positiony, lovelylist[node.positiony][1], 1) #node to the right of boundary
        node.child.append(tempNode)
        if node.positiony > 0 and node.positiony < len(lovelylist)-1: #if node is on the left boundary AND not in the corner
            tempNode = Node(node.positionx, node.positiony - 1, lovelylist[node.positiony - 1][node.positionx], 1)  # node above
            node.child.append(tempNode)
            tempNode = Node(node.positionx, node.positiony + 1, lovelylist[node.positiony + 1][node.positionx], 1)  # node below
            node.child.append(tempNode)

    elif node.positionx == len(lovelylist[0])-1: #if node is in the right boundary
        tempNode = Node(len(lovelylist[0])-1, node.positiony, lovelylist[node.positiony][len(lovelylist[0])-1], 1) #node to the left of boundary
        node.child.append(tempNode)
        if node.positiony > 0 and node.positiony < len(lovelylist)-1: #if node is on the right boundary AND not in the corner
            tempNode = Node(node.positionx, node.positiony - 1, lovelylist[node.positiony - 1][node.positionx], 1)  # node above
            node.child.append(tempNode)
            tempNode = Node(node.positionx, node.positiony + 1, lovelylist[node.positiony + 1][node.positionx], 1)  # node below
            node.child.append(tempNode)

    if node.positiony == 0: #if node is on the top of boundary
        tempNode = Node(node.positionx, 1, lovelylist[1][node.positionx], 1)
        node.child.append(tempNode)
        if node.positionx > 0 and node.positionx < len(lovelylist[0]) - 1: #if node is on the top of boundary AND not in the corner
            tempNode = Node(node.positionx - 1, node.positiony, lovelylist[node.positiony][node.positionx - 1], 1)  # node to the left
            node.child.append(tempNode)
            tempNode = Node(node.positionx + 1, node.positiony, lovelylist[node.positiony][node.positionx + 1], 1)  # node to the right
            node.child.append(tempNode)

    elif node.positiony == len(lovelylist)-1: #if node is on the bottom of boundary
        tempNode = Node(node.positionx, len(lovelylist)-2, lovelylist[len(lovelylist)-2][node.positionx], 1)
        node.child.append(tempNode)
        if node.positionx > 0 and node.positionx < len(lovelylist[0]) - 1: #if node is on the bottom of boundary AND not in the corner
            tempNode = Node(node.positionx - 1, node.positiony, lovelylist[node.positiony][node.positionx - 1], 1)  # node to the left
            node.child.append(tempNode)
            tempNode = Node(node.positionx + 1, node.positiony, lovelylist[node.positiony][node.positionx + 1], 1)  # node to the right
            node.child.append(tempNode)

    if node.positionx > 0 and node.positionx < len(lovelylist[0]) - 1 and node.positiony > 0 and node.positiony < len(lovelylist)-1:
        tempNode = Node(node.positionx - 1, node.positiony, lovelylist[node.positiony][node.positionx - 1], 1) #node to the left
        node.child.append(tempNode)
        tempNode = Node(node.positionx + 1, node.positiony, lovelylist[node.positiony][node.positionx + 1], 1) #node to the right
        node.child.append(tempNode)
        tempNode = Node(node.positionx, node.positiony - 1, lovelylist[node.positiony - 1][node.positionx], 1) #node above
        node.child.append(tempNode)
        tempNode = Node(node.positionx, node.positiony + 1, lovelylist[node.positiony + 1][node.positionx], 1) #node below
        node.child.append(tempNode)





next_move(0, 0, list)