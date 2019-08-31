int statusbotao = 0;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2,INPUT);
}

void Green(const unsigned& port){
  digitalWrite(port, HIGH);
  delay(3000);
  digitalWrite(port, LOW);
}

void OnRed(const unsigned& port){
  digitalWrite(port, HIGH);
 
}

void OffRed(const unsigned& port){
 digitalWrite(port, LOW);
}


void Yellow(const unsigned& port){
  digitalWrite(port, HIGH);
  delay(1000);
  digitalWrite(port, LOW);
}

void Pedestre(){
  OnRed(13);
    OnRed(10);
    OffRed(3);
    Green(4);
    OffRed(10);
    OffRed(13);
    OnRed(3);
}
  
void estado1 (){
  OnRed(13);
  Green(8);
  Yellow(9);
  delay(100);
  OffRed(13);
}

void estado2 (){
  OnRed(10);
  Green(11);
  Yellow(12);
  delay(100);
  OffRed(10);
}

void loop()
{
  OnRed(3);
  estado1();
  statusbotao = digitalRead(2);
  
  if(statusbotao == HIGH){
      Pedestre();
  }
  
  estado2();
  statusbotao = digitalRead(2);
  
  if(statusbotao == HIGH){
      Pedestre();
    } 
}
