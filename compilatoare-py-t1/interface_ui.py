'''Interface to manage expresion parsing'''

from tkinter import *
from interpreter import *
from turtle import *

X = ''
index=0

#make an empty window and setup geometry

root = Tk()
root.title('Parsing Interface')
root.geometry('1000x700+100+100') # width x height + x0 + y0


#make all widgets

buttonPanel = LabelFrame(root, text = 'Control Panel', width = 300)
buttonPanel.pack()

#define clearF callback
def clearF():
    global turtleScreen
    #resetStringVars to ''
    expStr.set('')
    resultStr.set('')
    turtleScreen.clear()
#enddef

clearButton = Button(buttonPanel, text = '    Clear    ', command = clearF)
clearButton.grid(row = 1, column = 1)

#define evalF callback
def evalF():
    #get the expression to parse
    text = expStr.get()

    lexer = Lexer(text)
    parser = Parser(lexer)
    #make aan interpreter
    inter = Interpreter(parser)
    
    #eval and put it in resultStr
    result = inter.interpret()
    resultStr.set(str(result))
#enddef

#define tokenF callback
def tokenF():
    #get the expression to parse
    text = expStr.get()

    lexer = Lexer(text)
    parser = Parser(lexer)
    #make aan interpreter
    inter = Interpreter(parser)

    #while possible, get next token and append it to tokenList
    tokenStr = str(parser.current_token) + '\n'

    while True:
        #get next token
        token = lexer.get_next_token()

        #append to tokenStr
        tokenStr += str(token) + '\n'

        if token.type == 'EOF' : break
    #endwhile

    resultStr.set(tokenStr)
#enddef

def tree(n, l):
    global index
    global X
    #print(str(i)+X[i])
    if n == 0 or l < 1: return
    turtleScreen.forward(30)
    turtleScreen.right(25)
 
    tree(n-1, l//2)
    turtleScreen.left(50)

    tree(n-1, l//2)
    turtleScreen.right(25)

    turtleScreen.pencolor("blue")
    turtleScreen.circle(3)
    turtleScreen.write(X[index], font=("Arial", 14, "bold"))
    turtleScreen.pencolor("black")
    index+=1

    turtleScreen.backward(30)   

#enddef

#define makeTree button function command
def makeTree(lenght):
    nr = 0
    while(nr>-1):
        nr += 1
        if pow(2,nr) >= lenght:
            break
    tree(lenght,pow(2,nr-1))
#enddef


##defin makeTokens button function command
def makeTokens():
    global X
    X = ''
    global index
    text = expStr.get()

    lexer = Lexer(text)

    parser = Parser(lexer)

    inter = Interpreter(parser)

    result = inter.interpret()

##    inter.parser.eTree.inorder()
    
    postorder(inter.parser.eTree)
    
    print(X)

    makeTree(len(X))
    index = 0
    
    
#enddef


#define postorder traversal function
def postorder(tree):
    global X
    if tree != None:
        postorder(tree.getLeftChild())
        postorder(tree.getRightChild())
        X += str(tree.getRootVal())
#enddef

        
#define makeExpressions button function command
def makeExpressions():
    text = expStr.get()
    lexer = Lexer(text)
    parser = Parser(lexer)
    inter = Interpreter(parser)
    
    result = inter.interpret()
    resultStr.set((inter.list)[-2::-1])
    f=open('expressions.txt','w')
    f.write((inter.list)[-2::-1])
#enddef 
    

    
treeButton = Button(buttonPanel, text = '    Make Tree    ', command = makeTokens)
treeButton.grid(row = 1, column = 4)

treeButton = Button(buttonPanel, text = '    Make expressions    ', command = makeExpressions)
treeButton.grid(row = 1, column = 5)

evalButton = Button(buttonPanel, text = '    Eval    ', command = evalF)
evalButton.grid(row = 1, column = 2)

tokenButton = Button(buttonPanel, text = '    Token    ', command = tokenF)
tokenButton.grid(row = 1, column = 3)


expPanel = LabelFrame(root, text = 'Parsing Panel', width = 300)
expPanel.pack()

expLabel = Label(expPanel, text = 'Expression')
expLabel.grid(row = 1, column = 1)

expStr = StringVar()
expEntry = Entry(expPanel, textvariable = expStr)
expEntry.grid(row = 1,column = 2, columnspan = 2)

resultStr = StringVar()
resultLabel = Label(expPanel, textvariable = resultStr)
resultLabel.grid(row = 2, column = 1, columnspan = 3)

w=Canvas(root,width=700,height=500)
w.pack()
turtleScreen=RawTurtle(w)
turtleScreen.pensize(3)
turtleScreen.penup()
turtleScreen.setx(-300)
turtleScreen.sety(20)
turtleScreen.pendown()

root.mainloop()
