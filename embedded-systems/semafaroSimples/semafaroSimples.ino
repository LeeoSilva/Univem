const unsigned char verde = 13;
const unsigned char amarelo = 11;
const unsigned char vermelho = 12;


void setup() {
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
}

void toggleLed(const unsigned char port, bool state){
  if( state == false) digitalWrite(port, LOW);   
  else digitalWrite(port, HIGH);
}

void loop() {
  toggleLed(vermelho, 1);
  delay(3000);
  toggleLed(vermelho, 0);

  delay(200);
  
  toggleLed(verde, 1);
  delay(2000);
  toggleLed(verde, 0);

  delay(200);
  
  toggleLed(amarelo, 1);
  delay(1000);
  toggleLed(amarelo, 0);

  delay(3000);
  
}
