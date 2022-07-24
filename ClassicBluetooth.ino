#include "BluetoothSerial.h"

#define led_pin 33

BluetoothSerial SerialBT;
const String deviceName = "ESP32 board";
byte dataRX;

void setup() {
  Serial.begin(115200);
  SerialBT.begin(deviceName);

  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, LOW);
}

void loop() {
  serialEvent();

  if (dataRX == '1') {
    digitalWrite(led_pin, HIGH);
  } else if (dataRX == '0') {
    digitalWrite(led_pin, LOW);
  }
}

void serialEvent() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    dataRX = SerialBT.read();
    Serial.write(dataRX);
  }
  delay(20);
}
