#include <Wire.h>

// MCP23008_I2CR8G5LE I2C address is 0x20(32)
#define Addr 0x20
byte readByte;
uint8_t data;
void setup()
{
  // Initialise I2C communication as MASTER
  Wire.begin();
  // Initialise serial communication, set baud rate = 9600
  Serial.begin(9600);

  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select IODIR register
  Wire.write(0x00);
  // All pins are configured as outputs
  Wire.write(0x00);
  // Stop I2C transmission
  Wire.endTransmission();
  delay(300);
    // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select GPIO register
  Wire.write(0x09);
  Wire.write(0x00);
  // Stop I2C transmission
  Wire.endTransmission();
}


void loop()
{
   Wire.beginTransmission(Addr);
   Wire.write(0x09);
  // Select GPIO register
  if(Serial.available()>0){
    readByte = Serial.read();
    char sw = (char) readByte; 
    Serial.print(sw);
    Wire.requestFrom(Addr,2);
    data = Wire.read();
  if(sw == '1'){
    if(data == 0x01)
    Wire.write(0x00);
    Serial.println("Relay OFF");
    delay(500);
    else
      Wire.write(0x01);
      Serial.println("Relay ON");
      delay(500);
  }
  if(sw == '2'){
    if(data == 0x02)
      Wire.write(0x00);
      Serial.println("Relay OFF");
      delay(500);
    else
      Wire.write(0x02);
      Serial.println("Relay ON");
      delay(500);
  }
  if(sw == '3'){
    if(data == 0x04)
      Wire.write(0x00);
      Serial.println("Relay OFF");
      delay(500);
    else
      Wire.write(0x04);
      Serial.println("Relay ON");
      delay(500);
  }
  if(sw == '4'){
    if(data == 0x08)
      Wire.write(0x00);
      Serial.println("Relay OFF");
      delay(500);
    else
      Wire.write(0x08);
      Serial.println("Relay ON");
      delay(500);
  }
  if(sw == '5'){
    if(data == 0x10)
      Wire.write(0x00);
      Serial.println("Relay OFF");
      delay(500);
    else
      Wire.write(0x10);
      Serial.println("Relay ON");
      delay(500);
  }
  if(sw == '6'){
    if(data == 0x20)
      Wire.write(0x00);
      Serial.println("Relay OFF");
      delay(500);
    else
      Wire.write(0x20);
      Serial.println("Relay ON");
      delay(500);
  }
  if(sw == '7'){
    if(data == 0x40)
      Wire.write(0x00);
      Serial.println("Relay OFF");
      delay(500);
    else
      Wire.write(0x40);
      Serial.println("Relay ON");
      delay(500);

  }
  
  if(sw == '8'){
    if(data == 0x80)
      Wire.write(0x00);
      Serial.println("Relay OFF");
      delay(500);
      else
        Wire.write(0x80);
        Serial.println("Relay ON");
        delay(500);
  }
  }
  
  // Stop I2C transmission
  Wire.endTransmission();

  // Output data to serial monitor
  }
