Features implemented:
1. Temperature monitoring using DS18B20
2. 5 heater control states: IDLE, Heating, Stabilizing, Target reached and Overheat
3. Real time serial logging of temperature and state
4. Heater Status using an LED

Components Used:
1. Arduino Uno
2. DS18B20 Sensor
3. LED
4. Resistors(4.7kohms and 220ohms)

How to use:
1. Open the simulation in Wokwi
2. Press Run button
3. Click on DS18B20 sensor and change the temperature
4. Watch LED behaiviour and serial monitor for real time status

State Logic:
1. Below 25 deg Celsius = System State(IDLE)
2. 25 deg Celsius to 37 deg celsius = System State(Heating)
3. 37 deg Celsius to 40 deg celsius = System State(Stabilizing)
4. 40 deg Celsius to 59.9 deg celsius = System State(Target Reached)
5. 60 deg celsius and above = System State(Overheat)

How it works
1. The DS18B20 sensor reads temperature every second
2. Based on the reading, the system decides the heater state
3. The heater (LED) turns ON or OFF accordingly
4. The current temperature and state are logged to the Serial Monitor
