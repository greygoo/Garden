
// uncomment to get debug output on serial console
#define DEBUG         true 


////////////////////////////////////////////////////////////////////////////////
// Sensors                                                                    //
////////////////////////////////////////////////////////////////////////////////

// PH config
#define PH_PIN        A1

// ECC config
#define ECC_PIN       A2
#define ECC_VREF      5
#define ECC_TEMP      0

// Flow sensor config
#define FLOW_PIN      2 
#define FLOW_INT      0

// DS18B20 Temp sensor config
#define TMP_NUM       2
#define TMP0_PIN      4
#define TMP1_PIN      5

// DHT Humidity sensor config
#define DHT_TYPE      DHT22
#define DHT_NUM       1
#define DHT0_PIN      6

// Float sensor config
#define FLT_NUM       2
#define FLT0_PIN      7
#define FLT1_PIN      8

// Door sensor config
#define DOOR_PIN      14 

// RF switch config for RF plugs
# define RF_PIN       10

////////////////////////////////////////////////////////////////////////////////
// Lights, Pumps, Fans and other controlled devices                           //
////////////////////////////////////////////////////////////////////////////////

// Grow light codes for rf power plugs
#define LIGHT_ON      00000F000FF0
#define LIGHT_OFF     00000F000FF0

// Relais config
#define CLOCK_PIN     11
#define DATA_PIN      12
#define LATCH_PIN     13

// Pump config
#define PUMP_NUM      2
#define PUMP0_PORT    7     // port on the relais board
#define PUMP1_PORT    6     // for pumps

// Controlled fan config
#define CFAN_NUM      1
#define CFAN0_PORT    5     // port on the relais board
#define CFAN0_PIN     9    // pin for pwm speed control
#define CFAN0_CYCLE   35.0  // speed at startup
#define CFAN0_VREF    5.0   // analog reference voltage(Volt) of the ADC

// Simple fan config
#define SFAN_NUM      2
#define SFAN0_PORT    4	    // port on the relais board 
#define SFAN1_PORT    3     // port on the relais board 

// Ambient light config
#define LED_PORT      2     // port on the relais board 

// Valves
#define VALVE_NUM     2
#define VALVE0_PORT   1     // port on the relais board 
#define VALVE1_PORT   0     // port on the relais board 


#ifdef DEBUG
 #define D_PRINT(x)     Serial.print (x)
 #define D_PRINTDEC(x)     Serial.print (x, DEC)
 #define D_PRINTLN(x)  Serial.println (x)
#else
 #define D_PRINT(x)
 #define D_PRINTDEC(x)
 #define D_PRINTLN(x)
#endif

