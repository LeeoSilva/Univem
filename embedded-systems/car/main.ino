#include <AFMotor.h>

#define TRIG_PIN 9
#define ECHO_PIN 10

#define RIGHT_MOTOR_PIN 1
#define LEFT_MOTOR_PIN 2

AF_DCMotor motor1(RIGHT_MOTOR_PIN); 
AF_DCMotor motor2(LEFT_MOTOR_PIN); 

int getDistance(){
	long duration;
	int distance;

	digitalWrite(TRIG_PIN, LOW);
	delayMicroseconds(2);
	digitalWrite(TRIG_PIN, HIGH);

	delayMicroseconds(10);
	digitalWrite(TRIG_PIN, LOW);

	duration = pulseIn(ECHO_PIN, HIGH);
	distance = duration * 0.034 * 0.5;
	return distance;
}

void goRight(){
	motor1.run(FORWARD); 
	motor2.run(BACKWARD); 
}

void goLeft(){
	motor2.run(FORWARD);
	motor1.run(BACKWARD);
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
}

void loop() {




}
