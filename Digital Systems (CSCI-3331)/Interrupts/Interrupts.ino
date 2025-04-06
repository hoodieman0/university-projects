#include <TimerOne.h>

int redPin = 10;
int greenPin = 9;
int bluePin = 11;

int addingCounter = 0;
int sortingCounter = 0;
int printingCounter = 0;

String possibleFunctions[] = {"Adding Numbers", "Sorting", "Printing"};

volatile unsigned int functionToStart = 0;
unsigned int functionController = 0;

int numArray[700];

int arraySize = sizeof(numArray) / sizeof(numArray[0]); 

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);

  Timer1.initialize(100000); //from 1 to 8388480, or 1 mircosecond to 8.3 seconds
  Timer1.attachInterrupt(changeFunction);
}

void loop() 
{
  noInterrupts();
  //time sensitive:

  functionController = functionToStart;

  if(functionController > 2)
  {
    functionToStart = 0;
  }

  Serial.print("Current Function Is = ");
  Serial.println(possibleFunctions[functionController]);

  switch(functionController)
  {
    case 0: addToArray(); break;
    case 1: sortArray(); break;
    case 2: printArray(); break;
  }

  interrupts();
  //not time sensitive:
}

void changeFunction()
{
  Serial.println("Time To Switch!");
  functionToStart++;
}


void addToArray()
{
   digitalWrite(redPin, HIGH);

   addingCounter++;
   if(addingCounter > arraySize)
   {
     addingCounter = 0;
   }
   
   int num = random(0, 1001);
   numArray[addingCounter] = num;

   Serial.print("Added ");
   Serial.print(num);
   Serial.print(" At Index ");
   Serial.println(addingCounter);
   
   digitalWrite(redPin, LOW);
}

void swap(int * x, int * y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void sortArray()
{
  // blue LED
  digitalWrite(bluePin, HIGH);

  if (sortingCounter > arraySize)
  {
    sortingCounter = 0;
  }

  //Selection Sort Using Interrupts
  int minIndex = sortingCounter;
  for (int j = sortingCounter + 1; j < arraySize || j < addingCounter; j++)
  {
    if (numArray[j] < numArray[minIndex])
    {
      minIndex = j;
    }
  }

  Serial.print("Swapping Index ");
  Serial.print(minIndex);
  Serial.print(" And ");
  Serial.println(sortingCounter);
  swap(&numArray[minIndex], &numArray[sortingCounter]);
  sortingCounter++;


  
  digitalWrite(bluePin, LOW);
}

void printArray()
{
  digitalWrite(greenPin, HIGH);
  
  printingCounter++;
  if (printingCounter > arraySize)
  {
    printingCounter = 0;
  }

  Serial.print("Number At Index ");
  Serial.print(printingCounter);
  Serial.print(" Is: ");
  Serial.println(numArray[printingCounter]);
  
  digitalWrite(greenPin, LOW);
}
