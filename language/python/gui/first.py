from tkinter import Tk, Label, Button, filedialog, Text, Entry
import tkinter

class MyFirstGUI:

    def __init__(self, master):
        self.master = master
        master.title("A simple Telnet Client")
        self.file = 0
        self.ip = '192.168.172.90'
        self.port = 40001
        self.timeout = 1

        help = '''
使用说明：
1. 打开待发送文本,
   在右侧查看脚本是否正确
2. 更改脚本或者直接发送
注意：
脚本需要使用utf-8编码
        '''
        self.ipLabel = Label(master, text="串口服务器IP：")
        self.ipLabel.config(justify=tkinter.LEFT)
        self.portLabel = Label(master, text="需要发送板子Port：")
        self.timeoutlable = Label(master, text="发送间隔(s)：")
        self.ipEntry = Entry(master)
        self.ipEntry.insert(0, "192.168.172.90")
        self.portEntry = Entry(master)
        self.portEntry.insert(0, "40001")
        self.timeoutEntry = Entry(master)
        self.timeoutEntry.insert(0, "1")

        self.ipLabel.grid(row=0, column=0)
        self.ipEntry.grid(row=1, column=0)
        self.portLabel.grid(row=2, column=0)
        self.portEntry.grid(row=3, column=0)
        self.timeoutlable.grid(row=4, column=0)
        self.timeoutEntry.grid(row=5, column=0)

        self.label = Label(master, text=help)
        self.label.config(justify=tkinter.LEFT)
        self.label.grid(row=6, column=0)

        self.open_button = Button(master, text="Open", command=self.openFile)
        self.open_button.grid(row=0, column=1)

        self.send_button = Button(master, text="Send", command=self.Send)
        self.send_button.grid(row=0, column=2)

        self.save_button = Button(master, text="Save", command=self.Save)
        self.save_button.grid(row=0, column=3)

        self.close_button = Button(master, text="Close", command=master.quit)
        self.close_button.grid(row=0, column=4)

        self.text = Text(master)
        self.text.grid(row=1, column=1,columnspan=5, rowspan=10)

    def openFile(self):
        self.master.filename = filedialog.askopenfilename(initialdir="/", title="Select file",
                                               filetypes=(("txt files", "*.txt"), ("all files", "*.*")))
        print(self.master.filename)
        self.text.delete(1.0, tkinter.END)
        self.file = open(self.master.filename, encoding= 'utf-8')
        for s in self.file.readlines():
            self.text.insert(tkinter.INSERT, s)

    def Save(self):
        content = self.text.get(1.0, tkinter.END)
        fileWrite = open(self.master.filename, 'w', encoding= 'utf-8')
        fileWrite.write(content)
        fileWrite.close()

    def Send(self):
        self.ip = self.ipEntry.get()
        self.port = int(self.portEntry.get())
        self.timeout = int(self.timeoutEntry.get())
        print(self.ip, self.port, self.timeout)
        content = self.text.get(1.0, tkinter.END)
        content = str(content)
        lines = content.splitlines()
        print(content)

root = Tk()
my_gui = MyFirstGUI(root)
root.geometry("600x400")    # 设置窗口大小 注意：是x 不是*
root.mainloop()