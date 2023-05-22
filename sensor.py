import time
import serial
import pyautogui
 
# Iniciando conexao serial bluetooth
comport = serial.Serial('/dev/rfcomm0', 9600)

time.sleep(1.8) # Entre 1.5s a 2s
cont = 0

while ( True ):

    VALUE_SERIAL=comport.readline()
   
    x = str(VALUE_SERIAL)[2:3]

    if x == '1':
        pyautogui.press('space')
        cont += 1
        if cont % 2 == 0:
            print("PULA!!\n")
        else:
            print("PULA!!!\n")
        

    comport.reset_input_buffer()
