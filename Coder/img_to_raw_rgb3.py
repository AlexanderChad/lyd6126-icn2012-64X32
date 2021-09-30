import tkinter as tk
from tkinter import filedialog
import numpy as np
from PIL import Image

root = tk.Tk()
root.withdraw()

img_path = filedialog.askopenfilename(filetypes=(("Image files", "*.png;*.jpg;*.jpeg;*.bmp"),("All files", "*.*")))
img = Image.open(img_path)
x, y = img.size
obj = img.load()

raw_rgb3_uint8 = np.zeros((3,256),dtype=('uint8'))

adr = np.zeros(32,dtype=('uint8'))
adr=[8,0,9,1,10,2,11,3,12,4,13,5,14,6,15,7]

for yi in range(y):
    for xi in range(x):
        r, g, b = obj[xi,yi]
        obj[xi,yi] = ((r > 0) * 255,(g > 0) * 255,(b > 0) * 255)

def WriteByte(xi, yi, int_y):
    r, g, b = obj[xi,yi]
    if (r > 0):
        raw_rgb3_uint8[0][int_y*8+(xi//8)] |= (1 << (xi-8*(xi//8)))
    if (g > 0):
        raw_rgb3_uint8[1][int_y*8+(xi//8)] |= (1 << (xi-8*(xi//8)))
    if (b > 0):
        raw_rgb3_uint8[2][int_y*8+(xi//8)] |= (1 << (xi-8*(xi//8)))

    r, g, b = obj[xi,yi+16]
    if (r > 0):
        raw_rgb3_uint8[0][int_y*8+(xi//8)+128] |= (1 << (xi-8*(xi//8)))
    if (g > 0):
        raw_rgb3_uint8[1][int_y*8+(xi//8)+128] |= (1 << (xi-8*(xi//8)))
    if (b > 0):
        raw_rgb3_uint8[2][int_y*8+(xi//8)+128] |= (1 << (xi-8*(xi//8)))




int_y=0
for yi in adr:
    for xi in range(x):
        WriteByte(xi, yi, int_y)
    int_y+=1


img.show()


raw_path = img_path + '.to_MC_3bit'
print("Массив rgb3 для MC:")
for i in range(3):
    print('\n')
    for j in range(64):
        print(str(format(raw_rgb3_uint8[i,j], 'b')))

file = open(raw_path, 'w')
for i in range(3):
    for j in range(256):
        if ((j == 0) & (i == 0)) :
            file.write(str(raw_rgb3_uint8[i,j]))
        else :
            file.write(',' + str(raw_rgb3_uint8[i,j]))
file.close()
print("Сохранено в файл: ", raw_path)

input()