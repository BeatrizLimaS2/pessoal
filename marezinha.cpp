#include <Arduino.h>

#define PIN_OUT_PWM_MOTOR_RIGHT 0
#define PIN_OUT_PWM_MOTOR_LEFT 0

#define PIN_OUT_CHARGE_SENSOR 0

#define PIN_IN_CONTROL_FORWARD_BACKWARD 0
#define PIN_IN_CONTROL_LEFT_RIGHT 0

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

  pinMode(PIN_OUT_CONTROL_ERROR, OUTPUT);
  pinMode(PIN_OUT_BUZZER, OUTPUT);
  pinMode(PIN_OUT_HEADLIGHT, OUTPUT);

  pinMode(PIN_CURRENT_SENSOR, INPUT);

  pinMode(PIN_SHUTDOWN, OUTPUT);

	 attachInterrupt(digitalPinToInterrupt(PIN_IN_CONTROL_FORWARD_BACKWARD), risingForBack, RISING);
	 attachInterrupt(digitalPinToInterrupt(PIN_IN_CONTROL_LEFT_RIGHT), risingLeftRight, RISING);

 digitalWrite(PIN_CURRENT_SENSOR, HIGH);
}

int contador = -1;
int direcao;
long int risingForBackTime, risingLeftRightTime, baseTime;
int pulseForBack, pulseLeftRight, pulsoForBackTime, pulsoLeftRightTime;

bool controlStatus = false;


void risingForBack()
{
  contador++;
  risingForBackTime = micros();
  attachInterrupt(digitalPinToInterrupt(PIN_IN_CONTROL_FORWARD_BACKWARD), fallingForBack, FALLING);
}

void fallingForBack()
{
	pulseForBack = micros() - risingForBackTime;
  attachInterrupt(digitalPinToInterrupt(PIN_IN_CONTROL_FORWARD_BACKWARD), risingForBack, RISING);
}

void risingLeftRight()
{
  contador++;
  risingLeftRightTime = micros();
  attachInterrupt(digitalPinToInterrupt(PIN_IN_CONTROL_LEFT_RIGHT), fallingLeftRight, FALLING);
}

void fallingLeftRight()
{
  pulseLeftRight= micros() - risingLeftRightTime;
  attachInterrupt(digitalPinToInterrupt(PIN_IN_CONTROL_LEFT_RIGHT), risingLeftRight, RISING);
}

void moviment ()
{
  int pulsoBase;
  long y;
  long x;
  long zero;

  if (contador == 0 && pulsoForBackTime > 0)
    pulsoBase = pulsoForBackTime;
  else if (contador == 0 && pulseLeftRight > 0)
    pulsoBase = pulsoLeftRightTime;

    zero = map(pulsoBase, 1000, 2000, -100, 100);
    y= map(pulseForBack, 1000, 2000, -100, 100);
    x= map(pulseLeftRight, 1000, 2000, -100, 100);
    
    if (y < zero) // andando pra tras

    else // andando pra frente

    if (x < zero) //indo para a esquerda
   	 
    else //indo para a direita
   	 
}

void current_read()
{
    while true
    {
   	 valor = analogRead((pin_sensor)
        		 if (valor >3.0){
         			 digitalWrite(PIN_CURRENT_SENSOR, LOW);}
    	}
}

void check_control ()
{
  while (controlStatus == false)
  {
    if (pulseForBack > ??? || pulseLeftRight > ???)
     	 controlStatus = true;
  }
}

void loop ()
{
    check_control();
    current_read();
    moviment();

}


