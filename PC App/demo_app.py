import serial
import tkinter as tk

# Replace 'COM3' with your Arduino port
port = '/dev/cu.usbmodem2017_2_251'
baudrate = 9600

# Function to send data to Arduino
def send_to_arduino(data):
  ser.write(data.encode('utf-8'))
  print(f"Sent: {data}")

# Initialize serial connection
ser = serial.Serial(port, baudrate)


# Create the main window
window = tk.Tk()
window.title("Send Data to Arduino")

# Entry field for user input
entry_field = tk.Entry(window)
entry_field.pack()

# Button to send data
send_button = tk.Button(window, text="Send", command=lambda: send_to_arduino(entry_field.get()))
send_button.pack()

# Run the main event loop
window.mainloop()
