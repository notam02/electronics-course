/*  LDR-Servo
 *  
 *  Example for controlling a servo motor using an external sensor
 *  
 *  by NOTAM <http://notam02.no>
 *  
 *  based on:
 *  http://arduino.cc/en/Tutorial/Sweep
 *
 *   This code is in the public domain.
 *  
 *  
 *  How to use this example:
 *  As external sensor, an LDR (light dependend resistor) can be used.
 *  The LDR can be connected between <sensorPin> and GND.
 *  The PWM input of the servo is connected to <servoPIN>
 *  
*/ 

#include <Servo.h> 
#include <ADC.h>

 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards


const int sensorPin = A8; // The analog input pin, connected to the LDR
const int servoPin = 23; // The PWM output, connected to the servo


ADC *adc = new ADC(); // adc object;
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{
  // Initialise servo 
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object 

  // Initialise analog input
  // Enable pullup, so we can connect the LDR between the input pin and GND
  pinMode(sensorPin, INPUT_PULLUP);

  // Initialise Analog-to-Digital converter
  adc->setAveraging(16); // set number of averages
  adc->setResolution(16); // set bits of resolution
  adc->setConversionSpeed(ADC_CONVERSION_SPEED::VERY_LOW_SPEED); // change the conversion speed
  adc->setSamplingSpeed(ADC_SAMPLING_SPEED::MED_SPEED); // change the sampling speed
} 



void loop() 
{ 
  long value;

  // Read the analog input
  value = (unsigned long)adc->analogRead(sensorPin); // read a new value, will return ADC_ERROR_VALUE if the comparison is false.

  // Calculate a position between 0 and 180
  pos = value / ( 65536 / 180);
    
  myservo.write(pos);              // tell servo to go to position in variable 'pos' 
  delay(15);                       // waits 15ms for the servo to reach the position 
} 
