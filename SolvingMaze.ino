#include <Servo.h>
Servo servo1;

int pinservo = 2;
int pulsomin = 900;
int pulsomax = 2704;

int trig = A0;
int echo = A2;

int detener = 0;

int stopp();
int atras();
int adelante();
int giroizq();
int girode();

int medirdistancia();
int duracion;
int distancia;
int distanciaizq;
int distanciade;
int lookR();
int lookL();

const int mia = 3;
const int mib = 5;
const int mda = 6;
const int mdb = 11;

void setup()
{
  pinMode(mia, OUTPUT);
  pinMode(mib, OUTPUT);
  pinMode(mda, OUTPUT);
  pinMode(mdb, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, OUTPUT);
  Serial.begin(9600);

  servo1.attach(pinservo, pulsomin, pulsomax);
  Serial.begin(9600);
}

void loop()
{
  distancia=medirdistancia();
  Serial.println(distanciade); 
  if (distancia <= 20)
  {
    stopp();
    delay(1000);
    distanciade=lookR();
    delay(50);
    distanciaizq=lookL();
    delay(50);

    if (distanciaizq < distanciade)
    {
      stopp();
      delay(100);
      izquierda();
      delay(240);
      stopp();
      delay(500);
    }
    else if (distanciade < distanciaizq)
    {
      stopp();
      delay(100);
      derecha();
      delay(240);
      stopp();
      delay(500);
    }
    
  }
  else 
  adelante();
}


          // acciones 
          
int medirdistancia()
{
  int distancia = 0;
  int duracion = 0;
  digitalWrite(trig, HIGH);
  delay(5);
  digitalWrite(trig, LOW);
  duracion = pulseIn (echo, HIGH);
  distancia = duracion/58.2;
  delay(200);
  return distancia;
}

int derecha()
{
  analogWrite(mia, detener);
  analogWrite(mib, 200);
  analogWrite(mda, detener);
  analogWrite(mdb, 200);
}

int izquierda()
{
  analogWrite(mia, 200);
  analogWrite(mib, detener);
  analogWrite(mda, 200);
  analogWrite(mdb, detener);
}
int adelante()
{
  analogWrite(mia, 205);
  analogWrite(mib, detener);
  analogWrite(mda, detener);
  analogWrite(mdb, 205);
}
int atras()
{
  analogWrite(mia, detener);
  analogWrite(mib, 100);
  analogWrite(mda, 100);
  analogWrite(mdb, detener);
}
int stopp()
{
  analogWrite(mia,detener);
  analogWrite(mib,detener);
  analogWrite(mda,detener);
  analogWrite(mdb,detener);
}

int lookR()
{
  servo1.write(85);
  delay(500);
  distanciade = medirdistancia();
  delay(100);
  servo1.write(90);
  return distanciade;
}

int lookL()
{
  servo1.write(95);
  delay(500);
  distanciaizq = medirdistancia();
  delay(100);
  servo1.write(90);
  return distanciade;
}
