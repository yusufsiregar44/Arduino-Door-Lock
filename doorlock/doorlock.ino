#include <Keypad.h>
#include <Key.h>

#define DIRA 2
#define DIRB 3
#define LED  13

#define ROWS 4
#define COLS 3

char keys[ROWS][COLS] =
{
  { '1','2','3' },
  { '4','5','6' },
  { '7','8','9' },
  { '#','0','*' }
};

byte rowPins[ROWS] = { 7, 6, 5, 4 };  //connect to the row pinouts of the keypad
byte colPins[COLS] = { 10, 9, 8 };    //connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

boolean isLocked = false;
unsigned long start;

char password[5] = "1234";
char entered[5] = "";

void setup() 
{
  Serial.begin(57600);
  
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  
  keypad.setDebounceTime(100);
}

void loop() 
{


  wait(250);                //4Hz loop rate
}

void wait(unsigned int ms)  //nonblocking delay
{
  start = millis();
  
  do 
  {
    //nonblocking codes here

  } 
  
  while (millis() - start < ms);
}

void lockUnlockHandler()
{

}

void updatePasswordString()
{

}

void updateLCD()
{
  //placeholder for LCD update routines
}
