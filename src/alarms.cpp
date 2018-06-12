#include "alarms.h"

AlarmId pumpAlarmId;
AlarmId lightOnAlarmId;
AlarmId lightOffAlarmId;

void alarmInit() {

  // disable already set alarms
  Alarm.disable(pumpAlarmId);
  Alarm.free(pumpAlarmId);

  Alarm.disable(lightOnAlarmId);
  Alarm.free(lightOnAlarmId);

  Alarm.disable(lightOffAlarmId);
  Alarm.free(lightOffAlarmId);

  // pump rules
  pumpAlarmId = Alarm.timerRepeat(2400, pumpIntervall); //turn on pump every 60 second for the pump intervall


  //light rules
  lightOnAlarmId = Alarm.alarmRepeat(18,0,0, lightOn);
  lightOffAlarmId = Alarm.alarmRepeat(10,0,0, lightOff);
}
