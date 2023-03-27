#include <stdio.h>
#include <string.h>
#include <SoftwareSerial.h>

#define RS485_tx 1
#define RS485_rx 2

char bms_packets[0xAF, 0xFA, 0x60, 0x05, 0x01, 0x60, 0x7F, 0x00, 0x45, 0xAF, 0xA0]
char buff[50];

void setup(){
  Serial.begin(115200);
  rs485.begin(115200);
  pinMode(RS485_tx, OUTPUT);
  pinMode(RS485_rx, OUTPUT);
}

void loop(){
  int i = 0;
  digitaWrite(RS485_tx, LOW);
  if (rs485.available()){
    while (rs485.available() && i < 50)
    {
      buff[i++] = rs485.read();
    }
  }
}

buff[i++] = '\0';

if (i > 0){
  Serial.write(buff);
  Serial.write('\n');
  if (!strcmp(buff, " ")){
    Serial.write(buff);
  }
}