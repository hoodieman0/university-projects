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
#print(len(list))
#for i in list[1]:
#    print(i)

def next_move(posy, posx, lovelyList):
    while (posy > 0):
        posy -= 1
        print("Up")
    while (posx > 0):
        posx -= 1
        print("Left")

    row = 0
    column = 0
    while row < len(list):
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

def moveToLocation(lovelyList, currentX, currentY, newX, newY): #CostFunction, have it go back and forth if set in middle of row

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

def dirtLocator(lovelyList, row): #this is the place for search
    xLocation = 0
    for char in lovelyList[row]:
        if char == 'd':
            dirtX = xLocation
            return dirtX, row
        xLocation += 1
    raise Exception("\n~No Dirt Found~\n")

next_move(0, 0, list)