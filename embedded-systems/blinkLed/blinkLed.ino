unsigned char led1 = 13;

void setup() {
  pinMode(13, OUTPUT);
}

void blinkLed(const unsigned char& port){
  digitalWrite(port, HIGH);
  delay(1000);
  digitalWrite(port, LOW);  
  delay(1000);
}

void loop() {
  blinkLed(led1);
}
