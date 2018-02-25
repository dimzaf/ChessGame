import serial
import json
import pickle

MOVE_DONE = b'200'

class Board:
    xStepCm = 240 # step per cm on X axis
    yStepCm = 230 # step per cm on Y axis

    colWidthHeight = 5 # width & height of chessboard cell on cm

    xColSteps = xStepCm * colWidthHeight # calc width of cell in steps
    yColSteps = yStepCm * colWidthHeight # calc height of cell in steps

    xFirstColStart = xColSteps * 0  # # steps on X axis to reach first column from X start point (white space)
    yFirstColStart = yColSteps * 2 # steps on Y axis to reach first column from Y start point (white space)

    def __init__(self, com, boadrate=9600):
        self.board = serial.Serial(com, boadrate)

        # create X, Y axis list
        letters = []
        for letter in range(ord('A'), ord('H')+1):
            letters.append(chr(letter))

        # generate chessboard axis map with coordinates for each column center point
        self.axis = {}
        for x in letters:
          self.axis[x] = {}
          yCells = list(reversed(range(8)))
  
          for y in range(8):
            self.axis[x][y+1] = [letters.index(x) * xColSteps, yCells.index(y) * yColSteps]

    def get_crdn(startpoint , endpoint=False):
        crdn = {
            "start": self.axis[list(startpoint)[0]][int(list(startpoint)[1])],
            "end": self.axis[list(endpoint)[0]][int(list(endpoint)[1])] if endpoint else [-1, -1]
        }

        return json.dumps(crdn).encode('utf-8')

    def make_move(self, startpoint, endpoint=False):
        crdn = Board.get_crdn(startpoint , endpoint=False)
        arduino.write(crdn)
        time.sleep(1)

        while(arduino.readline() != MOVE_DONE):
            pass