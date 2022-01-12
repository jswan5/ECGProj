/******************************************************************************
Heart_Rate_Display.ino
Demo Program for AD8232 Heart Rate sensor.
Casey Kuhns @ SparkFun Electronics
6/27/2014
https://github.com/sparkfun/AD8232_Heart_Rate_Monitor
The AD8232 Heart Rate sensor is a low cost EKG/ECG sensor.  This example shows
how to create an ECG with real time display.  The display is using Processing.
This sketch is based heavily on the Graphing Tutorial provided in the Arduino
IDE. http://www.arduino.cc/en/Tutorial/Graph


ECG Electrode Placement:
RA: Red
LA: Yellow
GND: Green
******************************************************************************/
int sensorPin = A0;        //pin number to use the ADC
int sensorValue = 0;      //initialization of sensor variable, equivalent to EMA Y

//   EMA_a tested values:
//    >1.5 completely useless
//    0.8 good waveform, very susceptible to noise
//    0.7 solid waveform, quite susceptible to noise
//    0.6 acceptable QRS, susceptible to some noise
//    0.3 very susceptible to movement
//    0.1 isoelectric drift, but robust R
//    0.095
//    0.08 lots of isoelectric drift, weak R
//    0.05 massive isoelectric drift, weak R
//    0.001 quite a delay in reaching steady state, weak R


 
float EMA_a = 0.05;      //initialization of EMA alpha -> lower values = more smoothing (and rejection)
float EMA_S = 0.0;           //initialization of EMA S
 
void setup() {
  // initialize the serial communication:
  Serial.begin(19200);
     
  }

void loop() {
    // send the value of analog input 0:
  

  sensorValue = analogRead(sensorPin);    //read the sensor value using ADC
   
  EMA_S = (EMA_a*sensorValue) + ((1-EMA_a)*EMA_S);    //run the EMA

  //Serial.println(sensorPin);
  Serial.println(EMA_S);
  //Serial.println(EMA_a);
  
    //Wait for a bit to keep serial data from saturating
  delay(10);
}
