#include "lcd.h"


U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);


void LCDInit() {
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFont(u8x8_font_5x7_f);
  u8x8.drawString(0,0,"LCD Init OK.");
}


void printValuesLCD(sensorValues values) {
  u8x8.drawString(0,0,"A1   A2   W    C");
  u8x8.drawString(0,1,"                ");
  u8x8.drawString(0,2,"H1   H2        %");
  u8x8.drawString(0,3,"                ");
  u8x8.drawString(0,4,"pH :            ");
  u8x8.drawString(0,5,"ECC :           ");
  u8x8.setCursor(0,1);
  u8x8.print(values.tempAir1,2);
  u8x8.setCursor(5,1);
  u8x8.print(values.tempAir2,2);
  u8x8.setCursor(10,1);
  u8x8.print(values.tempWater,2);
  u8x8.setCursor(0,3);
  u8x8.print(values.humAir1,2);
  u8x8.setCursor(5,3);
  u8x8.print(values.humAir2,2);
  u8x8.setCursor(6,4);
  u8x8.print(values.pH,2);
  u8x8.setCursor(6,5);
  u8x8.print(values.ecc);
}


void printTimeLCD(){
  u8x8.print(hour());
  printDigitsLCD(minute());
  printDigitsLCD(second());
}


void printDigitsLCD(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  u8x8.print(":");
  if(digits < 10)
    u8x8.print('0');
  u8x8.print(digits);
}

