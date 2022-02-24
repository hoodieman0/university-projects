class Node:
    def __init__(self, state, position, parent=None, pathCost=0):  # list of strings, tuple, Node, int
        self.state = state  # node's game state
        self.position = position
        self.parent = parent  # previous game state
        self.pathCost = pathCost  # cost to get to this state
        self.depth = 0
        if parent:  # how far in the tree node is
            self.depth = parent.depth + 1

    # return a list of all possible moves, this is copy/paste from my code that was paired with Node class
    def Expand(self):
        list = []
        board = self.state.copy()
        for item in self.Actions(self.state, self.position):
            #r, c = FindPacman(board)
            board[item[0]][item[1]] = 'P'
            #board[r][c] = '-'
            list.append(Node(board, (item[0], item[1]), self, self.pathCost + 1))
            board = self.state.copy()
        return list

    # board is list of strings, pacman is a tuple of ints
    def Actions(self, board, pacman):  # Up Left Right Down of pacman
        list = [(pacman[0] - 1, pacman[1]), (pacman[0], pacman[1] - 1), (pacman[0], pacman[1] + 1),
                (pacman[0] + 1, pacman[1])]

        newList = []
        for coord in list:
            if board[coord[0]][coord[1]] == '-' or board[coord[0]][coord[1]] == '.':
                newList.append(coord)
        return newList

def FindPacman(board):
    for i in range (0, len(board)):
        for j in range(0, len(board[i])):
            if board[i][j] == 'P':
                return (i, j)

def ManhattanHueristic(r, c, r1, c1):
    return abs(r1 - r) + abs(c1 - c)


# f(n) = h(n) + g(n)
# node, tuple
def CostFunction(node, goal):
    return ManhattanHueristic(node.position[0], node.position[1], goal[0], goal[1]) + node.pathCost


# list of string, tuple, tuple
def AStar(board, pacman, food):
    tempNode = Node(board, pacman, None, 0)  # first state
    frontierPriorityQueue = []  # remember to sort
    exploredList = []
    closedList = []

    frontierPriorityQueue.append((CostFunction(tempNode, food), tempNode))
    closedList.append(tempNode)

    while frontierPriorityQueue:
        nodeInfo = frontierPriorityQueue.pop(0)
        node = nodeInfo[1]
        #print("Here:", node.position)
        #print(node.state, end='\n\n')
        if node.position == food:
            return node

        exploredList.append(node)
        closedList.append(node)

        for child in node.Expand():
            # if child not in exploredList and child not in frontierPriorityQueue:
            # frontierPriorityQueue.append((CostFunction(child, food), child))

            if child.pathCost < node.pathCost and child.state in closedList:
                child.parent = node
                child.pathCost = node.pathCost + 1
                print("Child Is Less\n")

            elif child.pathCost > node.pathCost and child in frontierPriorityQueue:
                child.parent = node
                child.pathCost = node.pathCost + 1
                print("Node Is Less\n")
            # if CostFunction(child, food) < CostFunction(node, food):        #what is this comparison supposed to be?
            #   frontierPriorityQueue.append((CostFunction(child, food), child))
            #  pathList.append()
            elif child not in frontierPriorityQueue and child not in closedList:
                frontierPriorityQueue.append((CostFunction(child, food), child))
            frontierPriorityQueue.sort(key=lambda f: f[0])
    return None


def main():
    """pacman = input().split()
    for i in range(0, len(pacman)):
        pacman[i] = (int)(pacman[i])

    food = input().split()
    for i in range(0, len(food)):
        food[i] = (int)(food[i])

    gridSize = input().split()
    for i in range(0, len(gridSize)):
        gridSize[i] = (int)(gridSize[i])

    board = []
    for i in range(0, gridSize[0]):
        board.append(list(input()))

    pacman = tuple(pacman)
    food = tuple(food)"""

    thing = ["%%%%%", "%---%", "%-%-%", "%.%P%", "%%%%%"]
    board = []
    board.append(list(thing[0]))
    board.append(list(thing[1]))
    board.append(list(thing[2]))
    board.append(list(thing[3]))
    board.append(list(thing[4]))
    print(board)
    pacman = (3, 3)
    food = (3, 1)


    thing = [['%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%'], ['%', '-', '-', '-', '-', '-', '-', '-', '%', '-', '%', '-', '%', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '%', '-', '-', '-', '%', '-', '-', '-', '-', '-', '%', '-', '%'], ['%', '-', '%', '%', '%', '%', '%', '%', '%', '-', '%', '-', '%', '%', '%', '-', '%', '-', '%', '%', '%', '-', '%', '%', '%', '-', '%', '%', '%', '%', '%', '%', '%', '-', '%', '-', '%'], ['%', '-', '-', '-', '-', '-', '-', '-', '%', '-', '-', '-', '-', '-', '-', '-', '%', '-', '%', '-', '-', '-', '-', '-', '%', '-', '-', '-', '-', '-', '%', '-', '%', '-', '-', '-', '%'], ['%', '%', '%', '%', '%', '-', '%', '%', '%', '%', '%', '-', '%', '%', '%', '-', '%', '-', '%', '-', '%', '-', '%', '%', '%', '-', '%', '%', '%', '%', '%', '-', '%', '-', '%', '%', '%'], ['%', '-', '-', '-', '%', '-', '%', '-', '%', '-', '%', '-', '-', '-', '%', '-', '%', '-', '%', '-', '%', '-', '-', '-', '%', '-', '%', '-', '-', '-', '%', '-', '%', '-', '-', '-', '%'], ['%', '-', '%', '%', '%', '-', '%', '-', '%', '-', '%', '-', '%', '%', '%', '-', '%', '%', '%', '%', '%', '-', '%', '%', '%', '-', '%', '-', '%', '%', '%', '-', '%', '%', '%', '-', '%'], ['%', '-', '-', '-', '-', '-', '-', '-', '%', '-', '-', '-', '-', '-', '%', '-', '-', '-', '%', '-', '-', '-', '%', '-', '-', '-', '-', '-', '%', '-', '%', '-', '%', '-', '-', '-', '%'], ['%', '%', '%', '-', '%', '%', '%', '%', '%', '%', '%', '%', '%', '-', '%', '%', '%', '%', '%', '%', '%', '-', '%', '%', '%', '-', '%', '%', '%', '-', '%', '-', '%', '-', '%', '-', '%'], ['%', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '%', '-', '-', '-', '-', '-', '-', '-', '%', '-', '%', '-', '-', '-', '%', '-', '-', '-', '-', '-', '%', '-', '%'], ['%', '-', '%', '-', '%', '%', '%', '%', '%', '-', '%', '-', '%', '%', '%', '-', '%', '-', '%', '-', '%', '%', '%', '-', '%', '-', '%', '%', '%', '-', '%', '%', '%', '-', '%', '-', '%'], ['%', '-', '%', '-', '%', '-', '-', '-', '-', '-', '%', '-', '%', '-', '%', '-', '%', '-', '%', '-', '-', '-', '-', '-', '%', '-', '-', '-', '%', '-', '%', '-', '%', '-', '%', '-', '%'], ['%', '-', '%', '-', '%', '-', '%', '%', '%', '%', '%', '%', '%', '-', '%', '-', '%', '%', '%', '%', '%', '%', '%', '%', '%', '-', '%', '%', '%', '-', '%', '-', '%', '%', '%', '-', '%'], ['%', '-', '%', '-', '%', '-', '%', '-', '-', '-', '-', '-', '%', '-', '-', '-', '%', '-', '-', '-', '-', '-', '%', '-', '-', '-', '-', '-', '%', '-', '-', '-', '%', '-', '-', '-', '%'], ['%', '%', '%', '-', '%', '%', '%', '-', '%', '-', '%', '%', '%', '%', '%', '-', '%', '%', '%', '%', '%', '-', '%', '%', '%', '-', '%', '%', '%', '-', '%', '%', '%', '%', '%', '-', '%'], ['%', '-', '-', '-', '-', '-', '%', '-', '%', '-', '%', '-', '-', '-', '-', '-', '%', '-', '%', '-', '-', '-', '-', '-', '%', '-', '%', '-', '-', '-', '%', '-', '%', '-', '%', '-', '%'], ['%', '-', '%', '-', '%', '-', '%', '-', '%', '-', '%', '%', '%', '-', '%', '%', '%', '-', '%', '%', '%', '-', '%', '%', '%', '-', '%', '-', '%', '-', '%', '-', '%', '-', '%', '-', '%'], ['%', '-', '%', '-', '%', '-', '%', '-', '%', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '%', '-', '%', '-', '%', '-', '-', '-', '-', '-', '%'], ['%', '%', '%', '-', '%', '%', '%', '%', '%', '%', '%', '-', '%', '-', '%', '-', '%', '%', '%', '%', '%', '-', '%', '%', '%', '-', '%', '-', '%', '%', '%', '-', '%', '%', '%', '%', '%'], ['%', '-', '-', '-', '-', '-', '-', '-', '%', '-', '%', '-', '%', '-', '%', '-', '-', '-', '-', '-', '%', '-', '-', '-', '%', '-', '-', '-', '-', '-', '%', '-', '%', '-', '-', '-', '%'], ['%', '%', '%', '%', '%', '-', '%', '-', '%', '-', '%', '%', '%', '%', '%', '%', '%', '%', '%', '-', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '-', '%', '-', '%', '%', '%'], ['%', '-', '-', '-', '%', '-', '%', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '%', '-', '%', '-', '-', '-', '-', '-', '%', '-', '-', '-', '%', '-', '%', '-', '-', '-', '%'], ['%', '-', '%', '%', '%', '-', '%', '%', '%', '%', '%', '-', '%', '%', '%', '%', '%', '%', '%', '%', '%', '-', '%', '%', '%', '%', '%', '-', '%', '-', '%', '-', '%', '%', '%', '-', '%'], ['%', '-', '%', '-', '-', '-', '%', '-', '-', '-', '-', '-', '-', '%', '-', '-', '-', '-', '-', '-', '-', '-', '%', '-', '-', '-', '-', '-', '%', '-', '-', '-', '-', '-', '-', '-', '%'], ['%', '-', '%', '-', '%', '-', '%', '%', '%', '%', '%', '-', '%', '%', '%', '-', '%', '-', '%', '-', '%', '-', '%', '-', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%'], ['%', '-', '%', '-', '%', '-', '-', '-', '%', '-', '-', '-', '-', '-', '%', '-', '%', '-', '%', '-', '%', '-', '-', '-', '-', '-', '-', '-', '%', '-', '-', '-', '%', '-', '%', '-', '%'], ['%', '-', '%', '-', '%', '%', '%', '-', '%', '%', '%', '-', '%', '-', '%', '-', '%', '-', '%', '%', '%', '%', '%', '%', '%', '%', '%', '-', '%', '%', '%', '-', '%', '-', '%', '-', '%'], ['%', '-', '%', '-', '-', '-', '%', '-', '%', '-', '-', '-', '%', '-', '%', '-', '%', '-', '-', '-', '%', '-', '%', '-', '-', '-', '%', '-', '%', '-', '%', '-', '-', '-', '-', '-', '%'], ['%', '-', '%', '%', '%', '-', '%', '%', '%', '-', '%', '%', '%', '%', '%', '-', '%', '%', '%', '-', '%', '-', '%', '-', '%', '%', '%', '%', '%', '-', '%', '-', '%', '%', '%', '%', '%'], ['%', '-', '-', '-', '-', '-', '-', '-', '%', '-', '-', '-', '%', '-', '-', '-', '-', '-', '%', '-', '%', '-', '-', '-', '-', '-', '%', '-', '-', '-', '%', '-', '%', '-', '-', '-', '%'], ['%', '%', '%', '-', '%', '-', '%', '%', '%', '%', '%', '-', '%', '%', '%', '%', '%', '-', '%', '%', '%', '-', '%', '%', '%', '-', '%', '-', '%', '%', '%', '-', '%', '-', '%', '%', '%'], ['%', '-', '%', '-', '%', '-', '%', '-', '%', '-', '%', '-', '%', '-', '%', '-', '-', '-', '-', '-', '%', '-', '%', '-', '-', '-', '%', '-', '%', '-', '-', '-', '%', '-', '%', '-', '%'], ['%', '-', '%', '-', '%', '%', '%', '-', '%', '-', '%', '-', '%', '-', '%', '-', '%', '%', '%', '%', '%', '%', '%', '%', '%', '-', '%', '-', '%', '-', '%', '-', '%', '-', '%', '-', '%'], ['%', '-', '-', '-', '%', '-', '-', '-', '%', '-', '-', '-', '%', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '%', '-', '-', '-', '-', '-', '%'], ['%', '-', '%', '-', '%', '-', '%', '-', '%', '%', '%', '-', '%', '%', '%', '-', '%', '%', '%', '%', '%', '%', '%', '-', '%', '%', '%', '-', '%', '%', '%', '-', '%', '%', '%', '-', '%'], ['%', '.', '%', '-', '%', '-', '%', '-', '-', '-', '-', '-', '-', '-', '%', '-', '-', '-', '%', '-', '-', '-', '-', '-', '-', '-', '%', '-', '-', '-', '%', '-', '%', '-', '-', 'P', '%'], ['%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%']]
    pacman = (35, 35)
    food = (35, 1)

    node = AStar(thing, pacman, food)

    file = open('test.txt', 'w')
    print(node.pathCost)
    file.write(str(node.pathCost))
    file.write('\n')
    pathToTake = []
    pathToTake.append(node.position)
    print(node.position)
    while node.parent:
        pathToTake.append(node.parent.position)
        node = node.parent
    while pathToTake:
        x = pathToTake.pop()
        file.write(''.join('%s %s' % x))
        file.write('\n')




#main()

import filecmp
filecmp.cmp('test.txt', 'check.txt')

"""file = open('test.txt', 'r')
file2 = open('check.txt', 'r')

m = file.readline()
n = file2.readline()

print(m)
print(n)

for line in file:
    m = file.readline()
    n = file2.readline()
    if (m == n):
        print("TRUE")"""
