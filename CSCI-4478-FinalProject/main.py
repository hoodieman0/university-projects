"""
Added functionality to Peter Norvig's Sudoku Solver:
http://norvig.com/sudoku.html

Useful information about the sizes and theory of Sudoku:
https://sudokudragon.com/sudokutheory.htm

Proof that a 9x9 Sudoku puzzle needs at least 17 clues to be unique:
https://arxiv.org/pdf/1201.0749v2.pdf

Creates a class that can be any grid size sudoku puzzle (max is 61 x 61 square)
Additionally adds the heuristic of Least-Constraining Value to test its efficiency

NOTE: Matrix Convention that starts at (0,0)
NOTE: '0' or '.' is considered empty
"""
import sys
import time, random
import tests as unit_tests

max_values = '123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'


class AnySudoku:
    def __init__(self, column=3, row=3, grid='0'*81):
        self.column = column
        self.row = row
        self.grid = grid
        self.sideLength = row * column

        # due to representation limits, there is max amount of numbers that can be represented
        assert self.sideLength <= len(max_values)

        self.possibleValues = ''
        for i in range(0, self.sideLength):
            self.possibleValues = self.possibleValues + max_values[i]

        self.squares = None  # becomes list of tuples
        self.unitList = None  # becomes list of list[tuple]
        self.units = None  # becomes dict
        self.peers = None  # becomes dict

    # fills class variables squares, unitList, units, and peers
    # makes the grid in a dictionary representation
    def create_grid(self) -> None:

        # cross product of two values inputted, gives a list of grid coordinates back
        def cross(A: list[str], B: list[str]) -> list[tuple]:
            return [(a, b) for a in A for b in B]

        cols = []
        rows = []

        # populate the rows can columns with values
        for i in range(0, self.sideLength):
            cols.append(str(i))
            rows.append(str(i))

        # number of squares is sideLength^2
        # results in the squares having grid coordinates
        self.squares = cross(cols, rows)

        # this is where each box is formed from each column and row
        # could be its own function
        colPosition = []
        rowPosition = []
        temp = []
        for i in range(0, self.sideLength):
            temp.append(str(i))
            if (i + 1) % self.row == 0:
                colPosition.append(temp)
                temp = []

        temp = []
        for i in range(0, self.sideLength):
            temp.append(str(i))
            if (i + 1) % self.column == 0:
                rowPosition.append(temp)
                temp = []

        # links each square to the other squares in its row
        # unitRows = [cross(c, rows) for c in cols]

        # links each square to the other squares in its column
        # unitCols = [cross(cols, r) for r in rows]

        # in a 3x3 box, it goes A1, B1, C1, A2, etc.
        # links each square to its corresponding box
        # unitBox = [cross(cs, rs) for cs in colPosition for rs in rowPosition]
        self.unitList = (
                [cross(c, rows) for c in cols]
                +
                [cross(cols, r) for r in rows]
                +
                [cross(cs, rs) for cs in colPosition for rs in rowPosition]
                        )

        # all (x, y) positions, including key square
        self.units = dict((square, [unit for unit in self.unitList if square in unit]) for square in self.squares)
        # all unique related (x,y) positions, not including key square
        self.peers = dict((square, set(sum(self.units[square], [])) - set([square])) for square in self.squares)



    # puts all the possible final values into the dictionary
    def fill_grid(self) -> dict:
        # assigns all possible values into each square
        values = dict((square, self.possibleValues) for square in self.squares)

        # given the grid dictionary, check if we can assign one value to each square
        for square, digit in self.assign_grid_values().items():
            if digit in self.possibleValues and not self.solve_values(values, square, digit):
                # fail if we cant assign the digit to the square
                return False
        return values

    # puts a specific character in each square and returns the dictionary
    # this is taken from inputted grid
    def assign_grid_values(self) -> dict:
        chars = [char for char in self.grid if char in self.possibleValues or char in '0.']
        assert len(chars) == len(self.squares)
        return dict(zip(self.squares, chars))



    """
    solve_values() and eliminate_digit() are the original Constraint Propagation algorithms used by Peter Norvig
    """

    # tests if the digit is the correct value for the square by checking if it is possible to eliminate all other values
    # if there is a contradiction return False, otherwise return a dict of values
    def solve_values(self, values: dict, square: tuple, digit: str) -> dict:
        # all other digits other than the given digit
        other_values = values[square].replace(digit, '')

        # eliminate each value if possible
        if all(self.eliminate_digit(values, square, digit2) for digit2 in other_values):
            return values
        else:
            return False  # fail if the square cannot be assigned a value


    # take out a digit from a square and its peers based on a dict of values
    # if there is a contradiction return False, otherwise return a dict of values
    def eliminate_digit(self, values: dict, square: tuple, digit: str) -> dict:

        # is the digit already eliminated
        if digit not in values[square]:
            return values

        # remove the digit
        values[square] = values[square].replace(digit, '')

        # if a square has only one value left, remove it from its peers:

        # is there nothing in values left
        if len(values[square]) == 0:
            return False

        # if there is one value left, that is the value for the square
        elif len(values[square]) == 1:
            digit2 = values[square]

            # check if all the current square's peers can eliminate the value
            if not all(self.eliminate_digit(values, square2, digit2) for square2 in self.peers[square]):
                return False



        # if there is only one place for the digit in the unit, put it there
        # get all the squares where digit2 can be in the unit
        for unit in self.units[square]:
            digitPlaces = [square for square in unit if digit in values[square]]

        # if there are no places left for the digit in the unit, there is a contradiction
        if len(digitPlaces) == 0:
            return False

        # if there is one place left for the digit in the unit, check that it cannot be placed somewhere else
        elif len(digitPlaces) == 1:
            # d can only be in one place in unit; assign it there
            if not self.solve_values(values, digitPlaces[0], digit):
                return False

        # return the possible values with the digit eliminated
        return values

    def dfs_solve(self) -> dict:
        return self.depth_first_search(self.fill_grid())

    # try all possible values
    # heuristic chooses the square with the smallest amount of possible values and tries all values
    def depth_first_search(self, values: dict) -> dict:
        # if there is no possible eliminations, fail
        if values is False:
            return False

        # if there only one value for everything, the puzzle is solved
        if all(len(values[square]) == 1 for square in self.squares):
            return values

        # get the square with the least amount of possibilities
        n, s = min((len(values[square]), square) for square in self.squares if len(values[square]) > 1)
        return self.some(self.depth_first_search(self.solve_values(values.copy(), s, digit)) for digit in values[s])

    # return element of sequence that is true
    # prevents iterative recursive function from failing when one of its multiple calls is False
    def some(self, sequence):
        for element in sequence:
            if element:
                return element
        return False



    def lcvs_solve(self) -> dict:
        return self.least_constraining_values_search(self.fill_grid())

    # a backtracking algorithm that tries all possible values
    # heuristic assigns the digit that occurs the least in a unit to the square
    def least_constraining_values_search(self, values: dict) -> dict:
        # if there is no possible eliminations, fail
        if values is False:
            return False

        # if there only one value for everything, the puzzle is solved
        if all(len(values[square]) == 1 for square in self.squares):
            return values

        # hash map for the least value
        valueSeen = dict((a, 0) for a in self.possibleValues)

        # get a square
        for square in self.squares:
            # if the square has only one value, skip it
            if len(values[square]) == 1:
                continue
            # get the peers associated with the square
            for peer in self.peers[square]:
                # if the square has a value, skip it
                if len(values[peer]) == 1:
                    continue
                # for each possible value in the square
                for char in values[peer]:
                    # increase how many times it was seen by 1
                    valueSeen[char] = valueSeen[char] + 1

            # filler value for loop
            valueSeen['0'] = 100000000000
            least_constraining_value = '0'
            # this loop gets the minimum value that is seen at least 1 time
            for v in valueSeen:
                if valueSeen[v] == 0:
                    continue
                if valueSeen[v] < valueSeen[least_constraining_value]:
                    least_constraining_value = v

            for unit2 in self.units[square]:
                return self.some(self.least_constraining_values_search(self.solve_values(values.copy(), square2, least_constraining_value)) for square2 in unit2)



    # takes a dictionary of a sudoku puzzle and shows it in a 2D grid
    # this one is easier to understand which values are unknown
    def display(self, values: dict) -> None:
        # row divider length
        line = '+'.join(['-' * self.column] * self.row)
        for c in range(0, self.sideLength):
            print(''.join('(' + values[(str(c), str(r))] + ')'
                          + ('|' if (r+1) % self.column == 0 and not (r+1) == self.sideLength else '')
                          for r in range(0, self.sideLength)))

            if ((c+1) % self.row == 0) and not (c+1) == self.sideLength:
                print(line)

        print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")

    # takes a dictionary of a sudoku puzzle and shows it in a 2D grid
    # this one is a polished version of display()
    def display_final(self, values: dict) -> None:
        # row divider length
        if not values:
            print("Sudoku Not Solvable!")
            return

        line = '+ '.join(['- ' * self.column] * self.row)
        for c in range(0, self.sideLength):
            print(' '.join(values[(str(c), str(r))]
                           + (' |' if (r+1) % self.column == 0 and not (r+1) == self.sideLength else '')
                           for r in range(0, self.sideLength)))
            if ((c+1) % self.row == 0) and not (c+1) == self.sideLength:
                print(line)

        print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")






    # solve a sequence of grids using a Depth-First Search
    # showif is in seconds
    def solve_all_dfs(self, grids: list[str], name='', showif=0.0):

        def time_solve(grid):
            self.grid = grid
            start = time.time()
            values = self.dfs_solve()
            t = time.time() - start

            # display puzzles that are over showif seconds
            if showif is not None and t > showif:
                self.display_final(self.assign_grid_values())
                if values: self.display(values)
                print('(%.2f seconds)\n' % t)
            return t, self.solved(values)

        times, results = zip(*[time_solve(grid) for grid in grids])
        N = len(grids)
        if N > 1:
            print("Solved %d of %d %s puzzles (avg %.2f secs (%d Hz), max %.2f secs)." % (
                sum(results), N, name, sum(times) / N, N / sum(times), max(times)))

    def solve_all_lcvs(self, grids, name='', showif=0.0):
        """Attempt to solve a sequence of grids. Report results.
        When showif is a number of seconds, display puzzles that take longer.
        When showif is None, don't display any puzzles."""

        def time_solve(grid):
            self.grid = grid
            start = time.time()
            values = self.lcvs_solve()
            t = time.time() - start
            # display puzzles that are over showif seconds
            if showif is not None and t > showif:
                self.display_final(self.assign_grid_values())
                if values: self.display(values)
                print('(%.2f seconds)\n' % t)
            return t, self.solved(values)

        times, results = zip(*[time_solve(grid) for grid in grids])
        N = len(grids)
        if N > 1:
            print("Solved %d of %d %s puzzles (avg %.2f secs (%d Hz), max %.2f secs)." % (
                sum(results), N, name, sum(times) / N, N / sum(times), max(times)))


    def solved(self, values: dict) -> bool:
        def unitsolved(unit):
            return set(values[s] for s in unit) == set(self.possibleValues)
        # checks if both values exists and its units all have on of each possibleValue
        return values is not False and all(unitsolved(unit) for unit in self.unitlist)

    def from_file(self, filename: str, sep='\n') -> list[str]:
        # reads a file, returns a list of strings for each puzzle, separated by sep
        file = open(filename, 'r')
        return file.read().strip().split(sep)

    # returns a randomized puzzle string with at least numSquaresAssigned, restart on contradictions
    # all puzzles are not guaranteed to be solvable, some have multiple solutions
    def random_puzzle(self, numSquaresAssigned=1) -> str:
        # create a grid where any square can be any value
        values = dict((square, self.possibleValues) for square in self.squares)
        for square in self.shuffled(self.squares):
            if not self.solve_values(values, square, random.choice(values[square])):
                break
            ds = [values[square] for square in self.squares if len(values[square]) == 1]
            if len(ds) >= numSquaresAssigned:
                return ''.join(values[square] if len(values[square]) == 1 else '0' for square in self.squares)
        return self.random_puzzle(numSquaresAssigned)  ## Give up and make a new puzzle

    # randomizes the input seq
    def shuffled(self, seq):

        seq = list(seq)
        random.shuffle(seq)
        return seq

if __name__ == '__main__':
    unit_tests.create_grid_check_correct_dictionary()
    print()


    """
    z = AnySudoku(3, 2, '0'*36)
    z.create_grid()
    z.grid = z.random_puzzle(14)
    z.display_final(z.assign_grid_values())
    z.display_final(z.dfs_solve())
    z.display_final(z.lcvs_solve())
    print(z.dfs_solve() == z.lcvs_solve())
    """

    """
    x = AnySudoku(4, 4, '50F0000C40000G0703000705G0E000907E4020B00D0C01A000C8G00D7009460E0B000050080000G09503D200A0FG8000G000080E10400003A0D40G01C0B0950FC09A05063070EB0110000B07209000040F0D130000G650C9070000900B0000600037B000900FDE0A6A1050200G08097009000A08B02000F040G0000F60000208')
    x.create_grid()
    x.display_final(x.assign_grid_values())
    x.display_final(x.dfs_solve())
    """

    """
    x = AnySudoku(3, 2, '103040060203040301302460201050050102')
    x.create_grid()
    x.display_final(x.assign_grid_values())
    print("DFS Solve")
    x.display_final(x.dfs_solve())
    print("LCVS Solve")
    x.display_final(x.lcvs_solve())
    print(x.dfs_solve() == x.lcvs_solve())
    """


    """
    y = AnySudoku(3, 3, '003020600900305001001806400008102900700000008006708200002609500800203009005010300')
    y.create_grid()
    # x.display_final(x.assign_grid_values())
    print("DFS Solve")
    y.display_final(y.dfs_solve())
    print("LCVS Solve")
    y.display_final(y.lcvs_solve())
    print(y.dfs_solve() == y.lcvs_solve())
    """