#This problem uses BFS

import Searches

class CleanBot(Problem):
    def __init__(self, initial, goal, board):
        super(CleanBot, self).__init__(initial, goal)
        self.board = board

    def Actions(self):
        return

    def Result(self, state, action):  # Inheritance
        raise NotImplementedError

    def GoalTest(self, state):
        return state == state.goal  # TODO check if is list

    def PathCost(self, c, state1, action, state2):  # Inheritance
        return c + 1

    def Value(self, state):  # Inheritance
        raise NotImplementedError

board = [['b','-','-','-','d'],
         ['-','d','-','-','-',],
         ['-','-','d','-','d',],
         ['-','-','-','-','-',],
         ['-','-','-','-','d',],
         ]

x = Searches.Problem(board, None)