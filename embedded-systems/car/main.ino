#include <AFMotor.h>
#include <Servo.h>

#define TRIG_PIN 9
#define ECHO_PIN 10

#define RIGHT_MOTOR_PIN 1
#define LEFT_MOTOR_PIN 2

#define SERVO_PIN 9

AF_DCMotor motor1(RIGHT_MOTOR_PIN); 
AF_DCMotor motor2(LEFT_MOTOR_PIN); 

Servo servo;

enum class servo_angle {
	RIGHT = 0,
	FRONTAL = 90,
	LEFT = 180
};


void turnServo(const servo_angle& target_angle){
	for(unsigned angle = 0; angle != target_angle; delay(10))
		servo.write(angle);
}

int getDistance(){ 
	long duration;

	digitalWrite(TRIG_PIN, LOW);
	delayMicroseconds(2);
	digitalWrite(TRIG_PIN, HIGH);

	delayMicroseconds(10);
	digitalWrite(TRIG_PIN, LOW);

	duration = pulseIn(ECHO_PIN, HIGH);
	return duration * 0.034 * 0.5;
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

	servo_angle servo_state = servo_angle.RIGHT;
	servo.attach(SERVO_PIN);
}

void driveLogic(){
	static unsigned ultra_distance = getDistace();
	if(ultra_distance <= 10 


}

void loop() {
	driveLogic();
}
