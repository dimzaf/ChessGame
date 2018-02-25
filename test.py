import serial
import time
import copy
from lib import sunfish as ai

MOVE_MADE = 1
MOVE_UNDO = 2

#arduino = serial.Serial("COM9", 9600, timeout=1)
#time.sleep(2)
#arduino.flushInput()

xStepCm = 240 # step per cm on X axis
yStepCm = 230 # step per cm on Y axis

colWidthHeight = 5 # width & height of chessboard cell on cm

xColSteps = xStepCm * colWidthHeight # calc width of cell in steps
yColSteps = yStepCm * colWidthHeight # calc height of cell in steps

xFirstColStart = xColSteps * 0  # # steps on X axis to reach first column from X start point (white space)
yFirstColStart = yColSteps * 2 # steps on Y axis to reach first column from Y start point (white space)

# create X, Y axis list
letters = []
for letter in range(ord('A'), ord('H')+1):
    letters.append(chr(letter))

# generate chessboard axis map with coordinates for each column center point
XY = {}
for x in letters:
  XY[x] = {}
  yCells = list(reversed(range(8)))
  
  for y in range(8):
    XY[x][y+1] = [letters.index(x) * xColSteps, yCells.index(y) * yColSteps]
    
# move pone to XY axis
def move_pone(startpoint , endpoint=False):
  return {
    "start": XY[list(startpoint)[0]][int(list(startpoint)[1])],
    "end": XY[list(endpoint)[0]][int(list(endpoint)[1])] if endpoint else [-1, -1]
}

def main():    
    #initialization of the chessboard
    pos = ai.Position(ai.initial,0,(True,True),(True,True),0,0)
    searcher = ai.Searcher()

    prevPos = copy.deepcopy(pos)

    print('Make a move, then press button')

    while True:
        # data=arduino.readline()
        data = input('arduino move made ? ')

        if(int(data) == MOVE_MADE):
            print(' '.join(pos.board))

            crdn = input("Your move: ")

            try:
                move = ai.parse(crdn[0:2]), ai.parse(crdn[2:4])
            except ValueError:
                print("Invalid Move !")

            if move not in pos.gen_moves():
                print("Invalid Move")
            else:
                print("You moved  a: ", pos.board[move[0]])

                #check if there is a piece on the place where the new piece is
                #being moved
                if (pos.board[move[1]] != '.'):
                    print("you just destroyed my :" + pos.board[move[1]])

                prevPos = copy.deepcopy(pos) 
                pos = pos.move(move)

                # After our move we rotate the board and print it again.
                # This allows us to see the effect of our move.
                print(' '.join(pos.rotate().board))

                # Fire up the engine to look for a move.
                move, score = searcher.search(pos)
                if score <= -ai.MATE_VALUE:
                    print("You won")
                    break
                if score >= ai.MATE_VALUE:
                    print("You lost")
                    break

                # The black player moves from a rotated position, so we have to
                # 'back rotate' the move before printing it.
                print("My move:", ai.render(119-move[0]) + ai.render(119-move[1]))

                print("Ai moved a: ",pos.board[move[0]])
                lastMovedPiece = pos.board[move[0]]

                if (pos.board[move[1]] != '.'):
                    print("I just destroyed your :" + pos.board[move[1]])

                pos = pos.move(move)
                print(' '.join(pos.board))

                movement = ai.render(119-move[0]) + ai.render(119-move[1])
                # arduino.write()

        elif (data == MOVE_UNDO):
            #player used undo
            pos = copy.deepcopy(prevPos)
            print(' '.join(pos.board))

main()