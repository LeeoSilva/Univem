#include <Servo.h>
#include <AFMotor.h>

AF_DCMotor motor1(2);
AF_DCMotor motor2(1);  

int Trig = A0; 
int Echo = A1; 

long time;
long ToObstacle; 

int distReal =  50; 
int Distancia1 =  0; 
int Distancia2 =  0; 

Servo SERVO;

void Accel()  {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void Back() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  delay(300);
  motor2.run(BACKWARD);
  motor1.run(BACKWARD);
}

void turnLeft() {
  motor2.run(FORWARD);
  motor1.run(BACKWARD);
}

void turnRight()   {
  motor2.run(BACKWARD);
  motor1.run(FORWARD);
}

void STOP()   {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

int ServoRead() {
  digitalWrite(Trig,LOW);
  delay(4);

  digitalWrite(Trig,HIGH); 
  delay(10);

  digitalWrite(Trig,LOW);
  time = pulseIn(Echo,HIGH);
  ToObstacle = time / 58; 
  return ToObstacle;
}

int Process() {
  int D =0;
  int SOMA = 0;
  for (int i = 0; i < 5; i++)
    {
       D =  ServoRead();
      SOMA += D;
    }
  return SOMA / 5;
}

void setup() {
  SERVO.attach(10);

  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);

  motor1.setSpeed(100);
  motor2.setSpeed(100);

  Serial.begin(9600); 
}

void loop() {
  byte relativePos = map(relativePos, 0, 1023, 0, 180); 
  relativePos = 90; 
  SERVO.write(relativePos);
  delay(250);

  Accel();

  distReal = Process(); 
  if (distReal < 25){
    STOP();
    relativePos = 0;
    SERVO.write(relativePos);
    delay(500);
    Distancia1 = Process();


    relativePos = 179;
    SERVO.write(relativePos);
    Distancia2 = Process();

    if ((Distancia1 >=  distReal) or (Distancia2 >=  distReal)){
      if (Distancia1 > Distancia2){
        relativePos = 0;
        SERVO.write(relativePos);
        delay(500);
        Back();
        turnLeft();
        delay(500);
      }
      
      else{
        relativePos = 180;
        SERVO.write(relativePos);
        delay(500);
        Back();
        turnRight();
        delay(500);
      }
    }
    
    else {
      relativePos = 0;
      SERVO.write(relativePos);
      delay(500);
      Back();
      delay(250);
    }
  }
}

