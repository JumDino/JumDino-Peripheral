#ifndef __POKEROBO_LAB_BLE_LOGGER_H__
#define __POKEROBO_LAB_BLE_LOGGER_H__

#include <ArduinoBLE.h>

class PokeroboBLELogger {
  public:
    virtual void log(uint16_t type, BLEDevice *device = NULL, int32_t value = 0) {}
};

#endif
