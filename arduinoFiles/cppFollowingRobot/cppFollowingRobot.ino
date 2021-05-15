//THIS FILE AND THE OTHER ONE GO ON THE ARDUINO TO RECIEVE THE COMMANDS SENT FROM THE JETSON NANO

//basically how this works is that the jetson nano sends two ints to the arduino
//the first one is the right wheel and the second one is the left wheel (sorry I can't remember if thats looking at it from the front or the back)
//the value ranges from 0 to 255. 
//0 is full reverse, 127 is stop, and 255 is full ahead.

#include <Wire.h>


int speeds[] = { 127, 127 };
int finalSpeedA = 0;
int finalSpeedB = 0;
unsigned long timeOfLastRecieveEvent = 0;

void setup()
{
  Wire.begin(0x40);      // join i2c bus with address #0x40
  Wire.onReceive(receiveEvent); // register event

  pinMode(3, OUTPUT); //init 2
  pinMode(4, OUTPUT); //init 1
  pinMode(5, OUTPUT); //pwm enable A

  pinMode(8, OUTPUT); //init 3
  pinMode(9, OUTPUT); // init 4
  pinMode(10, OUTPUT); //pwm enble B
  
  Serial.begin(2000000);    
}


void loop()
{
  
  Serial.print("speeds");
  for (int x : speeds)
  {
    Serial.print(" ");
    Serial.print(x);
    Serial.print(", ");
  }
  //221, 31
  if (speeds[0] > 127)
  {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    finalSpeedA = map(speeds[0], 128, 255, 0, 255);
    Serial.print("finalSpeedA ");
    Serial.print(finalSpeedA);
    analogWrite(5, finalSpeedA);
    Serial.print("\ngoing foword\n");
        
  }
  if (speeds[1] > 127)
  {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    finalSpeedB = map(speeds[1], 128, 255, 0, 255);
    Serial.print("finalSpeed B\n");
    Serial.print(finalSpeedB);
    analogWrite(10, finalSpeedB);
  }
  if (speeds[0] < 127)
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    finalSpeedB = map(speeds[0], 0, 126, 0, 255);
    Serial.print("finalSpeed A\n");
    Serial.print(finalSpeedA);
    analogWrite(5, finalSpeedA);
  }
  if (speeds[1] < 127)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    finalSpeedB = map(speeds[1], 126, 0, 0, 255);
    Serial.print("finalSpeed B\n");
    Serial.print(finalSpeedB);
    analogWrite(10, finalSpeedB);
  }
  if (speeds[0] == 127)
  {
    analogWrite(5, 0);
  }
  if (speeds[1] == 127)
  {
    analogWrite(10, 0);
  }

  if ((millis() - timeOfLastRecieveEvent) > 1000)
  {
    speeds[0] = 127;
    speeds[1] = 127;
  }
    
  Serial.println();
  
}
