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



print(list)
print("\n\n")

#TODO: Make nodes
#TODO: Make Cost function
#TODO: Make search function


class Node:
    def __init__(self, positionx, positiony, state, cost): #self, int, int, char, float
        self.positionx = positionx
        self.positiony = positiony
        self.child = [None]
        self.state = state
        self.cost = cost

    def GetCost(self):
        return self.cost

    def GetChildList(self):
        return self.child

#increments step for agent
def next_move(posx, posy, lovelyList):
    while (posy > 0):
        posy -= 1
        print("Up")
    while (posx > 0):
        posx -= 1
        print("Left")

    row = 0
    column = 0
    while row < len(list): #THIS IS THE SEARCH, make it better. Literally just searches every cell row by row
        while column < len(list[row]):
            try:
                dirtX, dirtY = dirtLocator(lovelyList, row)
                print("\nDirt(X,Y) = (" + str(dirtX + 1) + ", " + str(dirtY + 1) + ')')
                posx, posy = moveToLocation(lovelyList, posx, posy, dirtX, dirtY)
                column = dirtX + 1
            except:
                print("No Dirt In Row, Jumping To Next Row")
                column = len(list[row])



        print(posx + 1, posy + 1)
        print()
        row += 1
        column = 0

#CostFunction, inputs readable list current position and the location of the dirt
#Returns new position
def moveToLocation(lovelyList, currentX, currentY, newX, newY):

    while currentX > newX:
        lovelyList[currentY][currentX] = '-'
        print("Left")
        currentX -= 1
        lovelyList[currentY][currentX] = 'b'
        print(lovelyList)
    while currentX < newX:
        lovelyList[currentY][currentX] = '-'
        print("Right")
        currentX += 1
        lovelyList[currentY][currentX] = 'b'
        print(lovelyList)
    while currentY > newY:
        lovelyList[currentY][currentX] = '-'
        print("Up")
        currentY -= 1
        lovelyList[currentY][currentX] = 'b'
        print(lovelyList)
    while currentY < newY:
        lovelyList[currentY][currentX] = '-'
        print("Down")
        currentY += 1
        lovelyList[currentY][currentX] = 'b'
        print(lovelyList)
    print("Clean")
    return currentX, currentY

#Finds the place where the dirt is
def dirtLocator(lovelyList, row): #this is the place for search
    xLocation = 0
    for char in lovelyList[row]:
        if char == 'd':
            dirtX = xLocation
            return dirtX, row
        xLocation += 1
    raise Exception("\n~No Dirt Found~\n")

def BreadthFirstSearch(lovelylist, startPositionX, startPositionY): #Queue FIFO
    startNode = Node(startPositionX, startPositionY, lovelylist[startPositionY][startPositionX], 1)
    AssignChild(lovelylist, startNode)
    frontierQueue = [startNode]

    while frontierQueue != 0:
        tempNode = frontierQueue.pop(0)
        for node in tempNode.GetChildList():
            frontierQueue.append(node)

def AssignChild(lovelylist, node):
    if node.positionx == 0: #if node is in the left boundary
        tempNode = Node(1, node.positiony, lovelylist[node.positiony][1], 1) #node to the right of boundary
        node.child.append(tempNode)
        if node.positiony != 0 and node.positiony != len(lovelylist)-1: #if node is on the left boundary AND not in the corner
            tempNode = Node(node.positionx, node.positiony - 1, lovelylist[node.positiony - 1][node.positionx], 1)  # node above
            node.child.append(tempNode)
            tempNode = Node(node.positionx, node.positiony + 1, lovelylist[node.positiony + 1][node.positionx], 1)  # node below
            node.child.append(tempNode)

    elif node.positionx == len(lovelylist[0])-1: #if node is in the right boundary
        tempNode = Node(len(lovelylist[0])-1, node.positiony, lovelylist[node.positiony][len(lovelylist[0])-1], 1) #node to the left of boundary
        node.child.append(tempNode)
        if node.positiony != 0 and node.positiony != len(lovelylist)-1: #if node is on the right boundary AND not in the corner
            tempNode = Node(node.positionx, node.positiony - 1, lovelylist[node.positiony - 1][node.positionx], 1)  # node above
            node.child.append(tempNode)
            tempNode = Node(node.positionx, node.positiony + 1, lovelylist[node.positiony + 1][node.positionx], 1)  # node below
            node.child.append(tempNode)

    if node.positiony == 0: #if node is on the top of boundary
        tempNode = Node(node.positionx, 1, lovelylist[1][node.positionx], 1)
        node.child.append(tempNode)
        if node.positionx != 0 and node.positionx != len(lovelylist[0]) - 1: #if node is on the top of boundary AND not in the corner
            tempNode = Node(node.positionx - 1, node.positiony, lovelylist[node.positiony][node.positionx - 1], 1)  # node to the left
            node.child.append(tempNode)
            tempNode = Node(node.positionx + 1, node.positiony, lovelylist[node.positiony][node.positionx + 1], 1)  # node to the right
            node.child.append(tempNode)

    elif node.positiony == len(lovelylist)-1: #if node is on the bottom of boundary
        tempNode = Node(node.positionx, len(lovelylist)-2, lovelylist[len(lovelylist)-2][node.positionx], 1)
        node.child.append(tempNode)
        if node.positionx != 0 and node.positionx != len(lovelylist[0]) - 1: #if node is on the bottom of boundary AND not in the corner
            tempNode = Node(node.positionx - 1, node.positiony, lovelylist[node.positiony][node.positionx - 1], 1)  # node to the left
            node.child.append(tempNode)
            tempNode = Node(node.positionx + 1, node.positiony, lovelylist[node.positiony][node.positionx + 1], 1)  # node to the right
            node.child.append(tempNode)

    else:
        tempNode = Node(node.positionx - 1, node.positiony, lovelylist[node.positiony][node.positionx - 1], 1) #node to the left
        node.child.append(tempNode)
        tempNode = Node(node.positionx + 1, node.positiony, lovelylist[node.positiony][node.positionx + 1], 1) #node to the right
        node.child.append(tempNode)
        tempNode = Node(node.positionx, node.positiony - 1, lovelylist[node.positiony - 1][node.positionx], 1) #node above
        node.child.append(tempNode)
        tempNode = Node(node.positionx, node.positiony + 1, lovelylist[node.positiony + 1][node.positionx], 1) #node below
        node.child.append(tempNode)





next_move(0, 0, list)