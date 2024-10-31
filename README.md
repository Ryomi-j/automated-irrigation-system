# 🌱Automated Irrigation System

Do you enjoy side dishes made with bean sprouts?
But do you think a bag of bean sprouts is a bit too expensive?

This project can help you grow your own bean sprouts at home with an Automated Irrigation System! With this system, you can cultivate fresh bean sprouts on your own, easily and efficiently.

## 🔧Materials
- Arduino Uno R3 - 1 unit
- Button switch module for Arduino - 1 unit
- Water pump (5~12V) - 1 unit
- Power supply (suitable for your water pump voltage)
- Mini breadboard - 1 or 2 units
- Jumper wires - several
- Flexible hose - for water flow
- Resistors - 3 units
- LEDs - 2 units (for system status indication)
- 1-channel relay module - 1 unit
- Water container/basket - 1 unit (for storing water for irrigation)

## ⚙️Setting
### Important Notes

- Most of minus should be connected to Arduino GND. 
- Most of plus should be connected to Arduino 5v or 3.3v.

### Reference Circuit Image
Here is the reference circuit image to help you assemble the project:

![circuit image](https://github.com/user-attachments/assets/c7558a04-a74f-4225-9e3e-df97c97ae6a2)

### Wiring Instructions
1. Power Supply and Pump Setup
   - Connect the minus (-) terminal of the power supply to the minus (-) terminal of the water pump.
   - Connect the plus (+) terminal of the water pump to the NO (Normally Open) terminal on the relay module.
   - Connect the plus (+) terminal of the power supply to the COM (Common) terminal on the relay module.

2.  Relay and Arduino Connection
   - Connect the relay module’s VCC to the 5V pin on the Arduino.
   - Connect the relay module’s GND to the GND pin on the Arduino.
   - Connect the relay module’s Signal (S) pin to Digital Pin 7 on the Arduino. This will allow the Arduino to control the relay.

3. LED Setup for Status Indication

   - Connect the positive leg (longer leg) of the first LED to Digital Pin 8 on the Arduino through a resistor (e.g., 220Ω).
   - Connect the negative leg (shorter leg) of the first LED to the GND on the breadboard.
   - Repeat the above steps for the second LED, connecting it to Digital Pin 9.

4. Button Connection
   - Connect one leg of the button to Digital Pin 2 on the Arduino.
   - Connect the other leg of the button to the GND on the breadboard.
   - Ensure the button uses the internal pull-up resistor feature of the Arduino by configuring the pin mode in the code.

5. Hose and Water Container
   - Attach a hose to the output of the water pump, directing the other end to your sprout container or water distribution system.
   
### How the System Works
- When the button is pressed, the irrigation system’s interval and duration settings change, allowing you to adjust watering times.
- The LEDs will indicate the current mode and system status:
   - All LEDs Off: The system will water every 3 hours for a duration of 3 minutes.
   - LED 1 (Yellow): The system is set to water every 2 hours for a duration of 4 minutes.
   - LED 2 (Green): The system is set to water every 4 hours for a duration of 4 minutes.
   - Both LEDs: Continuous irrigation mode, where the water pump will run without stopping
- The Arduino controls the relay to turn the water pump on and off based on these interval and duration settings, ensuring that your bean sprouts receive the precise amount of moisture they need based on your selected mode.

### 💻 Code
Please upload the code to your Arduino to manage the automated irrigation schedule. Ensure that the interval and duration settings match your plant's watering requirements.

### 📝 Troubleshooting Tips
- Water Pump Not Working: Check all power and ground connections, especially the connections between the relay, power supply, and pump.
- Button Unresponsive: Verify that the button is connected to the correct Arduino pin and check for any loose connections.
- LEDs Not Lighting Up: Ensure that the LED polarity is correct (longer leg to positive) and that resistors are in place.

### 📬 Contact
If you have any questions about this project, feel free to reach out:<br>
Email: ryomi.j78@gmail.com

