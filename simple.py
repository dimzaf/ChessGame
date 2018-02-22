import cv2
 
# Camera 0 is the integrated web cam on my netbook
camera_port = 0
 
# Now we can initialize the camera capture object with the cv2.VideoCapture class.
# All it needs is the index to a camera port.
camera = cv2.VideoCapture(camera_port)
 
# Captures a single image from the camera and returns it in PIL format
def get_image():
 # read is the easiest way to get a full image out of a VideoCapture object.
 retval, im = camera.read()
 return im

print("Taking image...")

# Take the actual image we want to keep
camera_capture = get_image()
file = "test_image.png"

cv2.imwrite(file, camera_capture)
