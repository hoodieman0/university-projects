"""
Unique Features:
Comments
Any size grid
Add Least-Constraining Value

https://sudokudragon.com/sudokutheory.htm


NOTE: Matrix Convention
"""
import tests as unit_tests

class AnySudoku:
    def __init__(self):
        self.sideLength = None
        self.squares = None
        self.unitList = None
        self.units = None
        self.peers = None

    def create_grid(self, row: int, col: int) -> None:

        def cross(A: list[int], B: list[int]) -> list[tuple]:
            return [(a, b) for a in A for b in B]

        self.sideLength = row * col
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
            if (i + 1) % row == 0:
                colPosition.append(temp)
                temp = []

        temp = []
        for i in range(0, self.sideLength):
            temp.append(str(i))
            if (i + 1) % col == 0:
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

if __name__ == '__main__':
    unit_tests.create_grid_check_correct_dictionary()