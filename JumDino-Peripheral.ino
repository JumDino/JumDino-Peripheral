#include <Wire.h>
#include <MPU6050.h>
#include "JumDino_Lib_BLE_Peripheral.h"

MPU6050 mpu;

int16_t ax, ay, az;  // Gia tốc trên các trục

class MyBLEGenerator: public PokeroboBLEGenerator {
  public:
    bool generate(int32_t &value) {
      mpu.getAcceleration(&ax, &ay, &az);
      value = ax;
      return true;
    }
};

MyBLEGenerator mpuReader;
PokeroboBLEPeripheralDebugLogger serialLogger;
PokeroboBLEPeripheral mpuPeripheral("2A56", "180C", &mpuReader, &serialLogger);

void setup() {
  delay(3000);

  Wire.begin();
  Serial.begin(57600);

  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("MPU6500 is not connected!");
    while (1);
  }

  mpuPeripheral.begin("UNO-R4-BLE", 20);
}

void loop() {
  mpuPeripheral.check();
}
