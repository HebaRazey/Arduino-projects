Introduction:

In industrial environments, two of the most common hazards are excessive heat and gas leaks. If left unmonitored, these can cause equipment failure, fire, or serious accidents. Manual monitoring is slow and unreliable. This project solves that problem by combining two transducers, a temperature sensor and a gas sensor, to automatically control a cooling fan and trigger a warning when danger is detected.

Components Used:

 -LM35
 -MQ-2 module
 -L293D IC or motor driver module
 -I2C LCD 
 -Small DC fan/ DC motor
 -Jumping wires
 -Breadboard

 Working:

 
•	Arduino reads gas level from MQ-2 as an ADC value (0 to 1023).
•	If gas value exceeds 300: fan runs at full speed (PWM = 255) and LED turns ON.
•	If no gas detected: fan speed is set according to temperature thresholds.
•	Arduino reads temperature from LM35 and converts it to Celsius using the voltage formula.
•	A simple averaging filter reduces noise: Temperature = (Current Reading + Last Reading) / 2.
•	LCD is refreshed every second with updated temperature, gas value, and fan status.

TinkerCAD simulation link:

https://www.tinkercad.com/things/l8tC1CcQ3Kc-temperature-and-gas-controlled-dc-fan
