import tkinter as tk
from PIL import Image, ImageTk

FONT = ('Menlo', 14, 'bold')

usernames = ['prashant', 'sahil', 'ishan', 'sunny', 'priyanshu','doctor', 'patient']
passwords = ['prashant123', 'sahil123', 'ishan123', 'sunny123', 'priyanshu123','password', 'patientpass']
def login_fun(user, passwd):
    for i in range(int(len(usernames))):
        if user == usernames[i] and passwd == passwords[i]:
            print("hehe boi")
            return True
    print("Invalid")
    return False 
    

window = tk.Tk()
window.title("Vend-Aid Login")
window.resizable(False, False)

logo = Image.open("subject.png")
logo = logo.resize((200,200))
img_1 = ImageTk.PhotoImage(logo, size='400x400')
img_label = tk.Label(image=img_1)
img_label.grid(row=0, column=0, columnspan=2)

username = tk.StringVar()
username_label = tk.Label(text="Username: ", font=FONT)
username_label.grid(row=1, column=0)

username_entry = tk.Entry(textvariable=username, font=FONT)
username_entry.grid(row=1, column=1)

password = tk.StringVar()
password_label = tk.Label(text = "Password: ", font=FONT)
password_label.grid(row=2, column=0)

password_entry = tk.Entry(textvariable=password, show="*", font=FONT)
password_entry.grid(row=2, column=1)

login = tk.Button(window, text="Login", anchor='center', font=FONT, command=lambda:login_fun(username.get(), password.get()))
login.grid(row=3, column=0, columnspan=2, sticky='we')

signup = tk.Button(window, text="Signup", anchor='center', font=FONT)
signup.grid(row=4, column=0, columnspan=1, sticky='we')

forgot_password = tk.Button(window, text="Forgot Password", anchor='center', font=FONT)
forgot_password.grid(row=4, column=1, columnspan=1, sticky='we')

window.mainloop()
