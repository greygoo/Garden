#include <Arduino.h>
#include "pump.h"
#include "light.h"
#include "fans.h"
#include "sensors.h"
#include "temp.h"
#include "dht.h"
#include "tds.h"
#include "common.h"

void handleSerial();

int parseInt(char in_char);

void handleCommand(String command);
