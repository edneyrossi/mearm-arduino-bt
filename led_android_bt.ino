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
int pos =90;    // variable to store the servo position


SoftwareSerial blueToothSerial(RxD, TxD);

void setup()
{
  Serial.begin(9600);
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  pinMode(PINLED, OUTPUT);

  blueToothSerial.begin(9600);

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()
{
  char recvChar;
  if (blueToothSerial.available())
  { //check if there's any data sent from the remote bluetooth shield
    recvChar = blueToothSerial.read();
    Serial.print(recvChar);

    if (recvChar == '1')
    {
      digitalWrite(PINLED, HIGH);
    }
    else if (recvChar == '0')
    {
      digitalWrite(PINLED, LOW);
    }
  }//end if

  myservo.write(pos);              // tell servo to go to position in variable 'pos'
  delay(15);                       // waits 15ms for the servo to reach the position

}//end void loop

