#include "pump.h"
#include "light.h"
#include "fans.h"
#include "time.h"
#include <SoftwareSerial.h>
#include <SerialCommand.h>

void cmdInit();

void pumpCmd();

void lightCmd();

void fanCmd();

void fanSpeedCmd();

void timeCmd();

void unrecognizedCmd();

void usageCmd();
