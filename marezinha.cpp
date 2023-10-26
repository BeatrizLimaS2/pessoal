#include <Arduino.h>

#define PIN_OUT_PWM_MOTOR_RIGHT 0
#define PIN_OUT_PWM_MOTOR_LEFT 0

#define PIN_OUT_CHARGE_SENSOR 0

#define PIN_IN_CONTROL_FORWARD_BACKWARD 0
#define PIN_IN_CONTROL_LEFT_RIGHT 0
#define PIN_IN_CONTROL_UP_DOWN 0

#define PIN_OUT_CONTROL_ERROR 0
#define PIN_OUT_BUZZER 0
#define PIN_OUT_HEADLIGHT 0
#define PIN_CURRENT_SENSOR 0

#define PIN_SHUTDOWN 0


void setup ()
{
  Serial.begin(9600);
  pinMode(PIN_OUT_PWM_MOTOR_RIGHT, OUTPUT);
  pinMode(PIN_OUT_PWM_MOTOR_LEFT, OUTPUT);
  pinMode(PIN_OUT_CHARGE_SENSOR, OUTPUT);
 
  pinMode(PIN_IN_CONTROL_FORWARD_BACKWARD, INPUT);
  pinMode(PIN_IN_CONTROL_LEFT_RIGHT, INPUT);
  pinMode(PIN_IN_CONTROL_UP_DOWN , INPUT);

  pinMode(PIN_OUT_CONTROL_ERROR, OUTPUT);
  pinMode(PIN_OUT_BUZZER, OUTPUT);
  pinMode(PIN_OUT_HEADLIGHT, OUTPUT);

  pinMode(PIN_CURRENT_SENSOR, INPUT);

  pinMode(PIN_SHUTDOWN, OUTPUT);
}

int contador = 0;
float baseTime;
long int risingForBackTime, risingLeftRightTime, risingUpDownTime;
int pulseForBack, pulseLeftRight, pulseUpDown;

bool controlStatus = false;


void risingForBack()
{
 	risingForBackTime = micros();
  attachInterrupt(digitalPinToInterrupt(PIN_IN_CONTROL_FORWARD_BACKWARD), fallingForBack, FALLING); 
}

void fallingForBack()
{
 	pulsoForBack = micros() - risingForBackTime;
  attachInterrupt(digitalPinToInterrupt(PIN_IN_CONTROL_FORWARD_BACKWARD), risingForBack, RISING); 
}

void risingLeftRight()
{
 	risingLeftRightTime = micros();
	attachInterrupt(digitalPinToInterrupt(PIN_IN_CONTROL_LEFT_RIGHT), fallingLeftRight, FALLING); 
}

void fallingLeftRight()
{
 	pulsoLeftRight= micros() - risingLeftRightTime;
  attachInterrupt(digitalPinToInterrupt(PIN_IN_CONTROL_LEFT_RIGHT), risingLeftRight, RISING); 
}

void risingUpDown()
{
 	risingUpDowntTime = micros();
	attachInterrupt(digitalPinToInterrupt(PIN_IN_CONTROL_UP_DOWN), fallingUpDown, FALLING); 
}

void fallingUpDown()
{
 	pulsoUpDown = micros() - risingUpDownTime;
  attachInterrupt(digitalPinToInterrupt(PIN_IN_CONTROL_UP_DOWN), risingUpDown, RISING); 
}

void moviment ()
{
  if (contador == 0 && risingForBackTime > 0)
    baseTime = risingForBackTime;
  else if (contador == 0 && risingLeftRightTime > 0)
    baseTime = risingLeftRightTime;
  else if (contador == 0 && risingLeftRightTime > 0)
    baseTime = risingUpDownTime;

}

void check_control ()
{
  while (controlStatus == false)
  {
	Serial.println(“controle desligado”);

	if (pulseUpDown > ??? || pulseLeftRight > ???)
  	controlStatus = true;
  }
}

void loop ()
{
 	attachInterrupt(digitalPinToInterrupt(PIN_IN_CONTROL_FORWARD_BACKWARD), risingForBack, RISING);
  attachInterrupt(digitalPinToInterrupt(PIN_IN_CONTROL_LEFT_RIGHT), risingLeftRight, RISING);
  attachInterrupt(digitalPinToInterrupt(PIN_IN_CONTROL_UP_DOWN), risingUpDown, RISING);
  contador++;
  
}


