from PIL import Image
import os
import string

OUT_DIR = "out"

def crop_image(path):
    """Crop the image around the board and saves it under OUTPUT.png"""
    img = Image.open(path)

    # rotate image
    img = img.rotate(90)

    width, height = img.size
    
    #actual values. Depends on webcam configuration
    left = 120
    right = width - 120
    top = height - 0
    bottom = 0
    
    bbox = [left, bottom, right, top]
    bbox = map(int, bbox)
    bbox = tuple(bbox)
    workingSlide = img.crop(bbox)
    workingSlide.save('output.png')

def cut_image(path):
    """Cut the image in 64 pieces after cropping it around the board"""
    crop_image(path)

    img = Image.open('output.png')
    width, height = img.size
    boxwidth = round(width/8)
    boxheight = round(height/8)

    not os.path.exists(OUT_DIR) and os.mkdir(OUT_DIR)

    letters = list(string.ascii_uppercase)[0:8]

    for y in range(0, 8):
        for x in range(0,8):
            left = x*boxwidth
            right = (x+1)*boxwidth
            if right>width:
                right = width
    
            up = y*boxheight
            bottom = (y+1)*boxheight
            if bottom>height:
                bottom = height
    
            bbox = [left, up, right, bottom]
            bbox = map(int, bbox)
            bbox = tuple(bbox)
            workingSlide = img.crop(bbox)
            workingSlide.save("out/{0}{1}.png".format(letters[x], 8-y))