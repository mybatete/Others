from PIL import Image,ImageTk
from math import *
from commands import getoutput
from Tkinter import Tk,Canvas

layer_thickness = 7.5
contents = ["../B1run02_png/" + i for i in getoutput("ls ../B1run02_png/").split()]
stack = [Image.open(fn) for fn in contents]

#im = Image.open("/home/seth/B1run02_png/B1_Run02_BSED_slice_0176.png")
width, height = stack[0].size
print width, height
#
# pix = im.load()
#
current_image = 0

app = Tk()
canvas = Canvas(app)
canvas.pack()
canvas['width'] = 1280
canvas['height'] = 960
pimg = ImageTk.PhotoImage(image=stack[0])
canvas.create_image(0, 0, anchor='nw', image=pimg)
def changeimages(event, direction=1):
    global pimg, current_image
    current_image += direction
    if(current_image >= len(stack)):
        current_image = 0
    if(current_image < 0):
        current_image = len(stack)-1
    pimg = ImageTk.PhotoImage(image=stack[current_image])
    canvas.create_image(0, 0, anchor='nw', image=pimg)
canvas.bind("<Button-4>", changeimages)
canvas.bind("<Button-5>", lambda e : changeimages(e, -1))

def floodfill(event):
    img_x = event.x # ONLY when the image is anchored in the corner
    img_y = event.y

    frontier = [(img_x,img_y, current_image)];
    while len(frontier) > 0:
        img_x, img_y, ci = frontier.pop()
        neighbors = [
#                (img_x,img_y,      ci + 1), 
#                (img_x,img_y,      ci - 1),
                (img_x + 1,img_y,  ci),
                (img_x - 1,img_y,  ci),
                (img_x, img_y + 1, ci), 
                (img_x, img_y - 1, ci)]
        for n in neighbors:
            nx, ny, nz = n
            c = stack[nz].getpixel((nx, ny));
            if(c > 115 and c != 255):
                frontier.append(n)
                pix = stack[nz].load()
                pix[nx, ny] = 255
        print "Frontier:  ", len(frontier)

canvas.bind("<Button-1>", floodfill)

app.mainloop()










