# MinimalJammer

This project is a minimal and portable implementation of FazJammer by William Afton and Antonio Martínez with a printed circuit board (PCB) and a Lithium Polymer (Li-Po) battery for power. The OLED display was removed in favor of three LEDs for idle, wifi and full attack modes. A fourth mode, stealth, was added to use the full attack mode without any lights on. A case measuring 88 x 63 x 24 mm encloses the board, battery and all the modules for portable use. 

## Requirements

- **NodeMCU ESP8266**
- **NRF24L01+** 2.4 GHz Module
- **1 Pin DIP Switch** For Turning the Device On
- **4 Pin 6x6 Push Button** For Switching Modes
- **Green Led**
- **Yellow Led**
- **Red Led**
- **3x 220Ω (or any sufficiently high resistance value) Resistors** For Limiting LED Currents
- **3.7 Volt Li-Po Battery Cell**
- **TP4056 Type-C Li-Po Charging Board with Out Pins**
- **2x M3x12 Hex Bolts**
- **A 3D Printer**

## Required Libraries

The following libraries must be installed in Arduino IDE:

- [RF24](https://github.com/nRF24/RF24)
- [ezButton](https://github.com/ArduinoGetStarted/button)

## Steps

1. **Manufacture PCB:** Use a manufacturing service (such as JLCPCB or PCBWay) to manufacture the PCBs.
2. **Solder the Components to the Board:** Source the required components using the Bill of Materials found in the project documents and solder each part according to the schematic.  
3. **Install libraries**: Use **Library Manager** in Arduino IDE to install the required libraries.
4. **Upload the code**: Open `jammer.ino` in Arduino IDE and upload it to your ESP8266 board.
5. **Print the Case**: Use the provided STEP or STL files to print the case and assemble with two M3x12 hex bolts. Use the pin spacer part to prevent sharp pins poking your battery. Edit the bottom case part according to your needs, it is designed for a 82 x 50 x 6 mm battery for my case. 
7. **Power up the device**: Switch the device on using the DIP switch and use the push button to switch modes. 

## Usage

1. **Idle Mode:** Turns the Green LED on indicating its ready for user input. Nothing is transmitted.
2. **Wifi Attack Mode:** Turns the Yellow LED on indicating its jamming all wifi channels in the 2.4 GHz band.
3. **Full Attack Mode:** Turns the Red LED on indicating its jamming all channels including Bluetooth in the 2.4 GHz band.
4. **Stealth Attack Mode:** Turns the Red LED off while still jamming all channels in the 2.4 GHz band. 

## Images
![PCB](https://github.com/Egco2811/MinimalJammer/blob/main/images/No%20Case.jpeg?raw=true)
![Front](https://github.com/Egco2811/MinimalJammer/blob/main/images/Front.jpeg?raw=true)
![Ports](https://github.com/Egco2811/MinimalJammer/blob/main/images/Charging%20Port.jpeg?raw=true)



## License & Legal Disclaimer

This project is for **educational purposes only** and unauthorized usage is **illegal**. Please check your country's laws and adhere to ethical guidelines.

---

**Developer:** [system-linux](https://github.com/system-linux), [Egco2811](https://github.com/Egco2811)
