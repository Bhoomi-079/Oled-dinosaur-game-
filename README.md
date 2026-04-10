# Oled-dinosaur-game-
PLayable dinosaur game using oled display and tactile buttons
Arduino Dino Game 🦕
A Chrome Dino Runner clone built using Arduino and a 0.96" SSD1306 OLED display with a tactile button. This is a fully functional mini-game where you control a dinosaur to jump over moving cacti, just like the famous offline Chrome game.

Project Photo
(Real working prototype - Score: 3013 | HI: 244)

✨ Features
Smooth jumping physics with gravity
Randomly generated cactus obstacles
Score system (increases with time)
High score tracking (saved in EEPROM)
Game Over screen with restart option
Simple pixel art animation (running + jumping)
Clean and responsive controls using a tactile button
📋 Hardware Required
Component	Quantity	Notes
Arduino Uno / Nano	1	Any compatible board
0.96" SSD1306 OLED	1	I2C version (blue/white)
Tactile Push Button	1	For jumping
Breadboard + Jumper Wires	-	-
Buzzer (Optional)	1	For jump and game over sound
🔌 Circuit Connections
Component	Arduino Pin
OLED SDA	A4
OLED SCL	A5
OLED VCC	5V
OLED GND	GND
Button One Leg	Pin 2
Button Other Leg	GND
The code uses INPUT_PULLUP, so no external resistor is needed for the button.

🛠️ Libraries Required
Install these libraries via Arduino IDE → Sketch → Include Library → Manage Libraries:

Adafruit SSD1306
Adafruit GFX Library
📥 Installation
Connect the circuit as shown above.
Install the required libraries.
Copy the code below into the Arduino IDE.
Upload the sketch to your Arduino.
Press the tactile button to start/restart the game.
🎮 How to Play
Press the tactile button → Dinosaur jumps.
Avoid the cactus obstacles.
The longer you survive, the higher your score.
When game ends, press the button again to restart.
