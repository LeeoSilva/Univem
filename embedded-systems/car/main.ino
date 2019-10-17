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


unsigned turnServo(){ // return value is the angle of the servo
	static unsigned pos = 0;
	unsigned next_pos = 0;
	bool dir = 0; // 0 -> RIGHT
				  // 1 -> LEFT  

	if(pos == 0){
		next_pos = 90;	
		dir = 0;
	}
	else if(pos == 90 && dir == 0) next_pos = 180;
	else if(pos == 90 && dir == 1) next_pos = 0;
	else if(pos == 180) {
		next_pos = 90;
		dir = 1;
	}
	else{
		next_pos = 0;
		dir = 0;
	}

	for(; pos != next_pos; delay(10)){
		servo.write(pos);
		pos = dir ? (--pos) : (++pos);
	}
	return pos;
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

	servo.attach(SERVO_PIN);
}

void driveLogic(){
	static unsigned ultra_distance = getDistace();

	if(ultra_distance <= 10


}

void loop() {
	driveLogic();
}
