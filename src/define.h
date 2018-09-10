#define DHT_PIN1           A0    // pin for air temp/humidity sensor
#define DHT_PIN2           A1
#define DHT_TYPE           DHT22

#define DS18B20PIN        3     // pin for water temp sensore

#define PUMP_PIN          2     // power pin for pump
#define PUMP_INTERVALL    10    // pump runtime in milliseconds

#define FAN0_PWM_PIN      9     // pwm pin for fan0
#define FAN0_PIN          7     // power pin for fan0
#define INITIAL_FAN_CYCLE 40.0  // set fan to 50% speed


#define TIME_HEADER       "T"   // Header tag for serial time sync message
#define TIME_REQUEST      7     // ASCII bell character requests a time sync message
