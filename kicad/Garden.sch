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
Text GLabel 2900 2700 3    60   Output ~ 0
VCC
Text GLabel 3600 4950 0    60   Input ~ 0
VCC
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
D8
Text GLabel 6200 3750 2    60   Output ~ 0
D8
Text GLabel 6950 4950 0    60   Input ~ 0
D9
Text GLabel 6200 3850 2    60   Output ~ 0
D9
Text GLabel 6950 4350 0    60   Input ~ 0
A4
Text GLabel 6950 4450 0    60   Output ~ 0
A5
Text GLabel 3600 3750 0    60   Input ~ 0
A5
Text GLabel 3600 3850 0    60   Output ~ 0
A4
Text GLabel 2650 4850 2    60   Output ~ 0
A2
Text GLabel 3600 4050 0    60   Input ~ 0
A2
Text GLabel 2650 4250 2    60   Output ~ 0
A0
Text GLabel 3600 4250 0    60   Input ~ 0
A0
Text GLabel 2650 3550 2    60   Input ~ 0
D3
Text GLabel 6200 3250 2    60   Output ~ 0
D3
Text GLabel 2650 3050 2    60   Output ~ 0
A1
Text GLabel 3600 4150 0    60   Input ~ 0
A1
Text GLabel 3300 2700 3    60   Input ~ 0
TX
Text GLabel 3400 2700 3    60   Output ~ 0
RX
Text GLabel 3600 3150 0    60   Input ~ 0
RX
Text GLabel 3600 3250 0    60   Output ~ 0
TX
NoConn ~ 6200 4750
NoConn ~ 6200 4850
NoConn ~ 3600 3550
NoConn ~ 3600 3650
NoConn ~ 3600 3950
NoConn ~ 3600 4350
NoConn ~ 3600 4750
NoConn ~ 2650 4650
NoConn ~ 2650 4750
$Comp
L +5V #PWR01
U 1 1 5B2264E0
P 6950 3950
F 0 "#PWR01" H 6950 3800 50  0001 C CNN
F 1 "+5V" H 6950 4090 50  0000 C CNN
F 2 "" H 6950 3950 50  0001 C CNN
F 3 "" H 6950 3950 50  0001 C CNN
	1    6950 3950
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR02
U 1 1 5B22656E
P 6950 4550
F 0 "#PWR02" H 6950 4400 50  0001 C CNN
F 1 "+5V" H 6950 4690 50  0000 C CNN
F 2 "" H 6950 4550 50  0001 C CNN
F 3 "" H 6950 4550 50  0001 C CNN
	1    6950 4550
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR03
U 1 1 5B22659C
P 6950 3050
F 0 "#PWR03" H 6950 2900 50  0001 C CNN
F 1 "+5V" H 6950 3190 50  0000 C CNN
F 2 "" H 6950 3050 50  0001 C CNN
F 3 "" H 6950 3050 50  0001 C CNN
	1    6950 3050
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR04
U 1 1 5B2265CA
P 2650 3150
F 0 "#PWR04" H 2650 3000 50  0001 C CNN
F 1 "+5V" H 2650 3290 50  0000 C CNN
F 2 "" H 2650 3150 50  0001 C CNN
F 3 "" H 2650 3150 50  0001 C CNN
	1    2650 3150
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR05
U 1 1 5B2265F8
P 2650 3750
F 0 "#PWR05" H 2650 3600 50  0001 C CNN
F 1 "+5V" H 2650 3890 50  0000 C CNN
F 2 "" H 2650 3750 50  0001 C CNN
F 3 "" H 2650 3750 50  0001 C CNN
	1    2650 3750
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR06
U 1 1 5B226626
P 2650 4350
F 0 "#PWR06" H 2650 4200 50  0001 C CNN
F 1 "+5V" H 2650 4490 50  0000 C CNN
F 2 "" H 2650 4350 50  0001 C CNN
F 3 "" H 2650 4350 50  0001 C CNN
	1    2650 4350
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR07
U 1 1 5B226654
P 2650 5150
F 0 "#PWR07" H 2650 5000 50  0001 C CNN
F 1 "+5V" H 2650 5290 50  0000 C CNN
F 2 "" H 2650 5150 50  0001 C CNN
F 3 "" H 2650 5150 50  0001 C CNN
	1    2650 5150
	0    1    1    0   
$EndComp
$Comp
L GND #PWR08
U 1 1 5B2266CD
P 2650 3250
F 0 "#PWR08" H 2650 3000 50  0001 C CNN
F 1 "GND" H 2650 3100 50  0000 C CNN
F 2 "" H 2650 3250 50  0001 C CNN
F 3 "" H 2650 3250 50  0001 C CNN
	1    2650 3250
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR09
U 1 1 5B2266FB
P 2650 3650
F 0 "#PWR09" H 2650 3400 50  0001 C CNN
F 1 "GND" H 2650 3500 50  0000 C CNN
F 2 "" H 2650 3650 50  0001 C CNN
F 3 "" H 2650 3650 50  0001 C CNN
	1    2650 3650
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR010
U 1 1 5B226729
P 2650 4050
F 0 "#PWR010" H 2650 3800 50  0001 C CNN
F 1 "GND" H 2650 3900 50  0000 C CNN
F 2 "" H 2650 4050 50  0001 C CNN
F 3 "" H 2650 4050 50  0001 C CNN
	1    2650 4050
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR011
U 1 1 5B226757
P 2650 4950
F 0 "#PWR011" H 2650 4700 50  0001 C CNN
F 1 "GND" H 2650 4800 50  0000 C CNN
F 2 "" H 2650 4950 50  0001 C CNN
F 3 "" H 2650 4950 50  0001 C CNN
	1    2650 4950
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR012
U 1 1 5B226785
P 2650 5050
F 0 "#PWR012" H 2650 4800 50  0001 C CNN
F 1 "GND" H 2650 4900 50  0000 C CNN
F 2 "" H 2650 5050 50  0001 C CNN
F 3 "" H 2650 5050 50  0001 C CNN
	1    2650 5050
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR013
U 1 1 5B2267EF
P 6950 3550
F 0 "#PWR013" H 6950 3300 50  0001 C CNN
F 1 "GND" H 6950 3400 50  0000 C CNN
F 2 "" H 6950 3550 50  0001 C CNN
F 3 "" H 6950 3550 50  0001 C CNN
	1    6950 3550
	0    1    1    0   
$EndComp
$Comp
L GND #PWR014
U 1 1 5B22681D
P 6950 3850
F 0 "#PWR014" H 6950 3600 50  0001 C CNN
F 1 "GND" H 6950 3700 50  0000 C CNN
F 2 "" H 6950 3850 50  0001 C CNN
F 3 "" H 6950 3850 50  0001 C CNN
	1    6950 3850
	0    1    1    0   
$EndComp
$Comp
L GND #PWR015
U 1 1 5B22684B
P 6950 4650
F 0 "#PWR015" H 6950 4400 50  0001 C CNN
F 1 "GND" H 6950 4500 50  0000 C CNN
F 2 "" H 6950 4650 50  0001 C CNN
F 3 "" H 6950 4650 50  0001 C CNN
	1    6950 4650
	0    1    1    0   
$EndComp
$Comp
L GND #PWR016
U 1 1 5B226879
P 6950 5050
F 0 "#PWR016" H 6950 4800 50  0001 C CNN
F 1 "GND" H 6950 4900 50  0000 C CNN
F 2 "" H 6950 5050 50  0001 C CNN
F 3 "" H 6950 5050 50  0001 C CNN
	1    6950 5050
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR017
U 1 1 5B2268C3
P 3600 4850
F 0 "#PWR017" H 3600 4700 50  0001 C CNN
F 1 "+5V" H 3600 4990 50  0000 C CNN
F 2 "" H 3600 4850 50  0001 C CNN
F 3 "" H 3600 4850 50  0001 C CNN
	1    3600 4850
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR018
U 1 1 5B22690F
P 3600 4550
F 0 "#PWR018" H 3600 4300 50  0001 C CNN
F 1 "GND" H 3600 4400 50  0000 C CNN
F 2 "" H 3600 4550 50  0001 C CNN
F 3 "" H 3600 4550 50  0001 C CNN
	1    3600 4550
	0    1    1    0   
$EndComp
$Comp
L GND #PWR019
U 1 1 5B22693D
P 3600 4650
F 0 "#PWR019" H 3600 4400 50  0001 C CNN
F 1 "GND" H 3600 4500 50  0000 C CNN
F 2 "" H 3600 4650 50  0001 C CNN
F 3 "" H 3600 4650 50  0001 C CNN
	1    3600 4650
	0    1    1    0   
$EndComp
$Comp
L GND #PWR020
U 1 1 5B226AE1
P 3000 2700
F 0 "#PWR020" H 3000 2450 50  0001 C CNN
F 1 "GND" H 3000 2550 50  0000 C CNN
F 2 "" H 3000 2700 50  0001 C CNN
F 3 "" H 3000 2700 50  0001 C CNN
	1    3000 2700
	1    0    0    -1  
$EndComp
Text GLabel 6200 4050 2    60   Input ~ 0
D11_MOSI
Text GLabel 6200 4150 2    60   Output ~ 0
D12_MISO
Text GLabel 6200 3950 2    60   Output ~ 0
D10_CS
Text GLabel 6200 4250 2    60   Output ~ 0
D13_SCK
$Comp
L Conn_01x06 J11
U 1 1 5B22D1EA
P 8000 3250
F 0 "J11" H 8000 3550 50  0000 C CNN
F 1 "SPI" H 8000 2850 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-06_06x2.54mm_Straight" H 8000 3250 50  0001 C CNN
F 3 "" H 8000 3250 50  0001 C CNN
	1    8000 3250
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR021
U 1 1 5B22D239
P 7800 3050
F 0 "#PWR021" H 7800 2900 50  0001 C CNN
F 1 "+5V" H 7800 3190 50  0000 C CNN
F 2 "" H 7800 3050 50  0001 C CNN
F 3 "" H 7800 3050 50  0001 C CNN
	1    7800 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR022
U 1 1 5B22D2AD
P 7800 3550
F 0 "#PWR022" H 7800 3300 50  0001 C CNN
F 1 "GND" H 7800 3400 50  0000 C CNN
F 2 "" H 7800 3550 50  0001 C CNN
F 3 "" H 7800 3550 50  0001 C CNN
	1    7800 3550
	1    0    0    -1  
$EndComp
Text GLabel 7800 3150 0    60   Input ~ 0
D10_CS
Text GLabel 7800 3250 0    60   Output ~ 0
D11_MOSI
Text GLabel 7800 3350 0    60   Input ~ 0
D12_MISO
Text GLabel 7800 3450 0    60   Input ~ 0
D13_SCK
$Comp
L SW_Push SW1
U 1 1 5B22D351
P 7750 4000
F 0 "SW1" H 7800 4100 50  0000 L CNN
F 1 "SW_Push" H 7750 3940 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm" H 7750 4200 50  0001 C CNN
F 3 "" H 7750 4200 50  0001 C CNN
	1    7750 4000
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW2
U 1 1 5B22D3E0
P 7750 4300
F 0 "SW2" H 7800 4400 50  0000 L CNN
F 1 "SW_Push" H 7750 4240 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm" H 7750 4500 50  0001 C CNN
F 3 "" H 7750 4500 50  0001 C CNN
	1    7750 4300
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW3
U 1 1 5B22D42D
P 7750 4600
F 0 "SW3" H 7800 4700 50  0000 L CNN
F 1 "SW_Push" H 7750 4540 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm" H 7750 4800 50  0001 C CNN
F 3 "" H 7750 4800 50  0001 C CNN
	1    7750 4600
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW4
U 1 1 5B22D46E
P 7750 4900
F 0 "SW4" H 7800 5000 50  0000 L CNN
F 1 "SW_Push" H 7750 4840 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm" H 7750 5100 50  0001 C CNN
F 3 "" H 7750 5100 50  0001 C CNN
	1    7750 4900
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW5
U 1 1 5B22D4AF
P 7750 5200
F 0 "SW5" H 7800 5300 50  0000 L CNN
F 1 "SW_Push" H 7750 5140 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm" H 7750 5400 50  0001 C CNN
F 3 "" H 7750 5400 50  0001 C CNN
	1    7750 5200
	1    0    0    -1  
$EndComp
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
Wire Wire Line
	7550 3900 7550 5200
Connection ~ 7550 4000
Connection ~ 7550 4300
Connection ~ 7550 4600
Connection ~ 7550 4900
$Comp
L +5V #PWR023
U 1 1 5B22D5BF
P 7550 3900
F 0 "#PWR023" H 7550 3750 50  0001 C CNN
F 1 "+5V" H 7550 4040 50  0000 C CNN
F 2 "" H 7550 3900 50  0001 C CNN
F 3 "" H 7550 3900 50  0001 C CNN
	1    7550 3900
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 5B22D779
P 8100 4000
F 0 "R3" V 8180 4000 50  0000 C CNN
F 1 "R" V 8100 4000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 8030 4000 50  0001 C CNN
F 3 "" H 8100 4000 50  0001 C CNN
	1    8100 4000
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 5B22D7DC
P 8100 4300
F 0 "R4" V 8180 4300 50  0000 C CNN
F 1 "R" V 8100 4300 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 8030 4300 50  0001 C CNN
F 3 "" H 8100 4300 50  0001 C CNN
	1    8100 4300
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 5B22D827
P 8100 4600
F 0 "R5" V 8180 4600 50  0000 C CNN
F 1 "R" V 8100 4600 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 8030 4600 50  0001 C CNN
F 3 "" H 8100 4600 50  0001 C CNN
	1    8100 4600
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 5B22D872
P 8100 4900
F 0 "R6" V 8180 4900 50  0000 C CNN
F 1 "R" V 8100 4900 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 8030 4900 50  0001 C CNN
F 3 "" H 8100 4900 50  0001 C CNN
	1    8100 4900
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 5B22D8B7
P 8100 5200
F 0 "R7" V 8180 5200 50  0000 C CNN
F 1 "R" V 8100 5200 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 8030 5200 50  0001 C CNN
F 3 "" H 8100 5200 50  0001 C CNN
	1    8100 5200
	0    1    1    0   
$EndComp
$Comp
L GND #PWR024
U 1 1 5B22D906
P 8250 5200
F 0 "#PWR024" H 8250 4950 50  0001 C CNN
F 1 "GND" H 8250 5050 50  0000 C CNN
F 2 "" H 8250 5200 50  0001 C CNN
F 3 "" H 8250 5200 50  0001 C CNN
	1    8250 5200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR025
U 1 1 5B22D94A
P 8250 4000
F 0 "#PWR025" H 8250 3750 50  0001 C CNN
F 1 "GND" H 8250 3850 50  0000 C CNN
F 2 "" H 8250 4000 50  0001 C CNN
F 3 "" H 8250 4000 50  0001 C CNN
	1    8250 4000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR026
U 1 1 5B22D98E
P 8250 4300
F 0 "#PWR026" H 8250 4050 50  0001 C CNN
F 1 "GND" H 8250 4150 50  0000 C CNN
F 2 "" H 8250 4300 50  0001 C CNN
F 3 "" H 8250 4300 50  0001 C CNN
	1    8250 4300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR027
U 1 1 5B22D9D2
P 8250 4600
F 0 "#PWR027" H 8250 4350 50  0001 C CNN
F 1 "GND" H 8250 4450 50  0000 C CNN
F 2 "" H 8250 4600 50  0001 C CNN
F 3 "" H 8250 4600 50  0001 C CNN
	1    8250 4600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR028
U 1 1 5B22DA16
P 8250 4900
F 0 "#PWR028" H 8250 4650 50  0001 C CNN
F 1 "GND" H 8250 4750 50  0000 C CNN
F 2 "" H 8250 4900 50  0001 C CNN
F 3 "" H 8250 4900 50  0001 C CNN
	1    8250 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 4000 7950 4200
Wire Wire Line
	7950 4200 8400 4200
Wire Wire Line
	7950 4300 7950 4500
Wire Wire Line
	7950 4500 8400 4500
Wire Wire Line
	7950 4600 7950 4800
Wire Wire Line
	7950 4800 8400 4800
Wire Wire Line
	7950 4900 7950 5100
Wire Wire Line
	7950 5100 8400 5100
Wire Wire Line
	7950 5200 7950 5400
Wire Wire Line
	7950 5400 8400 5400
Text GLabel 8400 4200 2    60   Output ~ 0
D10_CS
Text GLabel 8400 4500 2    60   Output ~ 0
D11_MOSI
Text GLabel 8400 4800 2    60   Output ~ 0
D12_MISO
Text GLabel 8400 5100 2    60   Output ~ 0
D13_SCK
Text GLabel 8400 5400 2    60   Output ~ 0
D2
Text GLabel 6200 3150 2    60   Input ~ 0
D2
$EndSCHEMATC
