#define DHT_NUM            2    // Number of air temp/humidity sensor
#define DHT_PIN1           A0    // pin for air temp/humidity sensor
//#define DHT_PIN2           A3    // pin for air temp/humidity sensor
#define TDS_PIN            A1
#define PH_PIN		   A2
#define DHT_TYPE           DHT22

#define DS18B20PIN         3     // pin for water temp sensore

#define PUMP0_PIN          2     // power pin for pump0
#define PUMP1_PIN	   5     // power pin for pump1

#define FAN0_PWM_PIN       9     // pwm pin for fan0
#define FAN0_PIN           7     // power pin for fan0
#define FAN1_PIN	   6	 // power pin for fan1
#define INITIAL_FAN_CYCLE  35.0  // set fan to 50% speed

#define VREF 		   5.0   // analog reference voltage(Volt) of the ADC
//#define PPMCOUNT  	   30    // sum of sample point

#define DEBUG

#ifdef DEBUG
 #define D_PRINT(x)     Serial.print (x)
 #define D_PRINTDEC(x)     Serial.print (x, DEC)
 #define D_PRINTLN(x)  Serial.println (x)
#else
 #define D_PRINT(x)
 #define D_PRINTDEC(x)
 #define D_PRINTLN(x)
#endif
