EESchema Schematic File Version 4
LIBS:electronic_load-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 4700 1500 650  300 
U 5E84C446
F0 "Power Supply" 50
F1 "psu.sch" 50
F2 "12V" I L 4700 1600 50 
F3 "GND" I L 4700 1700 50 
F4 "3.3V" O R 5350 1700 50 
$EndSheet
$Sheet
S 6600 1400 1050 650 
U 5E88D5A3
F0 "Variable Load" 50
F1 "load.sch" 50
F2 "GND" I L 6600 1700 50 
F3 "Iset" I L 6600 1800 50 
F4 "Vload" I R 7650 1500 50 
F5 "3.3V" I L 6600 1600 50 
F6 "CURRENT_SENSE" O R 7650 1600 50 
F7 "12V" I L 6600 1500 50 
F8 "Enable_load" I L 6600 1900 50 
$EndSheet
$Comp
L power:GND #PWR01
U 1 1 5E8B2ED1
P 4600 1750
F 0 "#PWR01" H 4600 1500 50  0001 C CNN
F 1 "GND" H 4605 1577 50  0000 C CNN
F 2 "" H 4600 1750 50  0001 C CNN
F 3 "" H 4600 1750 50  0001 C CNN
	1    4600 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 1700 4600 1700
Wire Wire Line
	4600 1700 4600 1750
$Comp
L power:GND #PWR02
U 1 1 5E8B367B
P 6150 1750
F 0 "#PWR02" H 6150 1500 50  0001 C CNN
F 1 "GND" H 6155 1577 50  0000 C CNN
F 2 "" H 6150 1750 50  0001 C CNN
F 3 "" H 6150 1750 50  0001 C CNN
	1    6150 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 1700 6150 1750
$Sheet
S 5850 2850 1000 1500
U 5E8C4072
F0 "MCU" 50
F1 "mcu.sch" 50
F2 "RESET" I R 6850 3350 50 
F3 "DTR" I L 5850 3650 50 
F4 "GND" I L 5850 3050 50 
F5 "MOSI" I R 6850 3150 50 
F6 "MISO" I R 6850 2950 50 
F7 "SCK" I R 6850 3050 50 
F8 "SCL" I L 5850 3200 50 
F9 "SDA" I L 5850 3300 50 
F10 "UART_RX" I L 5850 3450 50 
F11 "UART_TX" I L 5850 3550 50 
F12 "3.3V" I L 5850 2950 50 
F13 "PWM_OUT" I L 5850 3800 50 
F14 "CURRENT_IN" I L 5850 3900 50 
F15 "VOLTAGE_IN" I L 5850 4000 50 
F16 "BUTTON1" I R 6850 3500 50 
F17 "BUTTON2" I R 6850 3600 50 
F18 "BUTTON3" I R 6850 3700 50 
F19 "BUTTON4" I R 6850 3800 50 
F20 "Enable" O R 6850 3900 50 
F21 "SPEAKER_DRIVE" O R 6850 4100 50 
F22 "ONE_WIRE_BUS" B R 6850 4200 50 
$EndSheet
Wire Wire Line
	5350 1700 5450 1700
$Comp
L power:GND #PWR03
U 1 1 5E8D3E7B
P 5550 3100
F 0 "#PWR03" H 5550 2850 50  0001 C CNN
F 1 "GND" H 5555 2927 50  0000 C CNN
F 2 "" H 5550 3100 50  0001 C CNN
F 3 "" H 5550 3100 50  0001 C CNN
	1    5550 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 3100 5550 3050
Wire Wire Line
	5550 3050 5850 3050
$Comp
L conn:CONN_01X02 P1
U 1 1 5E9455F0
P 3100 1650
F 0 "P1" H 3017 1285 50  0000 C CNN
F 1 "Power connector" H 3017 1376 50  0000 C CNN
F 2 "Connectors_JST:JST_XH_B02B-XH-A_02x2.50mm_Straight" H 3017 1467 50  0000 C CNN
F 3 "" H 3100 1650 50  0000 C CNN
	1    3100 1650
	-1   0    0    1   
$EndComp
Connection ~ 4600 1700
$Comp
L Connector:Conn_01x06_Male J2
U 1 1 5E974FD9
P 7800 3150
F 0 "J2" H 7772 3124 50  0000 R CNN
F 1 "SPI" H 7772 3033 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03" H 7800 3150 50  0001 C CNN
F 3 "~" H 7800 3150 50  0001 C CNN
	1    7800 3150
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7600 2950 6850 2950
Wire Wire Line
	6850 3050 7300 3050
Wire Wire Line
	7300 3050 7300 3150
Wire Wire Line
	7300 3150 7600 3150
Wire Wire Line
	6850 3150 7200 3150
Wire Wire Line
	7200 3150 7200 3250
Wire Wire Line
	7200 3250 7600 3250
Wire Wire Line
	6850 3350 7600 3350
$Comp
L Connector:Conn_01x04_Male J3
U 1 1 5E97CFA3
P 5150 3550
F 0 "J3" H 5258 3831 50  0000 C CNN
F 1 "UART" H 5258 3740 50  0000 C CNN
F 2 "Connectors_JST:JST_XH_B04B-XH-A_04x2.50mm_Straight" H 5150 3550 50  0001 C CNN
F 3 "~" H 5150 3550 50  0001 C CNN
	1    5150 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3450 5350 3450
Wire Wire Line
	5850 3550 5350 3550
Wire Wire Line
	5350 3650 5850 3650
$Comp
L power:GND #PWR016
U 1 1 5E97F0FD
P 5450 3850
F 0 "#PWR016" H 5450 3600 50  0001 C CNN
F 1 "GND" H 5455 3677 50  0000 C CNN
F 2 "" H 5450 3850 50  0001 C CNN
F 3 "" H 5450 3850 50  0001 C CNN
	1    5450 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5E97F2BA
P 7500 3550
F 0 "#PWR015" H 7500 3300 50  0001 C CNN
F 1 "GND" H 7505 3377 50  0000 C CNN
F 2 "" H 7500 3550 50  0001 C CNN
F 3 "" H 7500 3550 50  0001 C CNN
	1    7500 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 3450 7500 3450
Wire Wire Line
	7500 3450 7500 3550
Wire Wire Line
	5350 3750 5450 3750
Wire Wire Line
	5450 3750 5450 3850
$Comp
L Switch:SW_Push SW2
U 1 1 5E983678
P 7200 4400
AR Path="/5E983678" Ref="SW2"  Part="1" 
AR Path="/5DBD1084/5E983678" Ref="SW?"  Part="1" 
AR Path="/5E8C4072/5E983678" Ref="SW?"  Part="1" 
F 0 "SW2" H 7200 4685 50  0000 C CNN
F 1 "Back" H 7200 4594 50  0000 C CNN
F 2 "Extra:Switch" H 7200 4600 50  0001 C CNN
F 3 "" H 7200 4600 50  0001 C CNN
	1    7200 4400
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 5E983D5E
P 7600 4400
AR Path="/5E983D5E" Ref="SW3"  Part="1" 
AR Path="/5DBD1084/5E983D5E" Ref="SW?"  Part="1" 
AR Path="/5E8C4072/5E983D5E" Ref="SW?"  Part="1" 
F 0 "SW3" H 7600 4685 50  0000 C CNN
F 1 "Down" H 7600 4594 50  0000 C CNN
F 2 "Extra:Switch" H 7600 4600 50  0001 C CNN
F 3 "" H 7600 4600 50  0001 C CNN
	1    7600 4400
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 5E9844E7
P 8000 4400
AR Path="/5E9844E7" Ref="SW4"  Part="1" 
AR Path="/5DBD1084/5E9844E7" Ref="SW?"  Part="1" 
AR Path="/5E8C4072/5E9844E7" Ref="SW?"  Part="1" 
F 0 "SW4" H 8000 4685 50  0000 C CNN
F 1 "Up" H 8000 4594 50  0000 C CNN
F 2 "Extra:Switch" H 8000 4600 50  0001 C CNN
F 3 "" H 8000 4600 50  0001 C CNN
	1    8000 4400
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push SW5
U 1 1 5E984B8C
P 8400 4400
AR Path="/5E984B8C" Ref="SW5"  Part="1" 
AR Path="/5DBD1084/5E984B8C" Ref="SW?"  Part="1" 
AR Path="/5E8C4072/5E984B8C" Ref="SW?"  Part="1" 
F 0 "SW5" H 8400 4685 50  0000 C CNN
F 1 "Enter" H 8400 4594 50  0000 C CNN
F 2 "Extra:Switch" H 8400 4600 50  0001 C CNN
F 3 "" H 8400 4600 50  0001 C CNN
	1    8400 4400
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5E9889ED
P 8500 1750
F 0 "#PWR013" H 8500 1500 50  0001 C CNN
F 1 "GND" H 8505 1577 50  0000 C CNN
F 2 "" H 8500 1750 50  0001 C CNN
F 3 "" H 8500 1750 50  0001 C CNN
	1    8500 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 1600 8500 1600
Wire Wire Line
	8500 1600 8500 1750
Wire Wire Line
	6150 1700 6600 1700
Wire Wire Line
	7400 3500 7400 3950
Wire Wire Line
	7400 3950 8400 3950
Wire Wire Line
	8400 3950 8400 4200
Wire Wire Line
	7350 3600 7350 4000
Wire Wire Line
	7350 4000 8000 4000
Wire Wire Line
	8000 4000 8000 4200
Wire Wire Line
	7300 3700 7300 4050
Wire Wire Line
	7300 4050 7600 4050
Wire Wire Line
	7600 4050 7600 4200
Wire Wire Line
	7200 3800 7200 4200
$Comp
L power:GND #PWR017
U 1 1 5E9F2103
P 7800 4750
F 0 "#PWR017" H 7800 4500 50  0001 C CNN
F 1 "GND" H 7805 4577 50  0000 C CNN
F 2 "" H 7800 4750 50  0001 C CNN
F 3 "" H 7800 4750 50  0001 C CNN
	1    7800 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 4750 7800 4650
Wire Wire Line
	7800 4650 8000 4650
Wire Wire Line
	8000 4650 8000 4600
Wire Wire Line
	8000 4650 8400 4650
Wire Wire Line
	8400 4650 8400 4600
Connection ~ 8000 4650
Wire Wire Line
	7800 4650 7600 4650
Wire Wire Line
	7600 4650 7600 4600
Connection ~ 7800 4650
Wire Wire Line
	7600 4650 7200 4650
Wire Wire Line
	7200 4650 7200 4600
Connection ~ 7600 4650
Wire Wire Line
	7650 1500 8200 1500
$Comp
L Device:R R3
U 1 1 5EA84508
P 8200 1750
F 0 "R3" H 8270 1796 50  0000 L CNN
F 1 "22k" H 8270 1705 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 8130 1750 50  0001 C CNN
F 3 "~" H 8200 1750 50  0001 C CNN
	1    8200 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 1500 8200 1600
Connection ~ 8200 1500
Wire Wire Line
	8200 1500 8650 1500
$Comp
L Device:R R4
U 1 1 5EA8608E
P 8200 2200
F 0 "R4" H 8270 2246 50  0000 L CNN
F 1 "2k" H 8270 2155 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 8130 2200 50  0001 C CNN
F 3 "~" H 8200 2200 50  0001 C CNN
	1    8200 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR014
U 1 1 5EA8632B
P 8200 2450
F 0 "#PWR014" H 8200 2200 50  0001 C CNN
F 1 "GND" H 8205 2277 50  0000 C CNN
F 2 "" H 8200 2450 50  0001 C CNN
F 3 "" H 8200 2450 50  0001 C CNN
	1    8200 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 2450 8200 2350
Text GLabel 6350 1600 0    50   Input ~ 0
3.3V
Wire Wire Line
	6350 1600 6600 1600
Text GLabel 6350 1500 0    50   Input ~ 0
12V
Wire Wire Line
	6350 1500 6600 1500
Text GLabel 6450 1800 0    50   Input ~ 0
Iset
Wire Wire Line
	6600 1800 6450 1800
Text GLabel 5700 3800 0    50   Input ~ 0
Iset
Wire Wire Line
	5850 3800 5700 3800
Text GLabel 7600 3050 0    50   Input ~ 0
3.3V
Wire Wire Line
	8200 1900 8200 1950
Text GLabel 5450 1700 2    50   Input ~ 0
3.3V
Text GLabel 5700 2950 0    50   Input ~ 0
3.3V
Wire Wire Line
	5850 2950 5700 2950
Text GLabel 7800 1700 3    50   Input ~ 0
CURRENT_SENSE
Wire Wire Line
	7800 1600 7800 1700
Wire Wire Line
	7650 1600 7800 1600
Text GLabel 8000 2000 3    50   Input ~ 0
VOLTAGE_SENSE
Wire Wire Line
	8200 1950 8000 1950
Wire Wire Line
	8000 1950 8000 2000
Connection ~ 8200 1950
Wire Wire Line
	8200 1950 8200 2050
Text GLabel 5650 4150 3    50   Input ~ 0
CURRENT_SENSE
Text GLabel 5750 4150 3    50   Input ~ 0
VOLTAGE_SENSE
Wire Wire Line
	5850 4000 5750 4000
Wire Wire Line
	5750 4000 5750 4150
Wire Wire Line
	5850 3900 5650 3900
Wire Wire Line
	5650 3900 5650 4150
Text GLabel 5850 3200 0    50   Input ~ 0
SCL
Text GLabel 5850 3300 0    50   Input ~ 0
SDA
$Comp
L conn:CONN_01X04 P2
U 1 1 5E9B109E
P 9500 4800
F 0 "P2" V 9326 4562 50  0000 R CNN
F 1 "LCD" V 9417 4562 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" V 9508 4562 50  0000 R CNN
F 3 "" H 9500 4800 50  0000 C CNN
	1    9500 4800
	1    0    0    1   
$EndComp
Text GLabel 9300 4950 0    50   Input ~ 0
3.3V
Text GLabel 9300 4850 0    50   Input ~ 0
GND
Text GLabel 9300 4750 0    50   Input ~ 0
SCL
Text GLabel 9300 4650 0    50   Input ~ 0
SDA
Text GLabel 4400 1350 1    50   Input ~ 0
12V
Wire Wire Line
	4400 1350 4400 1600
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 5EA11A4E
P 1950 2800
F 0 "H1" H 2050 2849 50  0000 L CNN
F 1 "LCD Mount" H 2050 2758 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_Pad" H 1950 2800 50  0001 C CNN
F 3 "~" H 1950 2800 50  0001 C CNN
	1    1950 2800
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 5EA12B54
P 2600 2800
F 0 "H2" H 2700 2849 50  0000 L CNN
F 1 "LCD Mount" H 2700 2758 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_Pad" H 2600 2800 50  0001 C CNN
F 3 "~" H 2600 2800 50  0001 C CNN
	1    2600 2800
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H3
U 1 1 5EA144D4
P 3200 2800
F 0 "H3" H 3300 2849 50  0000 L CNN
F 1 "LCD Mount" H 3300 2758 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_Pad" H 3200 2800 50  0001 C CNN
F 3 "~" H 3200 2800 50  0001 C CNN
	1    3200 2800
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H4
U 1 1 5EA15CCA
P 3800 2800
F 0 "H4" H 3900 2849 50  0000 L CNN
F 1 "LCD Mount" H 3900 2758 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_Pad" H 3800 2800 50  0001 C CNN
F 3 "~" H 3800 2800 50  0001 C CNN
	1    3800 2800
	1    0    0    -1  
$EndComp
Text GLabel 2900 3100 3    50   Input ~ 0
GND
Wire Wire Line
	2600 2900 2600 3000
Wire Wire Line
	2600 3000 2900 3000
Wire Wire Line
	2900 3000 2900 3100
Wire Wire Line
	3200 2900 3200 3000
Wire Wire Line
	3200 3000 2900 3000
Connection ~ 2900 3000
Wire Wire Line
	3800 2900 3800 3000
Wire Wire Line
	3800 3000 3200 3000
Connection ~ 3200 3000
Wire Wire Line
	2600 3000 1950 3000
Wire Wire Line
	1950 3000 1950 2900
Connection ~ 2600 3000
$Comp
L Mechanical:MountingHole_Pad H5
U 1 1 5EA64BFA
P 1950 3650
F 0 "H5" H 2050 3699 50  0000 L CNN
F 1 "PCB Mount" H 2050 3608 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad" H 1950 3650 50  0001 C CNN
F 3 "~" H 1950 3650 50  0001 C CNN
	1    1950 3650
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H6
U 1 1 5EA6713F
P 2600 3650
F 0 "H6" H 2700 3699 50  0000 L CNN
F 1 "PCB Mount" H 2700 3608 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad" H 2600 3650 50  0001 C CNN
F 3 "~" H 2600 3650 50  0001 C CNN
	1    2600 3650
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H7
U 1 1 5EA6B1C6
P 3200 3650
F 0 "H7" H 3300 3699 50  0000 L CNN
F 1 "PCB Mount" H 3300 3608 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad" H 3200 3650 50  0001 C CNN
F 3 "~" H 3200 3650 50  0001 C CNN
	1    3200 3650
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H8
U 1 1 5EA6CF74
P 3800 3650
F 0 "H8" H 3900 3699 50  0000 L CNN
F 1 "PCB Mount" H 3900 3608 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad" H 3800 3650 50  0001 C CNN
F 3 "~" H 3800 3650 50  0001 C CNN
	1    3800 3650
	1    0    0    -1  
$EndComp
Text GLabel 2900 3950 3    50   Input ~ 0
GND
Wire Wire Line
	2600 3750 2600 3850
Wire Wire Line
	2600 3850 2900 3850
Wire Wire Line
	2900 3850 2900 3950
Wire Wire Line
	3200 3750 3200 3850
Wire Wire Line
	3200 3850 2900 3850
Connection ~ 2900 3850
Wire Wire Line
	3800 3750 3800 3850
Wire Wire Line
	3800 3850 3200 3850
Connection ~ 3200 3850
Wire Wire Line
	2600 3850 1950 3850
Wire Wire Line
	1950 3850 1950 3750
Connection ~ 2600 3850
Connection ~ 4400 1600
Wire Wire Line
	4400 1600 4700 1600
Text GLabel 6600 1900 0    50   Input ~ 0
Enable
Text GLabel 6850 3900 2    50   Input ~ 0
Enable
$Comp
L Device:Speaker LS1
U 1 1 5EAAF924
P 2500 4900
F 0 "LS1" H 2670 4896 50  0000 L CNN
F 1 "Speaker" H 2670 4805 50  0000 L CNN
F 2 "Buzzer_Beeper:MagneticBuzzer_ProSignal_ABT-410-RC" H 2500 4700 50  0001 C CNN
F 3 "~" H 2490 4850 50  0001 C CNN
	1    2500 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R19
U 1 1 5EAB5D59
P 2200 5600
F 0 "R19" H 2270 5646 50  0000 L CNN
F 1 "120R" H 2270 5555 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 2130 5600 50  0001 C CNN
F 3 "~" H 2200 5600 50  0001 C CNN
	1    2200 5600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5EAB62B5
P 2200 6250
F 0 "#PWR0106" H 2200 6000 50  0001 C CNN
F 1 "GND" H 2205 6077 50  0000 C CNN
F 2 "" H 2200 6250 50  0001 C CNN
F 3 "" H 2200 6250 50  0001 C CNN
	1    2200 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 5750 2200 5800
Wire Wire Line
	2200 5000 2300 5000
Wire Wire Line
	6850 3500 7400 3500
Wire Wire Line
	6850 3600 7350 3600
Wire Wire Line
	6850 3700 7300 3700
Wire Wire Line
	6850 3800 7200 3800
$Comp
L Fairchild:FDV303N U?
U 1 1 5EAE33D7
P 2200 6000
AR Path="/5E88D5A3/5EAE33D7" Ref="U?"  Part="1" 
AR Path="/5EAE33D7" Ref="U8"  Part="1" 
F 0 "U8" H 2298 6046 50  0000 L CNN
F 1 "FDV303N" H 2298 5955 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 2200 6000 50  0001 L BNN
F 3 "" H 2200 6000 50  0001 C CNN
	1    2200 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 6200 2200 6250
Text GLabel 1750 4900 0    50   Input ~ 0
3.3V
Wire Wire Line
	1750 4900 1850 4900
Wire Wire Line
	6850 4100 6950 4100
Text GLabel 6700 4650 0    50   Input ~ 0
SPEAKER_DRIVE
Text GLabel 1900 6100 0    50   Input ~ 0
SPEAKER_DRIVE
Wire Wire Line
	1900 6100 2000 6100
Wire Wire Line
	3300 1600 4000 1600
Wire Wire Line
	3300 1700 4600 1700
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5EB64EB3
P 4000 1350
F 0 "#FLG0101" H 4000 1425 50  0001 C CNN
F 1 "PWR_FLAG" H 4000 1523 50  0000 C CNN
F 2 "" H 4000 1350 50  0001 C CNN
F 3 "~" H 4000 1350 50  0001 C CNN
	1    4000 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 1350 4000 1600
Connection ~ 4000 1600
Wire Wire Line
	4000 1600 4400 1600
Wire Wire Line
	6950 4650 6700 4650
Wire Wire Line
	6950 4100 6950 4650
Wire Wire Line
	6850 4200 6900 4200
Wire Wire Line
	6900 4200 6900 4550
Wire Wire Line
	6900 4550 6700 4550
Text GLabel 6700 4550 0    50   Input ~ 0
ONE_WIRE
$Comp
L conn:CONN_01X03 P3
U 1 1 5EB950BD
P 4450 5200
F 0 "P3" H 4367 4785 50  0000 C CNN
F 1 "One Wire" H 4367 4876 50  0000 C CNN
F 2 "Connectors_JST:JST_XH_B03B-XH-A_03x2.50mm_Straight" H 4367 4967 50  0000 C CNN
F 3 "" H 4450 5200 50  0000 C CNN
	1    4450 5200
	1    0    0    1   
$EndComp
Text GLabel 3600 5200 0    50   Input ~ 0
ONE_WIRE
$Comp
L power:GND #PWR0109
U 1 1 5EBA1EFB
P 4000 5350
F 0 "#PWR0109" H 4000 5100 50  0001 C CNN
F 1 "GND" H 4005 5177 50  0000 C CNN
F 2 "" H 4000 5350 50  0001 C CNN
F 3 "" H 4000 5350 50  0001 C CNN
	1    4000 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 5350 4000 5300
Wire Wire Line
	4000 5300 4100 5300
Text GLabel 3600 5100 0    50   Input ~ 0
3.3V
$Comp
L Device:C C19
U 1 1 5EBD4EFD
P 3700 5450
F 0 "C19" H 3815 5496 50  0000 L CNN
F 1 "100n" H 3815 5405 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3738 5300 50  0001 C CNN
F 3 "~" H 3700 5450 50  0001 C CNN
	1    3700 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 5100 3700 5300
$Comp
L power:GND #PWR04
U 1 1 5EBDAA01
P 3700 5650
F 0 "#PWR04" H 3700 5400 50  0001 C CNN
F 1 "GND" H 3705 5477 50  0000 C CNN
F 2 "" H 3700 5650 50  0001 C CNN
F 3 "" H 3700 5650 50  0001 C CNN
	1    3700 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 5650 3700 5600
Wire Wire Line
	3600 5100 3700 5100
Connection ~ 3700 5100
Wire Wire Line
	3600 5200 4150 5200
$Comp
L Device:C C20
U 1 1 5EBEC0DE
P 1850 5150
F 0 "C20" H 1965 5196 50  0000 L CNN
F 1 "100n" H 1965 5105 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 1888 5000 50  0001 C CNN
F 3 "~" H 1850 5150 50  0001 C CNN
	1    1850 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 4900 1850 5000
Wire Wire Line
	1850 4900 2300 4900
Connection ~ 1850 4900
$Comp
L power:GND #PWR05
U 1 1 5EBFE8A1
P 1850 5350
F 0 "#PWR05" H 1850 5100 50  0001 C CNN
F 1 "GND" H 1855 5177 50  0000 C CNN
F 2 "" H 1850 5350 50  0001 C CNN
F 3 "" H 1850 5350 50  0001 C CNN
	1    1850 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 5350 1850 5300
$Comp
L diode:BZX84Cxx D7
U 1 1 5E9E36EA
P 8500 2250
F 0 "D7" V 8454 2329 50  0000 L CNN
F 1 "BZX84Cxx" V 8545 2329 50  0000 L CNN
F 2 "Diode_SMD:D_SOT-23_ANK" H 8500 2075 50  0001 C CNN
F 3 "https://diotec.com/tl_files/diotec/files/pdf/datasheets/bzx84c2v4.pdf" H 8500 2250 50  0001 C CNN
	1    8500 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	8200 1950 8500 1950
Wire Wire Line
	8500 1950 8500 2100
Wire Wire Line
	8500 2400 8500 2450
Wire Wire Line
	8500 2450 8200 2450
Connection ~ 8200 2450
$Comp
L Device:C C21
U 1 1 5EA8651E
P 2600 5600
F 0 "C21" H 2715 5646 50  0000 L CNN
F 1 "100n" H 2715 5555 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2638 5450 50  0001 C CNN
F 3 "~" H 2600 5600 50  0001 C CNN
	1    2600 5600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR020
U 1 1 5EA86C6E
P 2600 5800
F 0 "#PWR020" H 2600 5550 50  0001 C CNN
F 1 "GND" H 2605 5627 50  0000 C CNN
F 2 "" H 2600 5800 50  0001 C CNN
F 3 "" H 2600 5800 50  0001 C CNN
	1    2600 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 5800 2600 5750
Wire Wire Line
	2600 5450 2600 5300
Wire Wire Line
	2600 5300 2200 5300
Wire Wire Line
	2200 5300 2200 5450
Wire Wire Line
	2200 5000 2200 5300
Connection ~ 2200 5300
$Comp
L conn:CONN_01X03 P5
U 1 1 5EA456FC
P 4600 5850
F 0 "P5" H 4500 5500 50  0000 C CNN
F 1 "One Wire" H 4500 5600 50  0000 C CNN
F 2 "Connectors_JST:JST_XH_B03B-XH-A_03x2.50mm_Straight" H 4600 6100 50  0000 C CNN
F 3 "" H 4600 5850 50  0000 C CNN
	1    4600 5850
	1    0    0    1   
$EndComp
Wire Wire Line
	4100 5300 4100 5950
Wire Wire Line
	4100 5950 4400 5950
Connection ~ 4100 5300
Wire Wire Line
	4150 5200 4150 5850
Wire Wire Line
	4150 5850 4400 5850
Connection ~ 4150 5200
Wire Wire Line
	4200 5750 4400 5750
Wire Wire Line
	3700 5100 4200 5100
Wire Wire Line
	4150 5200 4250 5200
Wire Wire Line
	4100 5300 4250 5300
Wire Wire Line
	4200 5100 4200 5750
Connection ~ 4200 5100
Wire Wire Line
	4200 5100 4250 5100
$Comp
L conn:CONN_01X03 P6
U 1 1 5EA7E137
P 4600 6550
F 0 "P6" H 4500 6200 50  0000 C CNN
F 1 "One Wire" H 4500 6300 50  0000 C CNN
F 2 "Connectors_JST:JST_XH_B03B-XH-A_03x2.50mm_Straight" H 4600 6800 50  0000 C CNN
F 3 "" H 4600 6550 50  0000 C CNN
	1    4600 6550
	1    0    0    1   
$EndComp
Wire Wire Line
	4100 5950 4100 6650
Wire Wire Line
	4100 6650 4400 6650
Connection ~ 4100 5950
Wire Wire Line
	4150 5850 4150 6550
Wire Wire Line
	4150 6550 4400 6550
Connection ~ 4150 5850
Wire Wire Line
	4200 5750 4200 6450
Wire Wire Line
	4200 6450 4400 6450
Connection ~ 4200 5750
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5E987F12
P 8850 1600
F 0 "J1" H 8930 1592 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 8930 1501 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MKDS-1,5-2-5.08_1x02_P5.08mm_Horizontal" H 8850 1600 50  0001 C CNN
F 3 "~" H 8850 1600 50  0001 C CNN
	1    8850 1600
	1    0    0    1   
$EndComp
$EndSCHEMATC
