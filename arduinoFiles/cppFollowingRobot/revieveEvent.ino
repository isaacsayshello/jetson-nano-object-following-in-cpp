
void receiveEvent(int bytes) {
  //Wire.read(); // If YOU ARE USING the python manual motor control then this has to be uncommited other wise just leave it.
  for (int xxx = 0; xxx < 2; ++xxx)
  {
  //Serial.print("-----------");
  speeds[xxx] = Wire.read();
  //Serial.print("hi");
  //Serial.print(speeds[xxx]);
  //Serial.println("-----------");
  }
  timeOfLastRecieveEvent = millis();
 
}
