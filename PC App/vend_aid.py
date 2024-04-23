import serial
import tkinter as tk

# __dev__ port 
port = '/dev/cu.usbmodem2017_2_251'
serialRate = 9600

# function to send data to Arduino
def send_to_arduino(data : list):
  for i in data:
    ser.write(i.encode('utf-8'))
    print(f"Sent: {i}")

# medicine list 
medicines = []
def save_medicine(data, medicines, qty):
  for i in range(qty):
    medicines.append(data)

# __init__ serial connection
ser = serial.Serial(port, serialRate)

# __init__ tkinter window 
window = tk.Tk()
window.title("Doctor portal")
window.resizable(False,False)

# title of the app
title = tk.Label(window, text="Vend-Aid: Doctor Portal")

# 1. first medicine
med_1 = tk.Label(window, text="Paracetamol: ")
med_1.grid(row=1, column=0)

# 
med_qty_frame = tk.Frame(window)
med_qty_frame.grid(row=1, column=1)

qty_a = tk.IntVar()

qty_a_minus = tk.Button(med_qty_frame, text="-", command = lambda: qty_a.set(qty_a.get()-1))
qty_a_minus.grid(row=0, column=0)

med_1_entry = tk.Entry(med_qty_frame, textvariable = qty_a)
med_1_entry.grid(row=0, column=1)

qty_a_plus = tk.Button(med_qty_frame, text="+", command = lambda: qty_a.set(qty_a.get()+1))
qty_a_plus.grid(row=0, column=2)

# 
med_1_verify = tk.Button(window, text="Verify", command = lambda: save_medicine('a', medicines, qty_a.get()))
med_1_verify.grid(row=1, column=2)

# 2. second medicine
med_2 = tk.Label(window, text="Ofloxacin: ")
med_2.grid(row=2, column=0)

qty_b = tk.IntVar()
med_2_entry = tk.Entry(window, textvariable = qty_b)
med_2_entry.grid(row=2, column=1)

med_2_verify = tk.Button(window, text="Verify", command = lambda: save_medicine('b', medicines, qty_b.get()))
med_2_verify.grid(row=2, column=2)

# 3. third medicine
med_3 = tk.Label(window, text="Azithromycin: ")
med_3.grid(row=3, column=0)

qty_c = tk.IntVar()
med_3_entry = tk.Entry(window, textvariable = qty_c)
med_3_entry.grid(row=3, column=1)

med_3_verify = tk.Button(window, text="Verify", command = lambda: save_medicine('c', medicines, qty_c.get()))
med_3_verify.grid(row=3, column=2)

# 4. vend items button
vend = tk.Button(window, text="Vend items", command= lambda: send_to_arduino(medicines), anchor="center")
vend.grid(row=3, column=1, columnspan=3, sticky="w")

# __iter__ tkinter window 
window.mainloop()
