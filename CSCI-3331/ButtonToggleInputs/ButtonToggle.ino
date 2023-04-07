int redPin = 5;
int greenPin = 4;
int bluePin = 6;
int buttonPin = 8;

bool newSwitchState1 = LOW;
bool newSwitchState2 = LOW;
bool newSwitchState3 = LOW;

bool oldSwitchState = LOW;
bool isTriggered = false;
    
void setup() {
  pinMode (redPin, OUTPUT);
  pinMode (greenPin, OUTPUT);
  pinMode (bluePin, OUTPUT);
  pinMode (buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
    newSwitchState1 = digitalRead(buttonPin);
    delay(50); //50 ms
    newSwitchState2 = digitalRead(buttonPin);
    delay(50);
    newSwitchState3 = digitalRead(buttonPin);
 
    //debounce if statement cause buttons are terrible
    if ((newSwitchState1 == newSwitchState2) && (newSwitchState1 == newSwitchState3))
    {
        if (newSwitchState1 != oldSwitchState) //if the button is press 
        {
           if (newSwitchState1 == HIGH)//is the button pressed?
           {
               if (isTriggered == LOW)
               {
                digitalWrite(redPin, HIGH);
                isTriggered = HIGH;
                Serial.print("ON\n");
               }
               else
               {
                digitalWrite(redPin, LOW);
                isTriggered = LOW;
                Serial.print("OFF\n");
               }
           }
           oldSwitchState = newSwitchState1;
        }  
    }
}
