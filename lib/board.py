import serial
import json
import pickle
import time

MOVE_DONE = 1

class Board:
    def __init__(self, com, boadrate=9600):
        self.board = serial.Serial(com, boadrate)

        time.sleep(1)

        self.xStepCm = 240 # step per cm on X axis
        self.yStepCm = 230 # step per cm on Y axis

        self.colWidthHeight = 5 # width & height of chessboard cell on cm

        self.xColSteps = self.xStepCm * self.colWidthHeight # calc width of cell in steps
        self.yColSteps = self.yStepCm * self.colWidthHeight # calc height of cell in steps

        self.xFirstColStart = self.xColSteps * 0  # # steps on X axis to reach first column from X start point (white space)
        self.yFirstColStart = self.yColSteps * 2 # steps on Y axis to reach first column from Y start point (white space)

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
            self.axis[x][y+1] = [letters.index(x) * self.xColSteps, yCells.index(y) * self.yColSteps]

    def get_crdn(self, startpoint , endpoint=False):
        crdn = {
            "start": self.axis[list(startpoint)[0]][int(list(startpoint)[1])],
            "end": self.axis[list(endpoint)[0]][int(list(endpoint)[1])] if endpoint else [-1, -1]
        }

        return json.dumps(crdn).encode('utf-8')

    def make_move(self, startpoint, endpoint=False):
        crdn = self.get_crdn(startpoint , endpoint)

        self.board.write(crdn)
        time.sleep(1)

        while(int(self.board.readline()) != MOVE_DONE):
            pass