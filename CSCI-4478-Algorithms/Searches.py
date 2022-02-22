# TODO Nodes
# TODO Trees
# TODO Graphs
# TODO BFS
# TODO DFS Limited To Unlimited
# TODO UCS
# TODO Bidirectional Search
# TODO Greedy Best-First Search
# TODO Dijkstra's Algorithm
# TODO A* Search
# TODO MINIMAX Algorithm
# TODO Alpha-Beta Pruning
# TODO Time and Space Complexity

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

