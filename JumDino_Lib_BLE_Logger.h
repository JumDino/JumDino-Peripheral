#ifndef __JUMDINO_LIB_BLE_LOGGER_H__
#define __JUMDINO_LIB_BLE_LOGGER_H__

#include <ArduinoBLE.h>

class PokeroboBLELogger {
  public:
    virtual void log(uint16_t type, BLEDevice *device = NULL, int32_t value = 0) {}
};

#endif
