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
  pumpAlarmId = Alarm.timerRepeat(3600, pumpIntervall); //turn on pump every 6 hours for the pump intervall


  //light rules
  lightOnAlarmId = Alarm.alarmRepeat(6,0,0, lightOn);
  lightOffAlarmId = Alarm.alarmRepeat(24,0,0, lightOff);
}
