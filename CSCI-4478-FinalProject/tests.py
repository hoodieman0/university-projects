import unittest
import main


def create_grid_check_correct_dictionary():
    #Unit test to make sure main.create_grid() makes correct values

    grid1 = main.AnySudoku(3, 3)
    grid1.create_grid()

    assert len(grid1.squares) == 81
    assert len(grid1.unitList) == 27
    assert all(len(grid1.units[s]) == 3 for s in grid1.squares)
    assert all(len(grid1.peers[s]) == 20 for s in grid1.squares)
    assert grid1.units[('1', '2')] == [
        [('1', '0'), ('1', '1'), ('1', '2'), ('1', '3'), ('1', '4'), ('1', '5'), ('1', '6'), ('1', '7'), ('1', '8')],
        [('0', '2'), ('1', '2'), ('2', '2'), ('3', '2'), ('4', '2'), ('5', '2'), ('6', '2'), ('7', '2'), ('8', '2')],
        [('0', '0'), ('0', '1'), ('0', '2'), ('1', '0'), ('1', '1'), ('1', '2'), ('2', '0'), ('2', '1'), ('2', '2')]
    ]
    assert grid1.peers[('1', '2')] == set(
        [('0', '0'), ('1', '0'), ('2', '0'), ('0', '1'), ('1', '1'), ('2', '1'), ('0', '2'), ('2', '2'), ('3', '2'),
         ('4', '2'), ('5', '2'), ('6', '2'), ('7', '2'), ('8', '2'), ('1', '3'), ('1', '4'), ('1', '5'), ('1', '6'),
         ('1', '7'), ('1', '8')])

    grid2 = main.AnySudoku(3, 2)
    grid2.create_grid()

    assert len(grid2.squares) == 36
    assert len(grid2.unitList) == 18
    assert all(len(grid2.units[s]) == 3 for s in grid2.squares)
    assert all(len(grid2.peers[s]) == 12 for s in grid2.squares)
    assert grid2.units[('2', '5')] == [
        [('2', '0'), ('2', '1'), ('2', '2'), ('2', '3'), ('2', '4'), ('2', '5')],
        [('0', '5'), ('1', '5'), ('2', '5'), ('3', '5'), ('4', '5'), ('5', '5')],
        [('2', '3'), ('2', '4'), ('2', '5'), ('3', '3'), ('3', '4'), ('3', '5')]
    ]
    assert grid2.peers[('2', '5')] == set(
        [('2', '0'), ('2', '1'), ('2', '2'), ('2', '3'), ('2', '4'), ('0', '5'), ('1', '5'), ('3', '5'), ('4', '5'),
         ('5', '5'), ('3', '3'), ('3', '4')])

    print('~Correct Dictionary Values~')
