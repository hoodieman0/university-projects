
# TODO Trees
# TODO Graphs
# TODO BFS
# TODO DFS Limited To Unlimited
# TODO UCS
# TODO Bidirectional Search
# TODO Greedy Best-First Search
# TODO Dijkstra's Algorithm
# TODO A* Search    (cost of getting to next node) + (hueristic of next node) + (cost to get to current node) or f(n) = h(n) + g(n)
# TODO MINIMAX Algorithm
# TODO Alpha-Beta Pruning
# TODO Time and Space Complexity

#Best First Search becomes different ones based on heuristic given

# b is branching factor
# m is maximum depth
# d is depth of shallowest goal

#From AI: A Modern Approach Fourth Edition
#https://github.com/aimacode/aima-python

class Node:
    def __init__(self, state, parent=None, action=None, pathCost=0):
        self.state = state                  #node's game state
        self.parent = parent                #previous game state
        self.action = action                #action taken to get to state
        self.pathCost = pathCost            #cost to get to this state
        self.depth = 0
        if parent:                          #how far in the tree node is
            self.depth = parent.depth + 1

    def Expand(self, problem):
        return [self.ChildNode(problem, action) for action in problem.Actions(self.state)]
                                            #return a list of all possible moves

    def ChildNode(self, problem, action):
        nextState = problem.result(self.state, action)
        nextNode = Node(nextState, self, action, 0)         #TODO make path costs here
        return nextNode

    def Path(self):
        node = self
        pathBack = []
        while node:
            pathBack.append(node)
            node = node.parent
        return list(reversed(pathBack))

    def IsSameNode(self, other):
        return isinstance(other, Node) and self.state == other.state



class Problem:
    def __init__(self, initial, goal=None):
        self.initial = initial
        self.goal = goal

    def Actions(self, state):                           #Inheritance
        raise NotImplementedError

    def Result(self, state, action):                    #Inheritance
        raise NotImplementedError

    def GoalTest(self, state):
        return state == state.goal                      #TODO check if is list

    def PathCost(self, c, state1, action, state2):      #Inheritance
        return c + 1

    def Value(self, state):                             #Inheritance
        raise NotImplementedError

class Graph:
    def __init__(self, graphDict=None, directed=False):
        self.graphDict = graphDict
        self.directed = directed
        if not self.directed:
            self.MakeUndirected()

    def MakeUndirected(self):
        for nodeA in list(self.graphDict.keys()):
            for (nodeB, distance) in self.graphDict[nodeA].items():  #TODO Rename Variable b
                self.ConnectOneWay(nodeB, nodeA, distance)

    def Connect(self, nodeA, nodeB, distance=1):
        self.ConnectOneWay(nodeA, nodeB, distance)
        if not self.directed:
            self.ConnectOneWay(nodeB, nodeA, distance)

    def ConnectOneWay(self, nodeA, nodeB, distance):
        self.graphDict.setdefault(nodeA, {})[nodeB] = distance

    def get(self, nodeA, nodeB=None):
        links = self.graphDict.setdefault(nodeA, {})
        if b is None:
            return links
        else:
            return links.Get(nodeB)

    def nodes(self):
        s1 = set([k for k in self.graphDict.keys()])
        s2 = set([k2 for v in self.graphDict.values() for k2, v2, in v.items()])
        nodes = s1.union(s2)
        return list(nodes)













def BreadthFirstSearch(problem):
    frontierQueue = []
    exploredList = []

    startNode = Node(problem.initial, None, None, 0)
    frontierQueue.append(startNode)

    while frontierQueue:
        node = frontierQueue.pop(0)
        exploredList.append(node)

        if problem.GoalTest(node.state):
            return node

        for childNode in node.Expand(problem):
            if childNode not in frontierQueue and childNode not in exploredList:
                frontierQueue.append(childNode)

    return None
