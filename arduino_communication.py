import serial
import time

# Replace 'COM3' with your Arduino's serial port
ser = serial.Serial('COM5', 9600)
time.sleep(2)  # Wait for the serial connection to initialize

def get_matrix_value(row, col):
    if row < 0 or row >= 36 or col < 0 or col >= 36:
        raise ValueError("Row and column must be between 0 and 35 inclusive")
    
    ser.write(bytearray([row, col]))
    value = ser.read(1)
    return value[0]

try:
    row = int(input("Enter the row index (0-35): "))
    col = int(input("Enter the column index (0-35): "))
    
    value = get_matrix_value(row, col)
    print(f"The value at A[{row}][{col}] is {value}")

except ValueError as e:
    print(e)
finally:
    ser.close()
