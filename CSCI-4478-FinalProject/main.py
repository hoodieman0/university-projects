"""
Unique Features:
Comments
Any size grid
Add Least-Constraining Value

https://sudokudragon.com/sudokutheory.htm


NOTE: Matrix Convention that starts at (0,0) because I can't fix an error
GREEDY SEARCH for least values
Uhh I added max values because 1. too much run time and 2. it had some implementation errors with the CSP
'0' or '.' is considered empty
"""
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

        self.squares = None
        self.unitList = None
        self.units = None
        self.peers = None



    # fills class variables squares, unitList, units, and peers
    # makes the grid in a dictionary representation
    def create_grid(self) -> None:

        # cross product of two values inputted, gives a list of grid coordinates back
        def cross(A: list[str], B: list[str]) -> list[tuple]:
            return [(a, b) for a in A for b in B]

        cols = []
        rows = []

        # populate the rows can columns with values
        for i in range(0, self.sideLength):  # TODO get cells to be represented starting at (1,1)
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

        # if a square has only one value left, remove it from its peers

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
        # get all the places where digit2 can be in the unit
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
        line = '+ '.join(['- ' * self.column] * self.row)
        for c in range(0, self.sideLength):
            print(' '.join(values[(str(c), str(r))]
                           + (' |' if (r+1) % self.column == 0 and not (r+1) == self.sideLength else '')
                           for r in range(0, self.sideLength)))

            if ((c+1) % self.row == 0) and not (c+1) == self.sideLength:
                print(line)

        print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")

if __name__ == '__main__':
    unit_tests.create_grid_check_correct_dictionary()
    print()

    x = AnySudoku(3, 2, '103040060203040301302460201050050102')
    x.create_grid()
    x.display_final(x.assign_grid_values())
    x.display(x.fill_grid())

    y = AnySudoku(7, 5, '0'*1225)
    y.create_grid()
    y.display_final(y.assign_grid_values())