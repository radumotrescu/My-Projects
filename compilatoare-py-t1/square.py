from turtle import *

#make a turtle and setup features
turtle = Turtle()
turtle.speed(0)

#make a drawing

def square(lenght):
    for i  in range(4):
        turtle.forward(lenght)
        turtle.left(90)
#enddef

def drawing(n):
    for i in range(n):
        square(50+2*i)
        turtle.left(360//n)
#enddef

def tree(n, l):
    if n == 0 or l < 3: return
    turtle.forward(l)
    turtle.left(45)
    tree(n-1, l//2)
    turtle.right(90)
    tree(n-1, l//2)
    turtle.left(45)
    turtle.circle(5)
    turtle.backward(l)
    
#endtree

def node():
    
    turtle.left(45);turtle.forward(100);turtle.backward(100)
    turtle.right(90);turtle.forward(100);turtle.backward(100)
