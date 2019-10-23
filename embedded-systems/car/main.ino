#include <AFMotor.h>
#include <Servo.h>

#define TRIG_PIN 9
#define ECHO_PIN 10

#define DISTANCE_BASE_OBSTACLE 10
#define DISTANCE_BASE_NOT_OBSTACLE 50

#define RIGHT_MOTOR_PIN 1
#define LEFT_MOTOR_PIN 2

#define SERVO_PIN 10

AF_DCMotor motor1(RIGHT_MOTOR_PIN); 
AF_DCMotor motor2(LEFT_MOTOR_PIN); 

Servo servo;
unsigned LEFT = 0;
unsigned FRONTAL = 90;
unsigned RIGHT = 180;

void turnServo(const unsigned& target_angle){
    for(unsigned angle = 0; angle != target_angle; delay(10))
        servo.write(angle);
}

int getDistance(){ 
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);

    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    return pulseIn(ECHO_PIN, HIGH) * 0.034 * 0.5;
}

void goRight(){
    motor1.run(FORWARD); 
    motor2.run(BACKWARD); 
}

void goLeft(){
    motor2.run(FORWARD);
    motor1.run(FORWARD);
}

void goForward(){
    motor1.run(FORWARD); 
    motor2.run(FORWARD);
}

void stopAll(){
    motor1.run(RELEASE); 
    motor2.run(RELEASE);
}

void setup() {
    pinMode(TRIG_PIN, OUTPUT); 
    pinMode(ECHO_PIN, INPUT); 

    motor1.setSpeed(255); // Max speed for the right motor.
    motor2.setSpeed(255); // Max speed for the left  motor.

    unsigned servo_state = FRONTAL;
    servo.attach(SERVO_PIN);
}

void driveLogic(){
    static unsigned ultra_distance = getDistance();
    
      if(ultra_distance <= DISTANCE_BASE_OBSTACLE) {
      
      turnServo(RIGHT);
        if(ultra_distance >= DISTANCE_BASE_NOT_OBSTACLE){
            turnServo(FRONTAL);
            goRight();
            goForward();  
        }
        
     turnServo(LEFT);
      if(ultra_distance >= DISTANCE_BASE_NOT_OBSTACLE){
            turnServo(FRONTAL);
           goLeft();
            goForward();
            }
     }

  goLeft();
}

void loop() {
    driveLogic();
}
