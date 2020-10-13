from tkinter import *
#Simple Calculator using Tkinter in Python

def click(event):
    global scrval
    text = event.widget.cget("text")
    if text == "=":
        if scrval.get().isdigit():
            value = int(scrval.get())
        else:
            value = eval(screen.get())
        scrval.set(value)

    elif text == "C":
        scrval.set("")
        screen.update()
    else:
        scrval.set(scrval.get() + text)
        screen.update()


root=Tk()
root.geometry("500x550")
root.title("GUI Simple Calculator")

scrval = StringVar()
scrval.set("")

screen = Entry(root, textvar=scrval, font="lucida 30 bold", bd=4,relief=SUNKEN)
screen.pack()

frame = Frame(root, bg="grey", pady=10)
list1 = ["7", "8", "9", "C", "4", "5", "6", "+", "1", "2", "3", "-" ,".", "0", "=", "*", "%", "!", "^", "/"]
i = 0
for n in list1:
    # here width of button means 1 text width
    btn = Button(frame, text=n, font="lucida 20 bold", padx=50, width =1,pady=25 )
    btn.grid(row=int(i / 4), column=i % 4)
    i = i + 1

    btn.bind("<Button-1>", click)
frame.pack(fill=X)

root.mainloop()
