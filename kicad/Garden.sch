EESchema Schematic File Version 2
LIBS:arduino
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Garden-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Conn_01x02 J5
U 1 1 5B1E97A2
P 3300 2500
F 0 "J5" H 3300 2600 50  0000 C CNN
F 1 "Serial" H 3300 2300 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-02_02x2.54mm_Straight" H 3300 2500 50  0001 C CNN
F 3 "" H 3300 2500 50  0001 C CNN
	1    3300 2500
	0    -1   -1   0   
$EndComp
$Comp
L Conn_01x02 J6
U 1 1 5B1E97D9
P 2900 2500
F 0 "J6" H 2900 2600 50  0000 C CNN
F 1 "Power" H 2900 2300 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-02_02x2.54mm_Straight" H 2900 2500 50  0001 C CNN
F 3 "" H 2900 2500 50  0001 C CNN
	1    2900 2500
	0    -1   -1   0   
$EndComp
$Comp
L Conn_01x06 J7
U 1 1 5B1E98E8
P 7150 3250
F 0 "J7" H 7150 3550 50  0000 C CNN
F 1 "RELAIS" H 7150 2850 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-06_06x2.54mm_Straight" H 7150 3250 50  0001 C CNN
F 3 "" H 7150 3250 50  0001 C CNN
	1    7150 3250
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x03 J8
U 1 1 5B1E9947
P 7150 3950
F 0 "J8" H 7150 4150 50  0000 C CNN
F 1 "RC" H 7150 3750 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-03_03x2.54mm_Straight" H 7150 3950 50  0001 C CNN
F 3 "" H 7150 3950 50  0001 C CNN
	1    7150 3950
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x04 J9
U 1 1 5B1E99A6
P 7150 4450
F 0 "J9" H 7150 4650 50  0000 C CNN
F 1 "LCD" H 7150 4150 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-04_04x2.54mm_Straight" H 7150 4450 50  0001 C CNN
F 3 "" H 7150 4450 50  0001 C CNN
	1    7150 4450
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x02 J10
U 1 1 5B1E99DB
P 7150 4950
F 0 "J10" H 7150 5050 50  0000 C CNN
F 1 "FAN_PWM" H 7150 4750 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-02_02x2.54mm_Straight" H 7150 4950 50  0001 C CNN
F 3 "" H 7150 4950 50  0001 C CNN
	1    7150 4950
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x03 J1
U 1 1 5B1E9A4A
P 2450 3150
F 0 "J1" H 2450 3350 50  0000 C CNN
F 1 "EC" H 2450 2950 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-03_03x2.54mm_Straight" H 2450 3150 50  0001 C CNN
F 3 "" H 2450 3150 50  0001 C CNN
	1    2450 3150
	-1   0    0    1   
$EndComp
$Comp
L Conn_01x03 J2
U 1 1 5B1E9A93
P 2450 3650
F 0 "J2" H 2450 3850 50  0000 C CNN
F 1 "TEMP" H 2450 3450 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-03_03x2.54mm_Straight" H 2450 3650 50  0001 C CNN
F 3 "" H 2450 3650 50  0001 C CNN
	1    2450 3650
	-1   0    0    1   
$EndComp
$Comp
L Conn_01x04 J3
U 1 1 5B1E9AC4
P 2450 4250
F 0 "J3" H 2450 4450 50  0000 C CNN
F 1 "DHT" H 2450 3950 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-04_04x2.54mm_Straight" H 2450 4250 50  0001 C CNN
F 3 "" H 2450 4250 50  0001 C CNN
	1    2450 4250
	-1   0    0    1   
$EndComp
$Comp
L Conn_01x06 J4
U 1 1 5B1E9AFD
P 2450 4950
F 0 "J4" H 2450 5250 50  0000 C CNN
F 1 "PH" H 2450 4550 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-06_06x2.54mm_Straight" H 2450 4950 50  0001 C CNN
F 3 "" H 2450 4950 50  0001 C CNN
	1    2450 4950
	-1   0    0    1   
$EndComp
$Comp
L R R1
U 1 1 5B1E9E60
P 3050 3650
F 0 "R1" V 3130 3650 50  0000 C CNN
F 1 "470" V 3050 3650 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 2980 3650 50  0001 C CNN
F 3 "" H 3050 3650 50  0001 C CNN
	1    3050 3650
	-1   0    0    1   
$EndComp
$Comp
L R R2
U 1 1 5B1E9F15
P 3050 4150
F 0 "R2" V 3130 4150 50  0000 C CNN
F 1 "1K" V 3050 4150 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 2980 4150 50  0001 C CNN
F 3 "" H 3050 4150 50  0001 C CNN
	1    3050 4150
	0    1    1    0   
$EndComp
$Comp
L Arduino_Nano_Socket XA1
U 1 1 5B1E96B6
P 4900 4050
F 0 "XA1" V 5000 4050 60  0000 C CNN
F 1 "Arduino_Nano_Socket" V 4800 4050 60  0000 C CNN
F 2 "Arduino:Arduino_Nano_Socket" H 6700 7800 60  0001 C CNN
F 3 "" H 6700 7800 60  0001 C CNN
	1    4900 4050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR01
U 1 1 5B1FE22B
P 6150 2550
F 0 "#PWR01" H 6150 2400 50  0001 C CNN
F 1 "+5V" H 6150 2690 50  0000 C CNN
F 2 "" H 6150 2550 50  0001 C CNN
F 3 "" H 6150 2550 50  0001 C CNN
	1    6150 2550
	1    0    0    -1  
$EndComp
Text GLabel 2650 3150 2    60   Input ~ 0
+5V
Text GLabel 6950 3550 0    60   Output ~ 0
GND
Text GLabel 6950 3850 0    60   Output ~ 0
GND
Text GLabel 6950 4650 0    60   Output ~ 0
GND
Text GLabel 6950 5050 0    60   Output ~ 0
GND
Text GLabel 6950 3050 0    60   Input ~ 0
+5V
Text GLabel 6950 3950 0    60   Input ~ 0
+5V
Text GLabel 6950 4550 0    60   Input ~ 0
+5V
Text GLabel 2650 3750 2    60   Input ~ 0
+5V
Text GLabel 2650 4350 2    60   Input ~ 0
+5V
Text GLabel 2650 5150 2    60   Input ~ 0
+5V
Text GLabel 3600 4850 0    60   Output ~ 0
+5V
Text GLabel 2650 5050 2    60   Output ~ 0
GND
Text GLabel 2650 4050 2    60   Output ~ 0
GND
Text GLabel 2650 4950 2    60   Output ~ 0
GND
Text GLabel 2650 3650 2    60   Output ~ 0
GND
Text GLabel 2650 3250 2    60   Output ~ 0
GND
Text GLabel 3600 4550 0    60   Output ~ 0
GND
Text GLabel 3600 4650 0    60   Output ~ 0
GND
Text GLabel 3000 2700 3    60   Output ~ 0
GND
Text GLabel 2900 2700 3    60   Output ~ 0
VCC
Text GLabel 3600 4950 0    60   Input ~ 0
VCC
$Comp
L GND #PWR02
U 1 1 5B1FAFAA
P 6300 2800
F 0 "#PWR02" H 6300 2550 50  0001 C CNN
F 1 "GND" H 6300 2650 50  0000 C CNN
F 2 "" H 6300 2800 50  0001 C CNN
F 3 "" H 6300 2800 50  0001 C CNN
	1    6300 2800
	1    0    0    -1  
$EndComp
Text GLabel 6300 2800 1    60   Input ~ 0
GND
Text GLabel 6150 2550 3    60   Output ~ 0
+5V
Text GLabel 6950 3150 0    60   Input ~ 0
D4
Text GLabel 6200 3350 2    60   Output ~ 0
D4
Text GLabel 6950 3250 0    60   Input ~ 0
D5
Text GLabel 6200 3450 2    60   Output ~ 0
D5
Text GLabel 6950 3350 0    60   Input ~ 0
D6
Text GLabel 6200 3550 2    60   Output ~ 0
D6
Text GLabel 6200 3650 2    60   Output ~ 0
D7
Text GLabel 6950 3450 0    60   Input ~ 0
D7
Text GLabel 6950 4050 0    60   Input ~ 0
D10
Text GLabel 6200 3950 2    60   Output ~ 0
D10
Text GLabel 6950 4950 0    60   Input ~ 0
D9
Text GLabel 6200 3850 2    60   Output ~ 0
D9
Text GLabel 6950 4350 0    60   Input ~ 0
A4
Text GLabel 6950 4450 0    60   Input ~ 0
A5
Text GLabel 3600 3750 0    60   Output ~ 0
A5
Text GLabel 3600 3850 0    60   Output ~ 0
A4
Text GLabel 2650 4850 2    60   Input ~ 0
A2
Text GLabel 3600 4050 0    60   Output ~ 0
A2
Text GLabel 2650 4250 2    60   Input ~ 0
A0
Text GLabel 3600 4250 0    60   Output ~ 0
A0
Text GLabel 2650 3550 2    60   Input ~ 0
D3
Text GLabel 6200 3250 2    60   Output ~ 0
D3
Text GLabel 2650 3050 2    60   Input ~ 0
A1
Text GLabel 3600 4150 0    60   Output ~ 0
A1
Text GLabel 3300 2700 3    60   Input ~ 0
TX
Text GLabel 3400 2700 3    60   Output ~ 0
RX
Text GLabel 3600 3150 0    60   Input ~ 0
RX
Text GLabel 3600 3250 0    60   Output ~ 0
TX
Wire Wire Line
	3050 3450 3050 3500
Wire Wire Line
	2650 3550 2650 3450
Wire Wire Line
	2650 3450 3050 3450
Wire Wire Line
	2650 3750 2650 3850
Wire Wire Line
	2650 3850 3050 3850
Wire Wire Line
	3050 3850 3050 3800
Wire Wire Line
	2650 4150 2900 4150
Wire Wire Line
	3200 4150 3200 4250
Wire Wire Line
	3200 4250 2650 4250
$EndSCHEMATC
