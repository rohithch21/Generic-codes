
"""
read image
resize image
rotate image
gaussian blur
segmentation
edge detection
"""
import cv2
import numpy as np
import matplotlib.pyplot as plt
from skimage.filters import threshold_otsu

img = cv2.imread("D:/Rohith/Code/Python/lenna.png") # numpy array 2
#img2 = cv2.imread("/home/amrutha/rohith/.jpg")
cv2.imshow("images",img)
dim = img.shape
width = dim[0]
height = dim[1]
print(dim)
resized= cv2.resize(img,(int(width*0.5),int(height*0.5)))
print(resized.shape)
cv2.imshow("images2",resized)
img = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
cv2.imshow("gray",img)
print(img.shape)

blur = cv2.GaussianBlur(img, (5,5),cv2.BORDER_DEFAULT)
cv2.imshow("images3",blur)


edge = cv2.Canny(img,50,50)
cv2.imshow("edge",edge)


ret,seg = cv2.threshold(img,127,255,cv2.THRESH_BINARY) # returns binary image: binary segmentation
cv2.imshow("seg",seg)

threshold_value = threshold_otsu(img)
binary_image = img > threshold_value
print(binary_image.shape)
print(type(binary_image))
plt.imshow(binary_image, cmap = "gray")
plt.show()

cv2.waitKey(0)
cv2.destroyAllWindows()


#cv2.imshow("segmentation",seg)


 


