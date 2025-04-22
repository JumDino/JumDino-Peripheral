#ifndef __JUMDINO_LIB_BLE_PERIPHERAL_H__
#define __JUMDINO_LIB_BLE_PERIPHERAL_H__

#include <ArduinoBLE.h>
#include "JumDino_Lib_BLE_Logger.h"

#define BLE_PERIPHERAL_BEGIN         0x2000
#define BLE_PERIPHERAL_BEGIN_FAILED  0x2001
#define BLE_PERIPHERAL_CONNECTED     0x2002
#define BLE_PERIPHERAL_DISCONNECTED  0x2003
#define BLE_PERIPHERAL_ADVERTISED    0x2004
#define BLE_PERIPHERAL_DATA_SENT     0x2005

class PokeroboBLEGenerator {
  public:
    virtual bool generate(int32_t &value) {
      return false;
    }
};

class PokeroboBLEPeripheral {
  public:
    PokeroboBLEPeripheral(const char *charactId, const char* serviceId,
        PokeroboBLEGenerator *generator = NULL,
        PokeroboBLELogger *logger = NULL);
    void begin(const char* localName, uint16_t delayTime = 0);
    void check();
  protected:
    void initialize(BLEIntCharacteristic *charact, BLEService *service);
    virtual void sendData();
    BLEService *service = NULL;
    BLEIntCharacteristic *charact = NULL;
  private:
    uint16_t _delayTime = 0;
    PokeroboBLEGenerator *_generator = NULL;
    PokeroboBLELogger *_logger = NULL;
};

class PokeroboBLEPeripheralDebugLogger: public PokeroboBLELogger {
  public:
    void log(uint16_t type, BLEDevice *device = NULL, int32_t value = 0) {
      switch (type) {
      case BLE_PERIPHERAL_BEGIN:
        Serial.println("BLE khởi động");
        break;
      case BLE_PERIPHERAL_BEGIN_FAILED:
        Serial.println("BLE khởi động thất bại!");
        break;
      case BLE_PERIPHERAL_CONNECTED:
        if (device != NULL) {
          Serial.print("Đã kết nối với: ");
          Serial.println(device->address());
        } else {
          Serial.print("Đã kết nối!");
        }
        break;
      case BLE_PERIPHERAL_DISCONNECTED:
        Serial.println("Ngắt kết nối!");
        break;
      case BLE_PERIPHERAL_ADVERTISED:
        Serial.println("BLE Peripheral đang phát sóng...");
        break;
      case BLE_PERIPHERAL_DATA_SENT:
        Serial.print("Sent value: ");
        Serial.println(value);
        break;
      }
    }
};

#endif
