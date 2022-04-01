"""
Unique Features:
Comments
Any size grid
Add Least-Constraining Value

https://sudokudragon.com/sudokutheory.htm


NOTE: Matrix Convention
GREEDY SEARCH for least values
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

    def create_grid(self) -> None:

        def cross(A: list[str], B: list[str]) -> list[tuple]:
            return [(a, b) for a in A for b in B]

        cols = []
        rows = []

        for i in range(0, self.sideLength):
            cols.append(str(i))
            rows.append(str(i))

        # number of squares is sideLength^2
        self.squares = cross(cols, rows)

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

        """
        unitRows = [cross(c, rows) for c in cols]
        unitCols = [cross(cols, r) for r in rows]
        
        in a 3x3 box, it goes A1, B1, C1, A2, etc.
        unitBox = [cross(cs, rs) for cs in colPosition for rs in rowPosition]
        """
        self.unitList = (
                [cross(c, rows) for c in cols]
                +
                [cross(cols, r) for r in rows]
                +
                [cross(cs, rs) for cs in colPosition for rs in rowPosition]
                        )

        # all (x, y) positions, including key
        self.units = dict((square, [unit for unit in self.unitList if square in unit]) for square in self.squares)
        # all unique related (x,y) positions, not including key
        self.peers = dict((square, set(sum(self.units[square], [])) - set([square])) for square in self.squares)




    def fill_grid(self):
        """Convert grid to a dict of possible values, {square: digits}, or
            return False if a contradiction is detected."""
        ## To start, every square can be any digit; then assign values from the grid.

        values = dict((square, self.possibleValues) for square in self.squares)
        for square, digit in self.assign_grid_values().items():
            if digit in self.possibleValues and not self.solve_values(values, square, digit):
                return False  ## (Fail if we can't assign d to square s.)
        return values

    def assign_grid_values(self):
        "Convert grid into a dict of {square: char} with '0' or '.' for empties."
        chars = [char for char in self.grid if char in self.possibleValues or char in '0.']
        assert len(chars) == len(self.squares)
        return dict(zip(self.squares, chars))



    """
    This is mean value thingy, the original AI for the paper
    """

    def solve_values(self, values, square, digit):
        """Eliminate all the other values (except d) from values[s] and propagate.
        Return values, except return False if a contradiction is detected."""

        other_values = values[square].replace(digit, '')
        if all(self.eliminate_digit(values, square, digit2) for digit2 in other_values):
            return values
        else:
            return False



    def eliminate_digit(self, values, square, digit):
        """Eliminate d from values[s]; propagate when values or places <= 2.
        Return values, except return False if a contradiction is detected."""
        if digit not in values[square]:
            return values  ## Already eliminated
        values[square] = values[square].replace(digit, '')
        ## (1) If a square s is reduced to one value d2, then eliminate d2 from the peers.
        if len(values[square]) == 0:
            return False  ## Contradiction: removed last value
        elif len(values[square]) == 1:
            digit2 = values[square]
            if not all(self.eliminate_digit(values, square2, digit2) for square2 in self.peers[square]):
                return False

        ## (2) If a unit u is reduced to only one place for a value d, then put it there.
        for unit in self.units[square]:
            digitPlaces = [square for square in unit if digit in values[square]]
        if len(digitPlaces) == 0:
            return False  ## Contradiction: no place for this value
        elif len(digitPlaces) == 1:
            # d can only be in one place in unit; assign it there
            if not self.solve_values(values, digitPlaces[0], digit):
                return False
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