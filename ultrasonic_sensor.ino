
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define BUTTON_PIN 2
#define BUZZER_PIN 8          // Optional

// Game Variables
int dinoY = 45;
int velocity = 0;
bool isJumping = false;
int obstacleX = 110;
int obstacleType = 0;
int score = 0;
int highScore = 0;
bool gameOverFlag = false;
unsigned long lastScoreTime = 0;
unsigned long lastFrameTime = 0;
bool dinoLeg = false;  // For running animation

// Dino and Cactus bitmaps
const unsigned char dino[] PROGMEM = {
  0x00, 0x7C, 0x4C, 0x7C, 0x7C, 0x40, 0x40, 0x60
};

const unsigned char cactus[] PROGMEM = {
  0x18, 0x18, 0x7E, 0x18, 0x18, 0x18, 0x18, 0x00
};

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);
  }

  highScore = EEPROM.read(0) | (EEPROM.read(1) << 8);
  
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  showStartScreen();
}

void loop() {
  if (gameOverFlag) {
    if (digitalRead(BUTTON_PIN) == LOW) {
      resetGame();
    }
    return;
  }

  unsigned long currentTime = millis();

  // Button press with debounce
  if (digitalRead(BUTTON_PIN) == LOW && !isJumping) {
    isJumping = true;
    velocity = -6;
    tone(BUZZER_PIN, 800, 50);
    delay(50);
  }

  // Update physics every 30ms
  if (currentTime - lastFrameTime > 30) {
    lastFrameTime = currentTime;

    // Dino physics
    if (isJumping) {
      dinoY += velocity;
      velocity += 1;  // gravity
      if (dinoY >= 45) {
        dinoY = 45;
        isJumping = false;
        velocity = 0;
      }
    }

    // Move obstacle
    obstacleX -= 3;
    if (obstacleX < -10) {
      obstacleX = 128 + random(20, 60);
      score += 10;
    }

    // Score increase
    if (currentTime - lastScoreTime > 200) {
      score++;
      lastScoreTime = currentTime;
    }

    // Collision detection
    if (obstacleX < 25 && obstacleX > 10 && dinoY > 38) {
      gameOverFlag = true;
      tone(BUZZER_PIN, 200, 400);
      if (score > highScore) {
        highScore = score;
        EEPROM.write(0, highScore & 0xFF);
        EEPROM.write(1, (highScore >> 8) & 0xFF);
      }
    }

    drawGame();
  }
}

void drawGame() {
  display.clearDisplay();

  // Draw ground
  display.drawLine(0, 55, 128, 55, SSD1306_WHITE);

  // Draw Dino
  display.drawBitmap(15, dinoY, dino, 8, 8, SSD1306_WHITE);
  
  // Simple running legs when on ground
  if (!isJumping) {
    dinoLeg = !dinoLeg;
    display.drawPixel(18, dinoY + 8, dinoLeg ? SSD1306_WHITE : SSD1306_BLACK);
  }

  // Draw Cactus
  display.drawBitmap(obstacleX, 45, cactus, 8, 8, SSD1306_WHITE);

  // Score & High Score
  display.setCursor(70, 5);
  display.print("HI ");
  display.print(highScore);
  display.setCursor(70, 18);
  display.print(score);

  display.display();
}

void showStartScreen() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(15, 15);
  display.print("DINO");
  display.setTextSize(1);
  display.setCursor(25, 40);
  display.print("Press Button");
  display.display();
}

void resetGame() {
  dinoY = 45;
  velocity = 0;
  isJumping = false;
  obstacleX = 110;
  score = 0;
  gameOverFlag = false;
  lastScoreTime = millis();
  display.clearDisplay();
}
