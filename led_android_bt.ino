/*
  Code by Edney Rossi and OpenSource Comunit
  ------------------------------------------
  Led On/Off Bluetooth android control
  module HC06
  ------------------------------------------
  Schematic:
  Arduino Uno <----> Bluetooth HC-06
  ...pin 3 Rx <----> Tx
  ...pin 2 Tx <----> Rx

  .....pin 13 <----> LED
  ------------------------------------------
*/


#include <SoftwareSerial.h>   //Software Serial Port

#define RxD         3
#define TxD         2
#define PINLED      13

#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;   // variable to store the servo position
Servo myservo2;
int pos2 = 0;


SoftwareSerial blueToothSerial(RxD, TxD);

void setup()
{
  Serial.begin(9600);
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  pinMode(PINLED, OUTPUT);

  blueToothSerial.begin(9600);

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);  // attaches the servo on pin 10 to the servo object
}

void loop()
{
  char recvChar;
  if (blueToothSerial.available())
  { //check if there's any data sent from the remote bluetooth shield
    recvChar = blueToothSerial.read();
    Serial.println(recvChar);
    Serial.println(pos);
    Serial.println(pos2);
    
    if (recvChar == '1')
    {
      digitalWrite(PINLED, HIGH);
    }
    else if (recvChar == '0')
    {
      digitalWrite(PINLED, LOW);
    }
    else if (recvChar == 'a'& pos<180)
    {
      
      pos = pos + 10;
    }
    else if (recvChar == 'b' & pos >0)
    {
      pos = pos - 10;
    }
    else if (recvChar == 'A' & pos2 <180)
    {
      pos2 = pos2 + 10;
    }
    else if (recvChar == 'B' & pos2 >0)
    {
      pos2 = pos2 - 10;
    }
  }//end if

  myservo.write(pos);              // tell servo to go to position in variable 'pos'
  delay(15);                       // waits 15ms for the servo to reach the position
  myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
  delay(15);                       // waits 15ms for the servo to reach the position
  
}//end void loop
