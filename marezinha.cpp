#include <Arduino.h>

#define PIN_OUT_PWM_MOTOR_RIGHT 0
#define PIN_OUT_PWM_MOTOR_LEFT 0

#define PIN_OUT_CHARGE_SENSOR 0

#define PIN_IN_CONTROL_1 0
#define PIN_IN_CONTROL_2 0

#define PIN_OUT_CONTROL_ERROR 0
#define PIN_OUT_BUZZER 0 
#define PIN_OUT_HEADLIGHT 0
#define PIN_CURRENT_SENSOR 0

#define PIN_SHUTDOWN 0


void setup ()
{
  Serial.begin(9600);
  pinMode(PIN_OUT_PWM_MOTOR_RIGHT , OUTPUT);
  pinMode(PIN_OUT_PWM_MOTOR_LEFT , OUTPUT);
  pinMode(PIN_OUT_CHARGE_SENSOR , OUTPUT);
  
  pinMode(PIN_IN_CONTROL_1 , INPUT);
  pinMode(PIN_IN_CONTROL_2 , INPUT);

  pinMode(PIN_OUT_CONTROL_ERROR , OUTPUT);
  pinMode(PIN_OUT_BUZZER , OUTPUT);
  pinMode(PIN_OUT_HEADLIGHT, OUTPUT);

  pinMode(PIN_CURRENT_SENSOR, INPUT);

  pinMode(PIN_SHUTDOWN, OUTPUT);
}

bool controlStatus = false;


void moviment ()
{
  
}

void check_control ()
{
  while (controlStatus == false)
  {

    if ()
      controlStatus = true;
  }

}

void loop () 
{
  
}

