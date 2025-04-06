int redPin = 5;
int greenPin = 4;
int bluePin = 6;
int buttonPin = 8;
int tiltSwitchPin = 11;

char dotRGB = 'r';
char dashRGB = 'b';
int dotPin = redPin;
int dashPin = bluePin;

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
int studentID[8] = {0, 0, 9, 8, 7, 6, 5, 4};

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
//dg Dr c00123456


void setup() {
  pinMode (redPin, OUTPUT);
  pinMode (greenPin, OUTPUT);
  pinMode (bluePin, OUTPUT);
  pinMode (buttonPin, INPUT);
  pinMode (tiltSwitchPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  String input1;

  if (Serial.available())
  {
    input1 = Serial.readString();

    for (int i = 0; i < input1.length(); i++)
    {
      if (input1[i] == 'd')
      {
        dotRGB = input1[i + 1];
      }
      else if (input1[i] == 'D')
      {
        dashRGB = input1[i + 1];
      }
      else if (input1[i] == 'c')
      {
        for (int j = 0; j < arraySize; j++)
        {
          studentID[j] = ((int)input1[i + 1 + j]) - 48;
        }
        state = 0;
      }
    }

    Serial.println(dotRGB);
    Serial.println(dashRGB);
    for (int i = 0; i < arraySize; i++)
    {
      Serial.println(studentID[i]);
    }
  }

  if (dotRGB == 'r')
  {
    dotPin = redPin;
  }
  else if (dotRGB == 'b')
  {
    dotPin = bluePin;
  }
  else if (dotRGB == 'g')
  {
    dotPin = greenPin;
  }

  if (dashRGB == 'r')
  {
    dashPin = redPin;
  }
  else if (dashRGB == 'b')
  {
    dashPin = bluePin;
  }
  else if (dashRGB == 'g')
  {
    dashPin = greenPin;
  }


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
          digitalWrite(dashPin, HIGH);
          delay(1000);
          digitalWrite(dashPin, LOW);
          delay(1000);
        }
        else if (currentChar == '.')
        {
          digitalWrite(dotPin, HIGH);
          delay(250);
          digitalWrite(dotPin, LOW);
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
