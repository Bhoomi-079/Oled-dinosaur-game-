# Arduino Dino Game 🦕

A Chrome Dino Runner clone built using Arduino and a 0.96" SSD1306 OLED display with a tactile button. This is a fully functional mini-game where you control a dinosaur to jump over moving cacti, just like the famous offline Chrome game!

![Project Photo](images/dino-game.jpg)
*(Real working prototype - Score: 3013 | HI: 244)*

---

## ✨ Features

- Smooth jumping physics with gravity
- Randomly generated cactus obstacles
- Score system (increases with time)
- High score tracking (saved in EEPROM)
- Game Over screen with restart option
- Simple pixel art animation (running + jumping)
- Clean and responsive controls using a tactile button
- Optional sound effects using a buzzer

---

## 📋 Hardware Required

| Component              | Quantity | Notes                    |
|------------------------|----------|--------------------------|
| Arduino Uno / Nano     | 1        | Any compatible board     |
| 0.96" SSD1306 OLED     | 1        | I2C version (blue/white) |
| Tactile Push Button    | 1        | For jumping              |
| Breadboard + Jumper Wires | -     | -                        |
| Buzzer (Optional)      | 1        | For jump and game over sound |

---

## 🔌 Circuit Connections

| Component         | Arduino Pin | Notes                                |
|-------------------|-------------|--------------------------------------|
| OLED SDA          | A4          |                                      |
| OLED SCL          | A5          |                                      |
| OLED VCC          | 5V          |                                      |
| OLED GND          | GND         |                                      |
| Button One Leg    | Pin 2       |                                      |
| Button Other Leg  | GND         | Uses `INPUT_PULLUP` (no resistor needed) |

---

## 🛠️ Libraries Required

Install these libraries via the Arduino IDE:

1. Go to **Sketch** → **Include Library** → **Manage Libraries...**
2. Search and install:
   - **Adafruit SSD1306**
   - **Adafruit GFX Library**

---

## 📥 Installation

1. Connect the circuit as shown in the table above.
2. Install the required libraries.
3. Copy the code below into the Arduino IDE.
4. Upload the sketch to your Arduino.
5. Press the tactile button to start/restart the game.

---

## 🎮 How to Play

1. Press the tactile button → Dinosaur jumps.
2. Avoid the cactus obstacles.
3. The longer you survive, the higher your score.
4. When the game ends, press the button again to restart.

---

