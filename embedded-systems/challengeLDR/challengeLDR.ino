/* 
	Leonardo Silva   - 591149 
	Marvin Burgareli - 591815
	Aron Vinícius    - 589977
	João Guilherme   - 588456

	Criar um circuito para que um sensor LDR ao
	detectar luz forneça um feedback luminoso da
	quantidade de luz detectada através de 3 LEDS,
	sendo eles:
	
	1 verde   -> grande quantidade de luz;
	1 amarelo -> para valores intermediários;
	1 vermelho -> para pouca luz

*/


const unsigned int PIN_LDR = A0;
const unsigned char PIN_GREEN = 12,
	  PIN_YELLOW = 11,
	  PIN_RED= 10;

void ledOn(const unsigned char pin ){
	digitalWrite(pin, HIGH);
	delay(250);
	digitalWrite(pin, LOW);
}


void setup(){
	Serial.begin(9600);
	pinMode(PIN_GREEN, OUTPUT);	
	pinMode(PIN_YELLOW, OUTPUT);	
	pinMode(PIN_RED, OUTPUT);	
}

void loop(){
	int valueLDR = analogRead(PIN_LDR);	
	bool HIGH_LIGHT = valueLDR >= 350,
		INTER_LIGHT = valueLDR > 150 && valueLDR < 350,
		LOW_LIGHT = valueLDR <= 150;


	Serial.println(valueLDR);
	if (HIGH_LIGHT)
		ledOn(PIN_GREEN);
	else if(INTER_LIGHT) 
		ledOn(PIN_YELLOW);
	else if(LOW_LIGHT) 
		ledOn(PIN_RED);
	delay(250);
}
