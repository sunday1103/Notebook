from tkinter import Tk, Label, Button, filedialog, Text
import tkinter

class MyFirstGUI:

    def __init__(self, master):
        self.master = master
        master.title("A simple GUI")
        self.file = 0

        self.label = Label(master, text="This is our first GUI!")
        self.label.pack()

        self.open_button = Button(master, text="Open", command=self.openFile)
        self.open_button.pack()

        self.send_button = Button(master, text="Send", command=self.Send)
        self.send_button.pack()

        self.save_button = Button(master, text="Save", command=self.Save)
        self.save_button.pack()

        self.close_button = Button(master, text="Close", command=master.quit)
        self.close_button.pack()


        self.text = Text(master)
        self.text.pack()

    def openFile(self):
        self.master.filename = filedialog.askopenfilename(initialdir="/", title="Select file",
                                               filetypes=(("txt files", "*.txt"), ("all files", "*.*")))
        print(self.master.filename)
        self.text.delete(1.0, tkinter.END)
        self.file = open(self.master.filename)
        for s in self.file.readlines():
            self.text.insert(tkinter.INSERT, s)

    def Save(self):
        pass
        #self.file.

    def Send(self):
        content = self.text.get(1.0, tkinter.END)
        content = str(content)
        lines = content.splitlines()
        print(content)

root = Tk()
my_gui = MyFirstGUI(root)
root.geometry("600x400")    # 设置窗口大小 注意：是x 不是*
root.mainloop()