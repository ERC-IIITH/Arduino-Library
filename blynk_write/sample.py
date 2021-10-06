import blynklib
import time

time.sleep(1) # delay

BLYNK_AUTH = '' # Enter your auth token here in between ' '

# initialize Blynk
blynk = blynklib.Blynk(BLYNK_AUTH)

# appropriately create buttons/ readers/ sliders to input/ output values

@blynk.handle_event('write V2') # to read values from Virtual pin 2
def write_virtual_pin_handler(pin,value):
    print("V2" + str(value)+"\n")
    blynk.virtual_write(0,"22") # write 22 to virtual pin 0
    # you can replace 22 with any character


@blynk.handle_event('write V3') # to read values from VP 3
def write_virtual_pin_handler(pin,value):
    print("V3" + str(value)+"\n")
    blynk.virtual_write(0,"33")

while True:
    blynk.run()
