/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x64 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/
//"i2c-address": "0x3D"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TimerOne.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define CURSOR_HEIGHT   16
#define CURSOR_WIDTH    16
static const unsigned char PROGMEM cursor_bmp[] =
{ 
  B10000000, B00000000,
B11000000, B00000000,
B10100000, B00000000,
B10010000, B00000000,
B10001000, B00000000,
B10000100, B00000000,
B10000010, B00000000,
B10000001, B00000000,
B10001111, B10000000,
B10010000, B00000000,
B10100000, B00000000,
B11000000, B00000000,
B00000000, B00000000,
B00000000, B00000000,
B00000000, B00000000,
B00000000, B00000000
};

#define X_MOVE 10
#define Y_MOVE 10
#define OFFSET 3
  
volatile int cursorX = display.width()/2;
volatile int cursorY = display.height()/2;

int upButton = 8;
int downButton = 9;
int rightButton = 10;
int leftButton = 11;

void setup() {
  Serial.begin(9600);

  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);

  Timer1.initialize(150000);
  Timer1.attachInterrupt(moveCursor);
  interrupts();
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds
}

  void loop()
  {
    display.clearDisplay();
    drawBackground();
    drawCursor();
    drawWords();
    display.display();
  }

  void drawBackground()
  {
    //x1, y1, x2, y2, x3, y3
    display.drawTriangle(5, 0, 10, 10, 0, 10,
      SSD1306_WHITE );
    
    //x, y, radius
    display.drawCircle(display.width() - 6, 5, 5, SSD1306_WHITE);

    //x, y, width, height
    display.drawRect(0, display.height() - 10, 10, 10, SSD1306_WHITE);

    //x1, y1, x2, y2
    display.drawLine(display.width() - 10, display.height() - 10, display.width(), 
      display.height(), SSD1306_WHITE);
    display.drawLine(display.width() - 10, display.height() - 1, display.width() - 1, 
      display.height() - 10, SSD1306_WHITE);
  }
  void drawWords()
  {
    display.setTextSize(1);    
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(display.width()/3, display.height()/2.5);
    display.cp437(true);
    String textToDisplay = "";

    if (cursorX < 15)
    {
      if (cursorY < 15)
      {
        textToDisplay = "Triangle";
      }
      else if (cursorY > display.height() - 15)
      {
        textToDisplay = "Square";
      }
    }
    else if (cursorX > display.width() - 15)
    {
      if (cursorY < 15)
      {
        textToDisplay = "Circle";
      }
      else if (cursorY > display.height() - 15)
      {
        textToDisplay = "Cross";
      }
    }

    display.println(textToDisplay);

  }

  void drawCursor()
  {
    display.drawBitmap(
    cursorX,
    cursorY,
    cursor_bmp, CURSOR_WIDTH, CURSOR_HEIGHT, 1);
  }

  void moveCursor() //interupt
  {
    int up = digitalRead(upButton);
    int down = digitalRead(downButton);
    int right = digitalRead(rightButton);
    int left = digitalRead(leftButton);
    
    if (up == 0)
    {
      if (cursorY < 0)
      {
        cursorY = OFFSET;
      }
      else
      {
        cursorY -= Y_MOVE;
      }
      Serial.println("UP");
    }
    else if (down == 0)
    {
      if (cursorY > display.height() - 5)
      {
        cursorY = display.height() - OFFSET;
      }
      else
      {
        cursorY += Y_MOVE;
      }
      Serial.println("DOWN");
    }
    else if (right == 0)
    {
      if (cursorX > display.width() - 5)
      {
        cursorX = display.width()-OFFSET;
      }
      else
      {
        cursorX += X_MOVE;
      }
      Serial.println("RIGHT");
    }
    else if (left == 0)
    {
      if (cursorX < 0)
      {
        cursorX = OFFSET;
      }
      else
      {
        cursorX -= X_MOVE;
      }
      Serial.println("LEFT");
    }
  }
