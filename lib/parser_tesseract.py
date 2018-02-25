import os
import time

#path = os.path.dirname(os.path.realpath(__file__))
#os.chdir(path)

def get_file_result(path):
    with open (path, "r") as f:
        lines = f.read().splitlines()
    return lines

def parse(path):
    """Character recognition of the image"""
    os.system("tesseract {0} tesseract_out.txt".format(path))
    text = get_file_result('tesseract_out.txt')
    text = filter(None, text)

    return text