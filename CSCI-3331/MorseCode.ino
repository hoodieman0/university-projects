int redPin = 5;
int greenPin = 4;
int bluePin = 6;
int buttonPin = 8;
int tiltSwitchPin = 11;

bool tiltSwitchState = LOW;
bool buttonState1 = LOW;
bool buttonState2 = LOW;
bool buttonState3 = LOW;

bool oldButtonState = LOW;
bool isTriggered = false;

int nuermals[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
char morseCode[10][5] = {
                          {'-', '-', '-', '-', '-'}, //0
                          {'.', '-', '-', '-', '-'}, //1
                          {'.', '.', '-', '-', '-'}, //2
                          {'.', '.', '.', '-', '-'}, //3
                          {'.', '.', '.', '.', '-'}, //4
                          {'.', '.', '.', '.', '.'}, //5
                          {'-', '.', '.', '.', '.'}, //6
                          {'-', '-', '.', '.', '.'}, //7
                          {'-', '-', '-', '.', '.'}, //8
                          {'-', '-', '-', '-', '.'}  //9
                        };

int state = 0;
int studentID[8] = {0, 0, 6, 9, 9, 5, 9, 5};

int arraySize = sizeof(studentID) / sizeof(studentID[0]);

int currentNumber;
char currentChar;

/*
Morse Code
1 = .----
2 = ..---
3 = ...--
4 = ....-
5 = .....
6 = -....
7 = --...
8 = ---..
9 = ----.
0 = -----

Blue = -
Red = .
*/



void setup() {
  pinMode (redPin, OUTPUT);
  pinMode (greenPin, OUTPUT);
  pinMode (bluePin, OUTPUT);
  pinMode (buttonPin, INPUT);
  pinMode (tiltSwitchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState1 = digitalRead(buttonPin);
  delay(100);
  buttonState2 = digitalRead(buttonPin);
  delay(100);
  buttonState3 = digitalRead(buttonPin);

  tiltSwitchState = digitalRead(tiltSwitchPin);
  

if ((buttonState1 == buttonState2) && (buttonState1 == buttonState3)) //debounce checker
  {
    if (buttonState1 == HIGH)//is the button pressed?
    {
      Serial.println("Button Pressed");
    
      currentNumber = studentID[state]; //gets the current digit
      Serial.print("CURRENT DIGIT: ");
      Serial.println(currentNumber);
      for (int i = 0; i < 5; i++)
      {
        currentChar = morseCode[currentNumber][i];
        Serial.print("CURRENT CHAR: ");
        Serial.println(currentChar);
        if (currentChar == '-') //gets the morse code value
        {
          digitalWrite(bluePin, HIGH);
          delay(1000);
          digitalWrite(bluePin, LOW);
          Serial.print("BLUE OUTPUT\n");
          delay(1000);
        }
        else if (currentChar == '.')
        {
          digitalWrite(redPin, HIGH);
          delay(250);
          digitalWrite(redPin, LOW);
          Serial.print("RED OUTPUT\n");
          delay(1000);
        }
      }
      state++; //moves to next digit
      if (state >= arraySize) //if greater than array reset
      {
        state = 0;
        Serial.println("ID Finished. Resetting...");
      }
    }
  }

 if (tiltSwitchState == HIGH) //reset code
 {
  Serial.println("Tilt Switch Active");
  state = 0;
 }
}
