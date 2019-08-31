enum class States : unsigned char {
  VERMELHO_VERDE = 0, // estado inicial
  VERMELHO_AMARELO,
  VERDE_VERMELHO,
  AMARELO_VERMELHO
};

const unsigned char verdeA = 13;
const unsigned char vermelhoA = 12;
const unsigned char amareloA = 11;

const unsigned char verdeB = 10;
const unsigned char vermelhoB = 9;
const unsigned char amareloB = 8;


class manageStates {
    
    
    States states;
    
    public:
    manageStates() {
      this->states = States::VERMELHO_VERDE; // inicial state
    }

    void state1() {
      // VERMELHO_VERDE
      digitalWrite(vermelhoA, HIGH);
      digitalWrite(verdeB, HIGH);

      delay(3000);

      digitalWrite(vermelhoA, LOW);
      digitalWrite(verdeB, LOW);

      this->states = States::VERMELHO_AMARELO; // next stage
    }

    void state2() {
      // VERMELHO_AMARELO
      digitalWrite(vermelhoA, HIGH);
      digitalWrite(verdeB, HIGH);
      delay(3000);
      digitalWrite(vermelhoA, LOW);
      digitalWrite(verdeB, LOW);
      this->states = States::VERDE_VERMELHO; // next stage
    }

    void state3() {
      // VERDE_VERMELHO
      digitalWrite(vermelhoA, HIGH);
      digitalWrite(verdeB, HIGH);
      delay(3000);
      digitalWrite(vermelhoA, LOW);
      digitalWrite(verdeB, LOW);
      this->states = States::AMARELO_VERMELHO;
    }

    void state4() {
      // AMARELO_VERMELHO
      digitalWrite(vermelhoA, HIGH);
      digitalWrite(verdeB, HIGH);
      delay(3000);
      digitalWrite(vermelhoA, LOW);
      digitalWrite(verdeB, LOW);
      this->states = States::VERMELHO_VERDE;
    }
};


void setup() {
}

void loop() {
  manageStates states;
  states.state1();
}
