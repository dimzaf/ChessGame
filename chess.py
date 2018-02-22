import serial
import json
import time
import pickle

arduino = serial.Serial('COM9', 9600) # init arduino devise to serial port
time.sleep(1)

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

data = json.dumps(move_pone('G4')).encode('utf-8')
arduino.write(data)

time.sleep(1)

while(int(arduino.readline()) != 200):
  pass

data = json.dumps(move_pone('E2', 'G4')).encode('utf-8')
arduino.write(data)

while(int(arduino.readline()) != 200):
  pass

time.sleep(4)

data = json.dumps(move_pone('E7', 'A8')).encode('utf-8')
arduino.write(data)