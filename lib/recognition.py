import os
import shutil
import time
import cv2
from lib import image_cutter
from lib import parser_tesseract

CHESS_IMAGE = "chessboard.jpg"
OUT_DIR = "out"
TESSERACT_DIR = "tesseract"

def take_picture():
    camera = cv2.VideoCapture(0)
    retval, image = camera.read()
    cv2.imwrite(CHESS_IMAGE, image)

def initialize(name):
    path = os.path.normpath(os.path.join(os.path.dirname(os.path.realpath(__file__)), '..', 'etc')) 
    os.chdir(path)

    # os.path.exists(CHESS_IMAGE) and os.unlink(CHESS_IMAGE) # remove old chessboard image
    os.path.exists(OUT_DIR) and shutil.rmtree(OUT_DIR) # remove old images

    # take_picture() # take current chessboard image

    time.sleep(3)

    image_cutter.cut_image(CHESS_IMAGE)

    parser_tesseract.parse()

def parse(name):    
    initialize(name)
    
    data = []
    for i in range(0,8):
        appendix = []
        for j in range(0,8):
            imagePath = os.path.join(OUT_DIR, "{0}_{1}.png".format(i, j))
            parsing = parser_tesseract.parse(imagePath)
            appendix.extend(parsing)

            if not parsing:
                appendix.append('0')

        data.append(appendix)
        
    return data
