unsigned char led1 = 13;

void setup() {
  pinMode(13, OUTPUT);
}

void blinkLedFast(const unsigned char& port){
  digitalWrite(port, HIGH);
  delay(750);
  digitalWrite(port, LOW);  
  delay(100);
}

void blinkLedLong(const unsigned char& port){
  digitalWrite(port, HIGH);
  delay(2000);
  digitalWrite(port, LOW);  
  delay(100);
}


void loop() {
  blinkLedFast(led1);
  blinkLedFast(led1);
  blinkLedFast(led1);
  blinkLedLong(led1);
  blinkLedLong(led1);
  blinkLedLong(led1);
  blinkLedFast(led1);
  blinkLedFast(led1);
  blinkLedFast(led1);
  delay(3000);
  
}
