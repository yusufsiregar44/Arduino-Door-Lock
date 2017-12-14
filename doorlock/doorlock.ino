#include <Keypad.h>
#include <Key.h>

#define LOCK 5
#define LED  13

#define ROWS 4
#define COLS 3

char keys[ROWS][COLS] =
{
  { '1','2','3' },
  { '4','5','6' },
  { '7','8','9' },
  { '*','0','#' }
};

byte rowPins[ROWS] = { 8, 9, 10, 11 };
byte colPins[COLS] = { 12, 7, 6 }; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

boolean isLocked = false;
unsigned long start;

char key;
char count;
String password = "0809";
String entered = "";

void setup() 
{
  Serial.begin(57600);
  
  pinMode(LOCK, OUTPUT);
  pinMode(LED, OUTPUT);
  
  keypad.setDebounceTime(100);
}

void loop() 
{
  key = keypad.getKey();

  if (key) 
  {
    if (count >= 5)
    {
      count = 0;
      Serial.println("\nWrong Password");
      entered = "";
    }

    if (key == '#')
    {
      if (entered.equals(password))
      {
        Serial.println("\nCorrect Password. Unlocking..");
        unlock();
        wait(10000);
        lock();
      }

      else
      {
        Serial.println("\nWrong Password");
        entered = "";
      }

      count = 0;
    }

    else
    {
      entered.concat(key);
      Serial.print(entered[count]);
      count++;
    }
  }

  wait(20);                   //50Hz loop rate
}

void unlock()
{
  digitalWrite(LOCK, HIGH);
}

void lock()
{
  digitalWrite(LOCK, LOW);
}

void wait(unsigned int ms)    //nonblocking delay
{
  start = millis();
  
  do 
  {
    //nonblocking codes here

  } 
  
  while (millis() - start < ms);
}

void updatePasswordString()
{

}

void updateLCD()
{
  //placeholder for LCD update routines

}
